#include "head.h"

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

void	brainfuck(char *ptr, char *str)
{
	int	i = 0;
	while (str[i])
	{
		if ((!(*ptr) && str[i] == '[') || (*ptr && str[i] == ']'))
		{
			int depth = str[i] == '[' ? 1 : -1;
			while (depth)
			 {
				i += depth > 0 ? 1 : -1;
				depth += str[i] == '[' ? 1 : str[i] == ']' ? -1 : 0;
			 }
		}
		else 
			operation(&ptr, str[i]);
		i++;
	}
}
