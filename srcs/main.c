/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:02:27 by astadnik          #+#    #+#             */
/*   Updated: 2018/06/10 22:49:37 by astadnik         ###   ########.fr       */
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

	args = get_args(--ac, ++av);
	show_args(args);
	field = ft_memalloc((size_t)args.length);
	/* ft_bzero(field, len); */
	/* brainfuck(field, fd); */
	return (0);
}
