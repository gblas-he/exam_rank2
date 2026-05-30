#include <unistd.h>
#include <stdlib.h>

int ft_lenght(char *s)
{
    int i = 0;
    while(s[i] && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
        i++;
    return (i);
}

int count_words(char *s)
{
    int i = 0;
    int words = 0;
    while(s[i])
    {
        while(s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
            i++;
		// para evitar que continue que continue contando si llega al final
        if (s[i])
            words++;
        while(s[i] && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
            i++;
    }
    return(words);
}

void fill_words(char **arr, char *s)
{
    int i = 0;
    int j = 0;

    while (s[i])
    {
        while(s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
            i++;
		// para evitar que continue si llego al final despues de saltar espacios
        if (!s[i])
            break;
        arr[j] = malloc(sizeof(char) * (ft_lenght(&s[i]) + 1));
        if(!arr[j])
            return;
        int k = 0;
        while(s[i] && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
            arr[j][k++] = s[i++];
        arr[j][k] = '\0';
        j++;
    }
}

char    **ft_split(char *str)
{
    int words = count_words(str);
    char **arr = malloc(sizeof(char *) * (words + 1));
    if(!arr)
        return (NULL);
     // marca el fin del array de strings. Es como '\0' pero con array de string
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

    // Liberar memoria
    i = 0;
    while (s[i])
    {
        free(s[i]);
        i++;
    }
    free(s);
}