#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int	temp;

	// Recorre el array hasta que no haya intercambios. si el tamaño es 3 seria -1 porque 0,1,2
	while (i < (size - 1))
	{
		// Si el elemento actual es mayor que el siguiente, los intercambia
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i+ 1];
			tab[i + 1] = temp;
			i = 0; // Reinicia desde el principio tras cada intercambio
		}
		else
			i++;
	}
}

int main (void)
{
	int i;

	int arr []= {5, 2, 3, 10, 8};
	sort_int_tab(arr, 5);
	i = 0;
	while(i < 5)
	{
		printf("-->%d ", arr[i]);
		i++;
	}
	return(0);
}

/* Array inicial: [5, 6, 2, 10]

i=0: 5 > 6 → no → i=1
i=1: 6 > 2 → intercambia → [5, 2, 6, 10], i=0
i=0: 5 > 2 → intercambia → [2, 5, 6, 10], i=0
i=0: 2 > 5 → no → i=1
i=1: 5 > 6 → no → i=2
i=2: 6 > 10 → no → i=3
i=3: 3 < 3 → fin del while

Array final: [2, 5, 6, 10] */