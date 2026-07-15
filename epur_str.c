#include <unistd.h>

// Limpia espacios extra: imprime la cadena con una sola separación entre palabras
// Ej: "  hola    mundo  42  " -> "hola mundo 42"
int main (int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        char *s = av[1];
        int flag = 1;

        while(s[i])
        {
            while(s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
                i++;
            if(!flag)
                write(1, " ", 1);
            while(s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
            {
                write(1, &s[i++], 1);
                flag = 0;
            }
        }
    }
    write (1, "\n", 1);
    return (0);
}