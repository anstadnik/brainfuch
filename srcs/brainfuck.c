#include "brainfuck.h"

static void	operation(char	*ptr, size_t *ind, char c, t_args args)
{
	char	buf[2];

	switch (c)
	{
		case '+':
			ptr[*ind]++;//increment the value
			break;
		case '-':
			ptr[*ind]--;//decrement the value
			break;		
		case '>':
			(*ind)++;//increment the pointer
			break;		
		case '<':
			(*ind)--;//decrememt the pointer
			break;		
		case '.':
			buf[0] = '\0';
			buf[1] = ptr[*ind];
			colored(buf, args.color);
			break;		
		case ',':
			read(0, ptr + *ind, 1);//read from input and write to value
			break;		
	}
}

static void	usage(t_color color)
{
	colored("Brainfuck debugger\n", color);
	colored("\n", color);
	colored("Commands:\n", color);
	colored("  h - show this message\n", color);
	colored("  s num - skip num steps\n", color);
	colored("  p - print whole string\n", color);
	colored("  n - step\n", color);
	colored("\n", color);
}

void	print(char *ptr, size_t ind, t_args args)
{
	size_t	beg;
	size_t	end;
	char	buf[5];

	if (ind < 10)
	{
		beg = 0;
		end = args.length > 20 ? 20: args.length;
	}
	else if (args.length - ind < 10)
	{
		beg = (ssize_t)(20 - args.length + ind + 1) >= 0 ? 20 - args.length + ind + 1 : 0;
		end = args.length - 1;
	}
	else
	{
		beg = ind - 10;
		end = ind + 10;
	}
	ft_printf("%zd %zd \n", beg, end);
	buf[3] = ' ';
	buf[4] = '\0';
	for (size_t i = beg; i < end; i++)
	{
		buf[0] = ptr[i] / 100 + '0';
		buf[1] = (ptr[i] % 100) / 10 + '0';
		buf[2] = (ptr[i] % 10) + '0';
		colored(buf, i == ind ? WHITE : args.color);
	}
	ft_printf("\n");
}

void	debug(char *ptr, size_t ind, t_args args)
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
				usage(GREEN);
			else if (ft_strequ(buf, "s"))
			{
				if (get_next_line(0, &buf) != 1 || ft_isinteger(buf))
					ft_printf("{red}Error{eoc}\n");
				else
					skip = ft_atoi(buf);
			}
			else if (ft_strequ(buf, "p"))
				print(ptr, ind, args);
			else if (ft_strequ(buf, "n"))
				break;
			else
				ft_printf("\n");
		}
		ft_printf("{eoc}");
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
			ft_printf("{red}Index out of range, error{eoc}\n");
			break;
		case(3):
			ft_printf("{red}Source file unavaiable, error{eoc}\n");
			break;
	}
	exit(1);
}

void	brainfuck(char *ptr, t_args args, char *buf)
{
	int		ret;
	size_t	ind = 0;
	size_t	i = 0;

	if (args.d)
		usage(GREEN);
	while (buf[i] && ind < args.length)
	{
		if (args.d)
			debug(ptr, ind, args);
		if ((!ptr[ind] && buf[i] == '[') || (ptr[ind] && buf[i] == ']'))
		{
			int depth = buf[i] == '[' ? 1 : -1;
			while (depth && ind < args.length)
			{
				// check if i is less than zero
				i += depth > 0 ? 1 : -1;
				depth += buf[i] == '[' ? 1 : buf[i] == ']' ? -1 : 0;
			}
		}
		else 
			operation(ptr, &ind, buf[i], args);
		i++;
	}
	if (ind >= args.length)
		error(2);
	if (ret == -1)
		error(3);
}
