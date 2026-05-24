#include <stdio.h>
#include <stdlib.h>

// Calcula y muestra el máximo común divisor (MCD) de dos números

void	pgcd(int a, int b)
{
	int n = a;

	// Busca el divisor común más grande
	while (n > 0)
	{
		if (a % n == 0 && b % n == 0)
		{
			printf("%d", n);
			return;
		}
		n--;
	}
}

int	main(int argc, char **argv)
{
	// Comprueba que haya 2 números
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return (0);
}