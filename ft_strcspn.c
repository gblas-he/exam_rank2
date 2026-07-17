#include <unistd.h>

// Devuelve la longitud del prefijo de la cadena s que no contiene ningún carácter presente en reject.
size_t  ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (reject[j] == s[i])
				return (i); // break; si usamos esto solo sale del segundo bucle pero continua con el primero
			j++;
		}
		i++;
	}
	return (i);
}
