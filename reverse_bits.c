// Invierte el orden de los bits de un byte
// Ejemplo: 11010110 → 01101011

unsigned char	reverse_bits(unsigned char octet)
{
	int				i = 8;
	unsigned char	res = 0;

	// Recorre los 8 bits del byte
	while (i > 0)
	{
		// (res << 1) Desplaza res a la izquierda en 1 | (octet & 1) peracion and con elultimo elemento de octet, bit menos significativo
		res = (res << 1) | (octet & 1);

		// Desplaza octet a la derecha en 1 bit
		octet >>= 1;
		i--;
	}

	return (res);
}