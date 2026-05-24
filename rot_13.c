#include <unistd.h>

// Este programa aplica el cifrado ROT13 al primer argumento recibido.
// ROT13 desplaza cada letra 13 posiciones en el alfabeto:
int main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)  // Solo si hay exactamente un argumento
	{
		while(av[1][i] != '\0')  // Recorre toda la cadena
		{
			// Letras A-M o a-m: avanzan 13 posiciones
			if ((av[1][i] >= 'a' && av[1][i]<= 'm') || (av[1][i] >= 'A' && av[1][i]<= 'M'))
				av[1][i] = av[1][i] + 13;
			// Letras N-Z o n-z: retroceden 13 posiciones
			else if ((av[1][i] >= 'n' && av[1][i]<= 'z') || (av[1][i] >= 'N' && av[1][i]<= 'Z'))
				av[1][i] = av[1][i] - 13;
			// Otros caracteres (números, espacios, etc.) no se modifican
			
			write(1, &av[1][i], 1);  // Imprime el carácter (modificado o no)
			i++;
		}
	}
	write(1, "\n", 1);  // Salto de línea al final
}