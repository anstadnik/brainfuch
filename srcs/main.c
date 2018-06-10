/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:02:27 by astadnik          #+#    #+#             */
/*   Updated: 2018/06/10 23:59:53 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

void	show_args(t_args args)
{
	ft_printf("{magenta}Color - %d\n", args.color);
	ft_printf("{magenta}Debug - %d\n", args.d);
	ft_printf("{magenta}Length - %d\n", args.length);
	ft_printf("{magenta}Fd - %d\n", args.fd);
}

int		main(int ac, char **av)
{
	char	*field;
	t_args	args;
	char	*command;
	char	*buf;
	char	*tmp;

	args = get_args(--ac, ++av);
	/* show_args(args); */
	field = ft_memalloc((size_t)args.length + 1);
	while (get_next_line(args.fd, &buf) == 1)
	{
		tmp = ft_strjoin(command, buf);
		free(command);
		command = tmp;
		free(buf);
	}
	close(args.fd);
	brainfuck(field, args);
	return (0);
}
