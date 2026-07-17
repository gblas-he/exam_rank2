// Invierte el orden de los bits de un byte
// Ejemplo: 11010110 → 01101011

void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0'; //'0' de número a caracter: +'0' de carcter a numero: -'0'
		write(1, &bit, 1);
		// octet >>= 1. No existe una forma de imprimirlos en el orden correcto sin almacenarlos antes o usar recursividad
}

unsigned char	reverse_bits(unsigned char octet)
{
	int				i = 8;
	unsigned char	res = 0;

	// Recorre los 8 bits del byte
	while (i--)
	{
		// (res << 1) Desplaza res a la izquierda en 1, 
		// (octet & 1) operacion and con el ultimo elemento de octet lo mete en bit menos significativo 
		// | ( es una operacion or y significa suma). Es decir mete el ultimo octet en res y desplaza a res en uno para meter el siguiente
		res = (res << 1) | (octet & 1);

		octet >>= 1; // octet >>= 1. Desplaza a la derecha los bits y actualiza la variable.
		// octet >> 1. Desplaza los bits sin modificar la variable.
	}

	return (res);
}

int	main(void)
{
	unsigned char n;
	unsigned char r;

	n = 245;
	print_bits(n);
	write(1, "\n", 1);
	r = reverse_bits(n);
	print_bits(r);
	write(1, "\n", 1);
	return (0);
}