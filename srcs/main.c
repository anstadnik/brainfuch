/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:02:27 by astadnik          #+#    #+#             */
/*   Updated: 2018/06/11 23:27:05 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

void	show_args(t_args args)
{
	ft_printf("{magenta}Color - %d\n{eoc}", args.color);
	ft_printf("{magenta}Debug - %d\n{eoc}", args.d);
	ft_printf("{magenta}Length - %d\n{eoc}", args.length);
	ft_printf("{magenta}Fd - %d\n{eoc}", args.fd);
}

int		main(int ac, char **av)
{
	char	*map;
	t_args	args;
	char	*command = "";
	char	*buf;
	char	*tmp;

	args = get_args(--ac, ++av);
	/* show_args(args); */
	map = ft_memalloc((size_t)args.length + 1);
	if (args.fd)
	while (get_next_line(args.fd, &buf) == 1)
	{
		tmp = ft_strjoin(command, buf);
		if (!command && !*command)
			free(command);
		command = tmp;
		free(buf);
	}
	close(args.fd);
	if (!command)
	{
		ft_printf("{red}Empty file, error{eoc}\n");
		return (1);
	}
	while (brainfuck(map, args, command))
		;
	return (0);
}
