#include <unistd.h>

// Imprime la cadena pasada como argumento al revés, carácter por carácter.
int	main(int argc, char *argv[])
{
	int	i = 0;

	if (argc == 2)
	{
		while (argv[1][i])
			i += 1;
		while (i) // i > 0 tambien puede ser
			write(1, &argv[1][--i], 1);
	}
	write(1, "\n", 1);
	return (0);
}

/* int main (int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		while (av[1][i])
			i++;
		i--;
		while(i >= 0)
		{
			write(1, &av[1][i], 1);
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
} */