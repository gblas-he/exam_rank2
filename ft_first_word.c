/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:14:46 by gblas-he          #+#    #+#             */
/*   Updated: 2026/04/19 15:16:58 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Extrae la primera palabra de una cadena de caracteres
char	*first_word(char *str)
{
	int i;
	int j;
	int len;
	char *word;

	i = 0;
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	len = 0;
	while(str[i + len] && (str[i + len] != ' ' && str[i +len] != '\t'))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while(j < len)
		word[j++] = str[i++];
	word[j] = '\0';
	return (word);
}