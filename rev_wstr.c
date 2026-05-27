
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
	int i = 0;
	
	while (str[i])
		i++;
	return (i);
}

// Invierte el orden de las palabras en una cadena e imprime el resultado palabra por palabra.
int main(int ac, char *av[])
{
	char *tmp;
	char *rev;
	int len;

	if (ac == 2)
	{
		tmp = av[1];
		len = ft_strlen(tmp); // Calcula longitud
		rev = NULL;
		len--;
		while (tmp[len]) // Recorre desde el final
		{
			if (tmp[len - 1] == ' ') // Si encuentra un espacio antes del carácter actual
			{
				rev = &tmp[len]; // rev apunta al inicio de la palabra
				while (*rev && *rev != ' ')
				{
					ft_putchar(*rev);
					rev++;
				}
				ft_putchar(' ');
			}
			else if (len == 0) // Si llegó al inicio (primera palabra
			{
				rev = &tmp[len]; // rev apunta al inicio de la primera palabra
				while (*rev && *rev != ' ')
				{
					ft_putchar(*rev);
					rev++;
				}
			}
			len--;
		}
	}
	ft_putchar('\n');
}
