

#include <unistd.h>

void	ft_putnbr(int n)
{
	char digit;

	if (n >= 10)
		ft_putnbr(n / 10);

	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

// Imprime la cantidad de argumentos recibidos por el programa (argc - 1).
int		main(int argc, char **argv)
{
	(void)argv;		// Silence 'unused parameter' error

	ft_putnbr(argc - 1);
	write(1, "\n", 1);

	return (0);
}
/* 
void ft_putnbr(int n)
{
	char c;

	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}

	if(n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	(void)av;
	int i;

	i = 0;
	while(i < ac)
		i++;
	ft_putnbr(i - 1);
	write(1, "\n", 1);
	return(0);
} */