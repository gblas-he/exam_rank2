#include <unistd.h>

// Mueve la primera palabra al final de la string
void	rostring(char *s)
{
	int	i = 0;
	int	start;
	int	end;
	int	flag = 0;

	// guardar primera palabra
	while (s[i] == ' ' || s[i] == '\t')
		i++;

	start = i;

	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;

	end = i;

	// imprimir resto
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;

		if (s[i] && flag)
			write(1, " ", 1);

		while (s[i] && s[i] != ' ' && s[i] != '\t')
		{
			write(1, &s[i], 1);
			i++;
			flag = 1;
		}
	}

	// imprimir espacio antes de la primera palabra
	if (flag)
		write(1, " ", 1);

	// imprimir primera palabra
	while (start < end)
	{
		write(1, &s[start], 1);
		start++;
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
		rostring(av[1]);

	write(1, "\n", 1);
	return (0);
}