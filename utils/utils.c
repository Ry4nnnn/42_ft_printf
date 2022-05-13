#include "../includes/ft_printf.h"

void	ft_putnchar_fd(char c, int n, int fd)
{
	while (n-- > 0)
		write(fd, &c, 1);
}

//for %p and %x and %X
char	*ft_rev(char *str)
{
	int		len;
	char	*ret;
	int		i;

	len = ft_strlen(str) - 1;
	ret = malloc(len + 2);
	i = 0;
	while (len >= 0)
	{
		ret[i] = str[len];
		i++;
		len--;
	}
	ret[i] = 0;
	return (ret);
}