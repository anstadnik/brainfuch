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
	int	size = 32;
	char	*rez = malloc(1);
	rez[0] = '\0';
	char	*buf = NULL;
	int	temp;
	while (42)
	{
		rez = ft_realloc(rez, sizeof(rez) + size);
		buf = malloc(size);
		temp = read(fd, buf, size);
		ft_strncat(rez, buf, size);
		ft_putstr(buf);
		ft_putstr("\n");
		ft_putstr("\n");
		ft_putstr("\n");
		free(buf);
		ft_putstr("Potato\n");
		if (temp != size)
			break;
		else
			size *= 2;
	}
	return rez;
}

void	*ft_realloc(void *data, int size)
{
	char	*rez = malloc(size);
	int	offset = 0;
	while (size-- && data)
		*(rez + offset++) = *(char *)(data + offset);
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
