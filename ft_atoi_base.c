#include <unistd.h>

/* Convierte un carácter a valor numérico */
int	ft_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

/* Convierte un número en cualquier base a decimal */
int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	sign;
	int	value;
	int	i;
	
	/* Comprueba la base */
	if (str_base < 2 || str_base > 16)
		return (0);
	result = 0;
	sign = 1;
	i = 0;
	/* Comprueba signo negativo */
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	/* Convierte mientras los caracteres sean válidos */
	value = ft_value(str[i]);
	// value < str_base: validación de la base. Comprueba que el carácter sea válido.
	// str = "12A45" < base = 10 carácter no es válido bucle se rompe
	while (value >= 0 && value < str_base)
	{
		result = (result * str_base) + value; // Multiplica el resultado por la base para desplazar los dígitos y suma el nuevo valor convertido.
		value = ft_value(str[++i]);
	}
	/* Devuelve el resultado final */
	return (result * sign);
}

int	main(void)
{
	printf("Base 10: %d\n", ft_atoi_base("17628934", 10));
	printf("Base 2: %d\n", ft_atoi_base("111010110111100110100010101", 2));
	printf("Base 16: %d\n", ft_atoi_base("7DE98115", 16));
	printf("Base 16 mayus: %d\n", ft_atoi_base("-1ABCDEF", 16));
	printf("Base 8: %d\n", ft_atoi_base("726746425", 8));
	printf("Negativo base 10: %d\n", ft_atoi_base("-987654321", 10));

	return (0);
}