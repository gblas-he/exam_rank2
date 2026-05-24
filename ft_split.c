#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char **ft_words(char **arr, char *s)
{
	int i = 0;
	int words = 0;

    while (s[i])
    {
        // Saltar espacios
        while (s[i] == ' ')
            i++;
        // Si no es el final, es una palabra
        if (s[i])
            words++;
        // Saltar la palabra
        while (s[i] && s[i] != ' ')
            i++;
    }
	return (words);
}

int	ft_strwordlen(char *s)
{
	int i = 0;
	int words = 0;

    while (s[i])
    {
        // Saltar espacios
        while (s[i] == ' ')
            i++;
        // Si no es el final, es una palabra
        if (s[i])
            words++;
        // Saltar la palabra
        while (s[i] && s[i] != ' ')
            i++;
    }
	return (words);
}

char    **ft_split(char *str)
{
	int i = 0;
	int words = 0;
	char **arr;

	words = ft_strwordlen(str);
	arr = (char **)malloc(words + 1);
	if (!arr)
		return NULL;
	arr[words] = 0;
	arr = ft_words(arr, str);
	return (arr);
}

int main (void)
{
	int i = 0;
	char **s = ft_split("  Hello world   welcome to the jungle  ");

    while (s[i])
    {
        printf("%s\n", s[i]);
        free(s[i]);
        i++;
    }
    free(s);
	return (0);
}