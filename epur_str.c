#include <unistd.h>

// Avanza el índice saltando espacios y tabs
int		skip_whitespace(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	return (i);
}

// Calcula la longitud de la siguiente palabra (hasta espacio/tab o fin)
int		ft_wordlen(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return (i);
}

// Limpia espacios extra: imprime la cadena con una sola separación entre palabras
// Ej: "  hola    mundo  42  " -> "hola mundo 42"
void	epur_str(char *str)
{
	int i = 0;
	int first_word = 1;  // Controla si es la primera palabra (sin espacio antes)
	int word_len;

	i = skip_whitespace(str, i);  // Salta espacios iniciales
	while (str[i] != '\0')
	{
		if (first_word == 0)       // Si no es la primera palabra
			write(1, " ", 1);      // Imprime un espacio separador
		word_len = ft_wordlen(str + i);  // Longitud de la palabra actual
		write(1, str + i, word_len);     // Imprime la palabra
		i = i + word_len;                 // Avanza al final de la palabra
		first_word = 0;                   // Ya no es la primera palabra
		i = skip_whitespace(str, i);      // Salta espacios hasta la siguiente palabra
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);  // Salto de línea final
	return (0);
}