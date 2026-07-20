#include <unistd.h>

// Concatena, sin duplicados y en orden de aparición, las letras unicas que no aparecen en ambas cadenas.
int main(int ac, char **av)
{
	int i;
	int j;
	int rep;

	if (ac == 3)
	{
		i = 0;
		while (av[1][i]) // Recorre la primera cadena
		{
			rep = 0;
			j = 0;
			while (j < i) // Comprueba si la letra ya apareció antes en av[1]
			{
				if (av[1][j] == av[1][i])
				{
					rep = 1;
					break;
				}
				j++;
			}
			if (!rep) // Solo la primera aparición se imprime
				write(1, &av[1][i], 1);
			i++;
		}
		i = 0;
		while (av[2][i]) // Recorre la segunda cadena
		{
			rep = 0;
			j = 0;
			while (av[1][j]) // Comprueba si la letra ya apareció en av[1]
			{
				if (av[1][j] == av[2][i])
				{
					rep = 1;
					break;
				}
				j++;
			}
			if (!rep)
			{
				j = 0;
				while (j < i) // Comprueba si ya apareció antes en av[2]
				{
					if (av[2][j] == av[2][i])
					{
						rep = 1;
						break;
					}
					j++;
				}
			}
			if (!rep) // Solo si no está ni en av[1] ni repetida en av[2]
				write(1, &av[2][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* 
// Concatena dos cadenas y luego imprime los caracteres únicos (sin repeticiones), en orden de aparición.
int check(int c, char *s, int index)
{
	int i = 0;
	
	while(i < index)
	{
		if (s[i] == c)
			return 0;
		i++;
	}
	return  1;
}

int main(int ac, char **av)
{	
	int i = 0;
	int j = 0;
	int k = 0;
	
	if (ac == 3)
	{
		while(av[1][i])
			i++;
		while(av[2][j])
		{
			av[1][i] = av[2][j];
			i++;
			j++;
		}
		i--;
		while(k <= i)
		{
			if(check(av[1][k], av[1], k) == 1) 
				write (1, &av[1][k], 1); 
			k++;
		}
	}
	write (1, "\n", 1);
}
 */