#include <stdio.h>
/*
Convierte una cadena de una base dada a entero.
Ejemplo:
"1010" base 2  → 10
"1a"   base 16 → 26
*/

// Convierte mayúscula a minúscula
char	to_lower(char c)
{
	// Convierte mayúsculas a minúsculas
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));

	return (c);
}

// Devuelve valor numérico (0-15) del dígito o -1 si no es válido en esa base
int	get_digit(char c, int digits_in_base)
{
	int	max_digit;

	// Define el carácter máximo válido según la base
	if (digits_in_base <= 10)
		max_digit = digits_in_base + '0';
	else
		max_digit = digits_in_base - 10 + 'a';

	// Convierte caracteres numéricos
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');

	// Convierte caracteres hexadecimales/letras
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');

	// Carácter inválido
	else
		return (-1);
}

// Convierte string en base str_base a entero (ej: "-FF",16 -> -255)
int	ft_atoi_base(const char *str, int str_base)
{
	int	result = 0;
	int	sign = 1;
	int	digit;

	// Detecta signo negativo
	if (*str == '-')
	{
		sign = -1;
		++str;
	}

	// Convierte cada carácter a número
	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{
		// Multiplica por la base y añade el nuevo dígito
		result = result * str_base;
		result = result + (digit * sign);

		++str;
	}

	return (result);
}

int	main(void)
{
	printf("%d\n", ft_atoi_base("1010", 2));   // 10
	printf("%d\n", ft_atoi_base("1a", 16));    // 26
	printf("%d\n", ft_atoi_base("-111", 2));   // -7
	printf("%d\n", ft_atoi_base("77", 8));     // 63

	return (0);
}