#include <unistd.h>

int	ft_atoi(char *s)
{
	int i = 0;
	int n = 0;
	int sign = 1;

	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i++] == '-')
			sign = -1;
	}
	while (s[i])
		n = (n * 10) + (s[i++] - '0');
	return (n * sign);
}

// Convierte un número decimal a su representación en hexadecimal y lo imprime.
void	print_hex(int n)
{
	char hex_n[] = "0123456789abcdef";

	if (n >= 16)
		print_hex(n / 16);
	write(1, &hex_n[n % 16], 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write (1, "\n", 1);
	return (0);
}