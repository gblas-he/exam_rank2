#include <unistd.h>

// Invierte el orden de las palabras en una cadena e imprime el resultado palabra por palabra.
void	rev_wstr(char *s)
{
	int	i = 0;
	int	first = 1;

	while (s[i])
		i++;
	i--;

	while (i >= 0)
	{
		while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i--;
		// por que recorrer desde el principio puede a ver espacios
		// capturamos el caracter final
		int end = i;
		while (i >= 0 && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			i--;
		int start = i + 1;
		// si no es lapriemra palabra imprime espacio si no quedaria " hola mundo"
		if (!first)
			write(1, " ", 1);
		//ponemos un limite en la palabra para que no se rompa el bucle
		while (start <= end)
		{
			write(1, &s[start], 1);
			start++;
		}
		first = 0;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
}