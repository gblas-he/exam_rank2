#include <stdio.h>

// Convierte un string en un entero (ej: "  -123" -> -123)
// Ignora signo opcional y lee dígitos hasta encontrar un no-dígito
int     ft_atoi(const char *str)
{
	int	nbr;
	int sign;
	int	i;

	nbr = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0'); // (nbr * 10) permite avanzar en el numero a la derecha
	return (nbr * sign);
}
