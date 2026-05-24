// Calcula el mínimo común múltiplo (LCM) de dos números

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int n;	

	// Si uno es 0, el resultado es 0
	if (a == 0 || b == 0)
		return (0);

	// Empieza desde el número mayor
	if (a > b)
		n = a;
	else
		n = b;

	// Busca el primer múltiplo común
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		n++;
	}
}