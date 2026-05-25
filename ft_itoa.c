#include <stdlib.h>

/* Devuelve el número de dígitos de un entero n */
int	ft_digits(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1; // Para el '-' o el '0' porque necesita un espacio estos para el malloc
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

/* Convierte un entero n a una cadena */
char	*ft_itoa(int n)
{
	char		*str;
	long int	num;
	int			len;

	num = n;
	len = ft_digits(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	/* ¿Por qué llenamos de derecha a izquierda? Porque extraemos los dígitos del final al principio:
	118 % 10 = 8  ← Último dígito, 11 % 10 = 1   ← Penúltimo dígito, 1 % 10 = 1    ← Primer dígito*/
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}