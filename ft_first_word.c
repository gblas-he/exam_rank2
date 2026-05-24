#include <stdlib.h>

// Extrae la primera palabra de una cadena de caracteres
char	*first_word(char *str)
{
	int i;
	int j;
	int len;
	char *word;

	i = 0;
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	len = 0;
	while(str[i + len] && (str[i + len] != ' ' && str[i +len] != '\t'))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while(j < len)
		word[j++] = str[i++];
	word[j] = '\0';
	return (word);
}