#ifndef HEAD_H
# define HEAD_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	brainfuck(char *line, char *str);
char	*ft_getstr(char *path);
int	ft_atoi(char *str);

#endif
