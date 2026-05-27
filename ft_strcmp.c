#include <stdio.h>
#include <string.h>

// Compara dos cadenas carácter por carácter y devuelve la diferencia entre la primera posición en la que son distintas.
int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
