#include <unistd.h>
#include <stdio.h>

// Intercambia los valores de dos variables enteras usando punteros.
void    ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}