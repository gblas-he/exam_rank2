#include <unistd.h>

// Imprime la última palabra de un string
int main(int ac, char **av)
{
	int i;
	int end;
	int start;

	if (ac == 2)
	{
		i = 0;
		while(av[1][i])
			i++;
		i--;
		while(av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t' || av[1][i] == '\n'))
			i--;
		end = i;
		while(av[1][i] && av[1][i] != ' ' && av[1][i] != '\t' && av[1][i] != '\n')
			i--;
		start = i + 1;
		while(start <= end)
			write(1, &av[1][start++], 1);
	}
	write(1,"\n", 1);
	return (0);
}

/* void	last_word(char *str)
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
} */

// Programa principal: toma un argumento y muestra su última palabra
int		main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}