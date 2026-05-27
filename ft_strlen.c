
// Calcula y devuelve la longitud de un string (número de caracteres hasta '\0')
int     ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')  // Recorre hasta encontrar el final
		i++;
	return (i);  // Devuelve el contador
}