#ifndef BRAINFUCK_H
# define BRAINFUCK_H
# include "libft.h"
# include <fcntl.h>
# include <stdbool.h>

typedef enum
{
	NONE,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE
}t_color;

typedef	enum
{
	OK,
	ERROR,
	USAGE
}t_parse_return;

typedef	struct
{
	t_color	color;
	bool	d;
	size_t	length;
	int		fd;
}t_args;

void	debug_usage(t_color color);
int		debug(char *map, size_t ind, t_args args, char *str, size_t s_i);
void	colored(char *str, t_color color);
t_args	get_args(int ac, char **av);
int		brainfuck(char *ptr, t_args args, char *buf);

#endif
