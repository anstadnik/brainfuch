/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:02:23 by astadnik          #+#    #+#             */
/*   Updated: 2018/06/18 11:00:26 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

void	colored(char *str, t_color color)
{
	switch (color)
	{
		case (RED):
			ft_printf("{red}");
			break;
		case (GREEN):
			ft_printf("{green}");
			break;
		case (YELLOW):
			ft_printf("{yellow}");
			break;
		case (BLUE):
			ft_printf("{blue}");
			break;
		case (MAGENTA):
			ft_printf("{magenta}");
			break;
		case (CYAN):
			ft_printf("{cyan}");
			break;
		case (WHITE):
			ft_printf("{white}");
			break;
		default: ;
	}
	ft_printf("%s", str);
	ft_printf("{eoc}");
}

static void	usage(t_color color)
{
	colored("Usage: ./brainfuck [-h] [-c color] [-d] [-l LENGTH] -f FILE\n", color);
	colored("Executes brainfuck code\n", color);
	colored("\n", color);
	colored("Options:\n", color);
	colored("  -h - show this message\n", color);
	colored("  -c - specify color\n", color);
	colored("  -d - debug mode\n", color);
	colored("  -l - specify length of string\n", color);
	colored("  FILE - specify file\n", color);
	colored("\n", color);
}

static int		get_color(char *str, t_color *color)
{
	if (ft_strequ(str, "red"))
		*color = RED;
	else if (ft_strequ(str, "green"))
		*color = GREEN;
	else if (ft_strequ(str, "yellow"))
		*color = YELLOW;
	else if (ft_strequ(str, "blue"))
		*color = BLUE;
	else if (ft_strequ(str, "magenta"))
		*color = MAGENTA;
	else if (ft_strequ(str, "cyan"))
		*color = CYAN;
	else
		return (1);
	return (0);
}

static t_parse_return 	parse_args(int ac, char **av, t_args *as)
{
	while (ac--)
	{
		if (!av)
			return (ERROR);
		else if (ft_strequ(*av, "-h"))
			return (USAGE);
		else if (ft_strequ(*av, "-c"))
		{
			if (++av && get_color(*av++, &as->color))
				return (ERROR);
			ac--;
		}
		else if (ft_strequ(*av, "-d") && av++)
			as->d = true;
		else if (ft_strequ(*av, "-l"))
		{
			if (++av && !ft_isinteger(*av))
				as->length = (size_t)ft_atoi(*av++);
			else
				return (ERROR);
			ac--;
		}
		else if (ft_strequ(*av, "-f"))
		{
			if (!++av || !~(as->fd = open(*av, O_RDONLY)) || !~read(as->fd, NULL, 0))
				return (ERROR);
			av++;
			ac--;
		}
		else
			return (ERROR);
	}
	return (OK);
}

t_args	get_args(int ac, char **av)
{
	t_args	args;

	ft_bzero(&args, sizeof(t_args));
	args.length = 2048;
	switch (parse_args(ac, av, &args))
	{
		case (OK):
			break;
		case (ERROR): 
			usage(RED);
			exit(1);
			break;
		case (USAGE):
			usage(GREEN);
			exit(0);
	}
	if (!args.fd)
	{
		usage(RED);
		exit(1);
	}
	return (args);
}
