#include "../includes/ft_printf.h"

void	ft_putnchar_fd(char c, int n, int fd)
{
	while (n-- > 0)
		write(fd, &c, 1);
}
