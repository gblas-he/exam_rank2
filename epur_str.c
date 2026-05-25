#include <unistd.h>

// Limpia espacios extra: imprime la cadena con una sola separación entre palabras
// Ej: "  hola    mundo  42  " -> "hola mundo 42"
int main (int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        char *str = av[1];
        int flag = 0;

        while(str[i])
        {
            while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
                i++;
            if (str[i] && flag == 1)
                write (1, " ", 1);
            while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            {
                write (1, &str[i], 1);
                flag = 1;
                i++;
            }
        }
    }
    write (1, "\n", 1);
    return (0);
}