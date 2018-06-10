#include "brainfuck.h"

void	operation(char	**ptr, char c)
{
	switch (c)
	{
		case '+':
			(**ptr)++;//increment the value
			break;
		case '-':
			(**ptr)--;//decrement the value
			break;		
		case '>':
			(*ptr)++;//increment the pointer
			break;		
		case '<':
			(*ptr)--;//decrememt the pointer
			break;		
		case '.':
			write(1, *ptr, 1);//print the value
			break;		
		case ',':
			read(0, *ptr, 1);//read from input and write to value
			break;		
	}
}

void	brainfuck(char *ptr, int fd)
{
	char	*buf;

	while (get_next_line(fd, &buf))
	{
		int	i = 0;
		while (buf[i])
		{
			if ((!(*ptr) && buf[i] == '[') || (*ptr && buf[i] == ']'))
			{
				int depth = buf[i] == '[' ? 1 : -1;
				while (depth)
				{
					i += depth > 0 ? 1 : -1;
					depth += buf[i] == '[' ? 1 : buf[i] == ']' ? -1 : 0;
				}
			}
			else 
				operation(&ptr, buf[i]);
			i++;
		}
	}
}
