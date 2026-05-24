#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_wordlen(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		++i;
	return (i);
}

char **fill_words(char **arr, char *s)
{
	int i = 0;
	int j;
	int len;
	int word_index = 0;

	while (s[i])
	{
		// Saltar espacios
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;

		if (s[i])
		{
			len = ft_wordlen(&s[i]);
			arr[word_index] = malloc(sizeof(char) * (len + 1));
			if (!arr[word_index])
				return (NULL);
			j = 0;
			while (j < len)
			{
				arr[word_index][j] = s[i + j];
				j++;
			}
			arr[word_index][j] = '\0';
			word_index++;

			// Saltar palabra
			while (s[i] != '\0' && s[i] != ' '
				&& s[i] != '\t' && s[i] != '\n')
				i++;
		}
	}
	return (arr);
}

int	count_words(char *s)
{
	int i = 0;
	int num_words = 0;

	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;

		// Si hay palabra
		if (s[i])
			num_words++;

		// Saltar palabra
		while (s[i] && s[i] != ' '
			&& s[i] != '\t' && s[i] != '\n')
			i++;
	}
	return (num_words);
}

char    **ft_split(char *str)
{
	int num_words = 0;
	char **arr;

	num_words = count_words(str);
	arr = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!arr)
		return (NULL);
	arr[num_words] = 0;
	arr = fill_words(arr, str);
	return (arr);
}

int main(void)
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