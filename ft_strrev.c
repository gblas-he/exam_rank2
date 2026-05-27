
/* Invierte el string modificándolo directamente (in-place) y lo retorna */
char *ft_strrev(char *str)
{
	int i = -1; // i = 0
	int length = 0;
	char temporary;

	while (str[length])
		length++;
	while (++i < length / 2)
	{
		temporary = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = temporary; // i = 0 al final se tendria que añadir i++ ya que no hacemos ++i, ahorramos espacio;
	}
	return (str);
}
