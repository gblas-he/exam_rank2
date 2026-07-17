#include <unistd.h>

// Convierte cada palabra para que la primera letra sea mayúscula y el resto minúsculas, imprimiendo el resultado.
int main(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
		// Convertir a minúscula si es mayúscula
			if (av[i][j] >= 'A' && av[i][j] <= 'Z')
				av[i][j] += 32;
		// Si es la primera letra del string, o la anterior es espacio/tab,
		// ponerla en mayúscula
			if ((j == 0 || av[i][j - 1] == ' ' || av[i][j - 1] == '\t')
				&& (av[i][j] >= 'a' && av[i][j] <= 'z'))
				av[i][j] -= 32;
			write(1, &av[i][j++], 1);
		}
		write(1, "\n", 1);
		i++;
	}
	if (ac == 1)
		write(1, "\n", 1);
	return (0);
}