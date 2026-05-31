#include <unistd.h>

// imprime primera palabra de un string
int main (int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		char *s = av[1];

		while(s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while(s[i] && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}