#include <unistd.h>
#include <stdlib.h>

int ft_lenght(char *s)
{
	int i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
	{
		i++;
	}
	return (i);
}

int count_words(char *str)
{
	int i = 0;
	int words = 0;

	while (str[i])
	{
		while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
        if (str[i])
            words++;
		while(str[i] && str[i] != ' '&& str[i] != '\t' && str[i] != '\n')
			i++;
	}
	return (words);
}

void fill_words(char **arr, char *s)
{
	int i = 0;
	int w = 0;
	while(s[i])
	{
		while(s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
        if (!s[i])
            break;
		arr[w] = malloc(ft_lenght(&s[i]) + 1);
		if (!arr[w])
			return;
		int j = 0;
		while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			arr[w][j++] = s[i++];
		arr[w][j] = '\0';
		w++;
	}
}

char    **ft_split(char *str)
{
	int words;

	words = count_words(str);
	char **arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
    	return NULL;
	arr[words] = NULL;
	fill_words(arr, str);
	return (arr);
}

int main(void)
{
    char **s = ft_split("   Welcome tO   the    junGle ");

    int i = 0;
    int j;

    while (s[i])
    {
        j = 0;
        while (s[i][j])
        {
            write(1, &s[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}