
#include <stdio.h>

// Comprueba si un número es potencia de 2, dividiéndolo sucesivamente entre 2 hasta llegar a 1.
int         is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n > 1)
	{
		if (n % 2 == 0)
			n = n / 2;
		else
			return (0);
	}
	return (1);
}
