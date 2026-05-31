#include <unistd.h>

// Recorre la cadena av[1] y reemplaza un carácter específico (av[2][0]) por otro (av[3][0]) si ambos son letras válidas de un solo carácter, luego imprime el resultado.
int main(int ac, char **av)
{
	if (ac == 4)
	{
		int i = 0;
		if (av[2][1] == '\0' && av[2][1] == '\0')
		{
			while(av[1][i])
			{
				if (av[1][i] == av[2][0])
					av[1][i] = av[3][0];
				write(1,&av[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}