#include <unistd.h>

int	repeated_before(char *str, char c, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	char	*s1;
	char	*s2;

	if (ac == 3)
	{
		s1 = av[1];
		s2 = av[2];
		i = 0;
		while (s1[i])
		{
			j = 0;
			while (s2[j])
			{
				if (s1[i] == s2[j]
					&& !repeated_before(s1, s1[i], i))
				{
					write(1, &s1[i], 1);
					break ;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}