#include <unistd.h>

// Comprueba si av[1] aparece como subsecuencia en av[2] y, si es así, imprime av[1].
int main ( int ac, char **av)
{
	int i;
	int j;

	if ( ac == 3)
	{
		i = 0;
		j = 0;
		while(av[2][i])
		{
			if (av[2][i] == av[1][j])
				j++;
			i++;
		}
		if (av[1][j] == '\0')
		{
			j = 0;
			while(av[1][j])
				write(1, &av[1][j++], 1);
		}
	}
	write (1, "\n", 1);
	return (0);
}