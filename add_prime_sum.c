#include <unistd.h>
void	ft_putnbr(int n)
{
	char c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int ft_atoi(char *s)
{
	int i;
	int sign;
	int n;

	i = 0;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if(s[i] == '-')
			sign = -1;
		i++;
	}
	n = 0;
	while(s[i] >= '0' && s[i] <= '9')
	{
		n = (n * 10) + (s[i] - '0');
		i++;
	}
	return (n * sign);
}

int isprime(int n)
{
	int i;

	i = 2;
	while(i < n)
	{
		if(n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

// Convierte un número de la entrada y calcula la suma de todos los números primos desde 2 hasta n, imprimiendo el resultado.
int main(int ac, char **av)
{
	int i;
	int n;
	int sum;

	if (ac == 2)
	{
		sum = 0;
		i = 2;
		n = ft_atoi(av[1]);
		while(i <= n)
		{
			if(isprime(i))
				sum += i;
			i++;
		}
		ft_putnbr(sum);
	}
	else
		ft_putnbr(0);
	write(1, "\n", 1);
	return(0);
}