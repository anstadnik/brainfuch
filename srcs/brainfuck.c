/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:31:38 by astadnik          #+#    #+#             */
/*   Updated: 2018/06/11 21:20:34 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

static void	operation(char	*map, ssize_t *ind, char c, t_args args)
{
	char	buf[2];

	switch (c)
	{
		case '+':
			map[*ind]++;//increment the value
			break;
		case '-':
			map[*ind]--;//decrement the value
			break;		
		case '>':
			(*ind)++;//increment the pointer
			break;		
		case '<':
			(*ind)--;//decrememt the pointer
			break;		
		case '.':
			buf[1] = '\0';
			buf[0] = map[*ind];
			colored(buf, args.color);
			break;		
		case ',':
			read(0, map + *ind, 1);//read from input and write to value
			break;		
	}
}

void	error(int code)
{
	switch (code)
	{
		case(1):
			ft_printf("{red}Unclosed square brackets, error{eoc}\n");
			break;
		case(2):
			ft_printf("{red}Carriage is out of range, error{eoc}\n");
			break;
	}
	exit(1);
}

int		brainfuck(char *map, t_args args, char *str)
{
	ssize_t	p_i = 0;
	int		s_i = 0;

	if (args.d)
		debug_usage(GREEN);
	while (str[s_i] && (size_t)p_i < args.length && p_i >= 0)
	{
		if (args.d)
			if (debug(map, (size_t)p_i, args, str, (size_t)s_i))
				return (1);
		if ((!map[p_i] && str[s_i] == '[') || (map[p_i] && str[s_i] == ']'))
		{
			int depth = str[s_i] == '[' ? 1 : -1;
			while (depth && (size_t)p_i < args.length)
			{
				s_i += depth > 0 ? 1 : -1;
				if (s_i < 0 || !str[s_i])
				{
					if (args.d)
					{
						ft_printf("{red}Unclosed square brackets, error{eoc}\n");
						if (debug(map, (size_t)p_i, args, str, (size_t)s_i))
							return (1);
					}
					error(1);
				}
				depth += str[s_i] == '[' ? 1 : str[s_i] == ']' ? -1 : 0;
			}
		}
		else 
			operation(map, &p_i, str[s_i], args);
		s_i++;
	}
	if (args.d)
	{
		if ((size_t)p_i >= args.length || p_i < 0)
			ft_printf("{red}Carriage is out of range, error{eoc}\n");
		else
			ft_printf("{green}Program finished succesfully{eoc}\n");
		if (debug(map, (size_t)p_i, args, str, (size_t)s_i))
			return (1);
	}
	if (((size_t)p_i >= args.length || p_i < 0) && !args.d)
		error(2);
	return (0);
}
