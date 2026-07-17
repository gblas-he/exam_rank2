#include <stdio.h>
#include <stdlib.h>

// Calcula y muestra el máximo común divisor (MCD) de dos números. El número más grande que los divide 
/* MCD: preguntas "¿n divide a a y b?"
	if (a % n == 0 && b % n == 0)
   MCM: preguntas "¿a y b dividen a n?"
	if (n % a == 0 && n % b == 0)*/

int main (int ac, char **av)
{
	int i;
	int n1;
	int n2;
	int mcd;

	if (ac == 3)
	{
		i = 1;
		mcd = 1;
		n1 = atoi(av[1]);
		n2 = atoi(av[2]);
		while(i <= n1)
		{
			if(n1 % i == 0 && n2 % i == 0)
				mcd = i;
			i++;
		}
		printf("%d", mcd);
	}
	printf("\n");
	return (0);
} 

/* void	pgcd(int a, int b)
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
		// n-- lo usamos en este caso porque usamos n como un iterador de n hasta 0
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
} */