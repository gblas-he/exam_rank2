#include <stdlib.h>
#include <stdio.h>

// Crea un array con números desde start hasta end
#include <stdlib.h>
#include <stdio.h>

// Crea un array con números desde start hasta end
int	*ft_range(int start, int end)
{
	int	size;
	int	*res;
	int	i;

	if (start > end)
		size = (start - end) + 1;
	else
		size = (end - start) + 1;

	res = malloc(size * sizeof(int));
	if (!res)
		return (NULL);

	i = 0;

	if (start < end)
	{
		while (start <= end)
		{
			res[i] = start;
			start++;
			i++;
		}
	}
	else
	{
		while (start >= end)
		{
			res[i] = start;
			start--;
			i++;
		}
	}

	return (res);
}
