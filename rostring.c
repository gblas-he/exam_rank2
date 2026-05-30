#include <unistd.h>

// Limpia espacios extra: imprime la cadena con una sola separación entre palabras
void epur_str(char *s)
{
	int i = 0;
	int flag = 0;

	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;

		if (s[i] && flag)
			write(1, " ", 1);

		while (s[i] && s[i] != ' ' && s[i] != '\t')
		{
			write(1, &s[i], 1);
			i++;
			flag = 1;
		}
	}
	
	// variación epur_str: imprimir espacio antes de la primera palabra si hay resto si no no imprime espacio
	if (flag)
		write(1, " ", 1);
}

// Mueve la primera palabra al final de la string
void rostring(char *s)
{
	int i = 0;
	int start = 0;
	int end = 0;

	// guardar primera palabra
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	start = i;
	while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		i++;
	end = i;
	epur_str(&s[i]);

	// imprimir primera palabra
	while (start < end)
	{
		write(1, &s[start], 1);
		start++;
	}
}

int main(int ac, char **av)
{
	if (ac >= 2)
		rostring(av[1]);
	write (1, "\n", 1);
	return (0);
}