#include <unistd.h>

// Imprime la tabla de multiplicar del número dado (del 1 al 9), mostrando cada operación y su resultado.
int		ft_atoi(char *str)
{
	int n = 0;

	while (*str >= '0' && *str <= '9')
	{
		n = (n * 10) + (*str - '0');
		++str;
	}
	return (n);
}

void ft_putnbr(int n)
{
	char c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write (1, &c, 1);
}

int main(int ac, char **av)
{
	int i = 1;
	int n = 0;

	if (ac == 2)
	{
		n = ft_atoi(av[1]);
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(n);
			write(1, " = ", 3);
			ft_putnbr(i * n);
			write(1, "\n", 1);
			++i;
		}
	}
	else
		write(1, "\n", 1);
	return(0);
}