char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	// Capitalizar primer carácter si es minúscula
	if ((str[0] >= 'a') && (str[0] <= 'z'))
		str[0] = str[0] - 32;
	while (str[i])
	{
		// Si hay espacio o guion seguido de minúscula, capitalizar
		if (((str[i] == ' ') || (str[i] == '-'))
			&& (str[i + 1] >= 'a') && (str[i + 1] <= 'z'))
			str[i + 1] = str[i + 1] - 32;
		i++;
	}
	return (str);
}