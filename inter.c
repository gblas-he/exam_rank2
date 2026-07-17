#include <unistd.h>

// Concatena, sin duplicados y en orden de aparición, las letras que aparecen en ambas cadenas.
int main(int ac, char **av)
{
	int i;
	int j;
	int repeated;

	if (ac == 3)
	{
		i = 0;
		while (av[1][i]) // Recorre la primera cadena
		{
			repeated = 0;
			j = 0;
			while (j < i) // Comprueba si la letra ya apareció antes
			{
				if (av[1][j] == av[1][i])
				{
					repeated = 1;
					break;
				}
				j++;
			}
			if (!repeated) // Solo busca si es la primera aparición
			{
				j = 0;
				while (av[2][j]) // Busca la letra en la segunda cadena
				{
					if (av[2][j] == av[1][i])
					{
						write(1, &av[1][i], 1); // Imprime la coincidencia
						break; // Evita imprimirla varias veces
					}
					j++;
				}
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}