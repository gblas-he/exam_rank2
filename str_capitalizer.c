#include <unistd.h>

// Convierte cada palabra para que la primera letra sea mayúscula y el resto minúsculas, imprimiendo el resultado.
char	*str_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		// Convertir a minúscula si es mayúscula
		if (str[i] >= 'A' && str[i] <= 'Z')
	 		str[i] = str[i] + 32;

		// Si es la primera letra del string, o la anterior es espacio/tab,
		// ponerla en mayúscula
		if ((str[i] >= 'a' && str[i] <= 'z') &&
			(i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t'))
			str[i] = str[i] - 32;

		write(1, &str[i], 1);
		i++;
	}
	return (str);
}

int main(int ac, char **av)
{
    int i = 1;
    
    if (ac >= 2)
    {
        while (i < ac)
        {
            str_capitalizer(av[i]);
            write(1, "\n", 1);
            i++;
        }
    }
	else
    	write(1, "\n", 1);
    return (0);
}