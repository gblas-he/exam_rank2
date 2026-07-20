#include <stdlib.h>

int		absolute_value(int n);

// Reserva y devuelve un array de enteros con todos los valores desde end hasta start en orden inverso.
int		*ft_rrange(int start, int end)
{
	int size;
	int i;

	size = 0;
	if(start > end)
		size = start - end;
	else 
		size = end - start;
	
	int *arr = malloc(sizeof(int) * (size + 1));
	if (!arr)
		return (NULL);

	if(start > end)
	{
		i = 0;
		while(start >= end)
			arr[i++] = start--;
	}
	else
	{
		i = 0;
		while(end >= start)
			arr[i++] = end--;
	}
	return (arr);
}