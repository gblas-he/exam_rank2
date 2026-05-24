#include <unistd.h>

// Muestra los bits de un byte en binario
// Ejemplo: 2 → 00000010

void	print_bits(unsigned char octet)
{
	int				i = 8;
	unsigned char	bit;

	// Recorre los 8 bits del byte
	while (i--)
	{
		// Desplaza el bit deseado y obtiene solo 0 o 1
		bit = ((octet >> i) & 1) + '0';

		// Escribe el bit como carácter
		write(1, &bit, 1);
	}
}