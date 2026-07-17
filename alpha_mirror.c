#include <unistd.h>

// Aplica un cifrado tipo "mirror" (rotación del alfabeto): reemplaza cada letra por su reflejo en el alfabeto y la imprime.
int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				av[1][i] = 219 - av[1][i]; // 219 = 'a' + 'z'. Convierte a↔z, b↔y... Sustituye la letra por su opuesta en el alfabeto.
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] = 155 - av[1][i]; // 155 = 'A' + 'Z'. Convierte A↔Z, B↔Y... Sustituye la letra por su opuesta en el alfabeto.
			write(1, &av[1][i++], 1);
		}
	}
	write(1, "\n", 1);
}