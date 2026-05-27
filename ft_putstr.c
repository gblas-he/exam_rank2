#include <unistd.h>

// Imprime una cadena de texto carácter por carácter en la salida estándar.
void    ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}