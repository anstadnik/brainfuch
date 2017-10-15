#include "head.h"

int	main(int argc, char **argv)
{
	if (argc == 2 || argc == 1)
	{
		//char *arr = argc == 1 ? malloc(2048) : malloc(ft_atoi(argv[1]));
		char *arr = malloc(2048);
		for (int i = 0; i < 2048; i++)
			arr[i] = 0;
		char *ch = ft_getstr(argc == 1 ? NULL : argv[1]);
		ft_putstr(ch);
		brainfuck(arr, ch);
		free(arr);
	}
	else
		ft_putstr("U should give one or two arguments\n");
	return (0);
}
