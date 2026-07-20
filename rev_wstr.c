#include <unistd.h>

// Invierte el orden de las palabras en una cadena e imprime el resultado palabra por palabra.
void	rev_wstr(char *s)
{
	int	i = 0;
	int	first = 1;

	// ir al final del string
	while (s[i])
		i++;
	i--;
	// i-- para estar en la ultima letra y no en '\0'
	while (i >= 0)
	{
		// por que recorrer desde el final puede haber espacios
		while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i--;
		// capturamos el caracter final
		int end = i;
		// si no es la priemra palabra imprime espacio si no quedaria " hola mundo"
		if (!first)
			write(1, " ", 1);
		while (i >= 0 && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			i--;
		// i + 1 porque si no no coje primera letra 
		int start = i + 1;
		//ponemos un limite en la palabra para que no se rompa el bucle
		while (start <= end)
		{
			write(1, &s[start++], 1);
			first = 0;
		}

	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
}

/* void rev_wstr(char *s)
{
	int i = 0;
	int end = 0;
	int start = 0;
	while(s[i])
		i++;
	i--;
	while (i >= 0)
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i--;
		end = i;
		while (s[i] &&s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			i--;
		start = i;
		while(start <= end)
		{
			if (s[start] != ' ' && s[start])
				write(1, &s[start], 1);
			start++;
		}
		if (s[i])
			write (1," ", 1);
	}
} */