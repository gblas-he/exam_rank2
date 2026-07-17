
/* Invierte el string modificándolo directamente (in-place) y lo retorna */
char *ft_strrev(char *str)
{
	int i = -1; // i = 0
	int length = 0;
	char tmp;

	while (str[length])
		length++;
	while (++i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - 1 - i]; // -1 pq no queremos '\0'y -i pq queremos que vaya avanzando simetricamente a la letra que queremos reemplazar.
		str[length - 1 - i] = tmp; // i = 0 al final se tendria que añadir i++ ya que no hacemos ++i, ahorramos espacio;
	}
	return (str);
}
