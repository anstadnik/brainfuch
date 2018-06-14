/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:29:34 by astadnik          #+#    #+#             */
/*   Updated: 2018/06/13 11:42:16 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

static void	print_map(char *map, size_t p_i, t_args args)
{
	size_t	beg;
	size_t	end;
	char	buf[5];

	if (p_i < 10)
	{
		beg = 0;
		end = args.length > 20 ? 20: args.length;
	}
	else if (args.length - p_i < 10)
	{
		beg = (ssize_t)(20 - args.length + p_i + 1) >= 0 ? 20 - args.length + p_i + 1 : 0;
		end = args.length - 1;
	}
	else
	{
		beg = p_i - 10;
		end = p_i + 10;
	}
	buf[3] = ' ';
	buf[4] = '\0';
	for (size_t i = beg; i < end; i++)
	{
		buf[0] = map[i] / 100 + '0';
		buf[1] = (map[i] % 100) / 10 + '0';
		buf[2] = (map[i] % 10) + '0';
		if (i == args.length)
			colored(buf, RED);
		else
			colored(buf, i == p_i ? WHITE : GREEN);
	}
	ft_printf("\n");

}

static void	print_str(char *str, size_t s_i)
{
	size_t	beg;
	size_t	end;
	char	buf[2];
	size_t	length;

	length = ft_strlen(str);
	if (s_i < 10)
	{
		beg = 0;
		end = length > 20 ? 20: length;
	}
	else if (length - s_i < 10)
	{
		beg = (ssize_t)(20 - length + s_i + 1) >= 0 ? 20 - length + s_i + 1 : 0;
		end = length - 1;
	}
	else
	{
		beg = s_i - 10;
		end = s_i + 10;
	}
	buf[1] = '\0';
	for (size_t i = beg; i < end; i++)
	{
		buf[0] = str[i];
		colored(buf, i == s_i ? WHITE : GREEN);
	}
	ft_printf("\n");
}

void	print(char *map, size_t p_i, t_args args, char *str, size_t s_i)
{
	print_map(map, p_i, args);
	print_str(str, s_i);
}

void	debug_usage(t_color color)
{
	colored("Brainfuck debugger\n", color);
	colored("\n", color);
	colored("Commands:\n", color);
	colored("  h - show this message\n", color);
	colored("  s - skip num steps(insert steps' amount after enter)\n", color);
	colored("  p - print whole string\n", color);
	colored("  r - restart program\n", color);
	colored("  n - step\n", color);
	colored("  q - quit\n", color);
	colored("\n", color);
}

int		prompt(void)
{
	char	*buf;
	int		ret = -1;

	while (ret == -1)
	{
		ft_printf("{magenta}Are you sure? (y/n)\n");
		if (get_next_line(0, &buf) != 1)
			ft_printf("{red}Error{eoc}\n");
		else if (ft_strequ(buf, "y"))
			ret = 1;
		else if (ft_strequ(buf, "n"))
			ret = 0;
		else
			ft_printf("{red}Wrong option. Please type 'y' or 'n'{eoc}\n");
		free(buf);
	}
	return (ret);
}

int		debug(char *map, size_t ind, t_args args, char *str, size_t s_i)
{
	char	*buf;
	static int	skip = 0;

	if (skip)
		skip--;
	else
	{
		while (ft_printf("{magenta}> ") && get_next_line(0, &buf) == 1)
		{
			if (ft_strequ(buf, "h"))
				debug_usage(GREEN);
			else if (ft_strequ(buf, "s"))
			{
				if (get_next_line(0, &buf) != 1 || ft_isinteger(buf))
					ft_printf("{red}Error{eoc}\n");
				else
					skip = ft_atoi(buf);
				free(buf);
				if (skip)
					break ;
			}
			else if (ft_strequ(buf, "p"))
				print(map, ind, args, str, s_i);
			else if (ft_strequ(buf, "n"))
				break;
			else if (ft_strequ(buf, "q"))
			{
				if (prompt())
					exit(0);
			}
			else if (ft_strequ(buf, "r"))
			{
				if (prompt())
					return (1);
			}
			else
				ft_printf("\n");
		}
		ft_printf("{eoc}");
	}
	return (0);
}
