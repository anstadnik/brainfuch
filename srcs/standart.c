#include "head.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}


void	*ft_realloc(void *data, int size);
char	*ft_strncat(char *str1, char *str2, int size);

char	*ft_getstr(char *path)
{
	int	fd = path ? open(path, O_RDONLY) : 0;
	fd = fd < 0 ? 0 : fd;
	int	cursize = 1;
	int	size = 32;
	char	*rez = malloc(1);
	rez[0] = '\0';
	char	*buf = NULL;
	int	temp;
	while (42)
	{
		rez = ft_realloc(rez, cursize + size);
		buf = malloc((size_t)size);
		temp = (int)read(fd, buf, (size_t)size);
		ft_strncat(rez, buf, size);
		free(buf);
		if (temp != size)
			break;
		cursize += size;
		size *= 2;
	}
	return rez;
}

void	*ft_realloc(void *data, int size)
{
	char	*rez = malloc((size_t)size);
	int	offset = 0;
	while (--size)
	{
		*(rez + offset) = *(char *)(data + offset);
		offset++;
	}
	free(data);
	return rez;
}

char	*ft_strncat(char *str1, char *str2, int size)
{
	if (!str1 || !str2)
		return NULL;
	while (*str1)
		str1++;
	while (*str2 && size--)
		*(str1++) = *(str2++);
	*str1 = '\0';
	return NULL;
}

int	ft_atoi(char *str)
{
	long	rez = 0;
	char	sign = 0;
	while(*str == ' ' || *str == '\n' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
		sign = *str++ == '-' ? 1 : 0;
	while (*str <= '9' && *str >= '0'){
		rez = rez * 10 + *str++ - '0';
		if ((rez > 2147483647 && !sign) || rez > 2147483648)
			return (sign ? -2147483648 : 2147483647);
	}
	return (sign ? (int)-rez : (int)rez);
}
