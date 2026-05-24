#include <unistd.h>

// Imprime la última palabra de un string
void	last_word(char *str)
{
	int	j = 0;
	int i = 0;

	// Busca el inicio de la última palabra
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] >= 33 && str[i + 1] <= 126)
			j = i + 1;  // Guarda posición del primer carácter de la palabra
		i++;
	}
	
	// Imprime la palabra desde j hasta el final
	while (str[j] >= 33 && str[j] <= 126)
	{
		write(1, &str[j], 1);
		j++;
	}
}

// Programa principal: toma un argumento y muestra su última palabra
int		main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}