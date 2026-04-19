/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:24:59 by gblas-he          #+#    #+#             */
/*   Updated: 2026/04/19 12:25:38 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Cuenta el numero de palabras en una cadena delimitadas por el caracter c */
static int ft_word_count(const char *s, char c)
{
    int i;
    int count;
    int in_word;

    i = 0;
    count = 0;
    in_word = 0;
    while (s[i])
    {
        if (s[i] != c && in_word == 0)
        {
            in_word = 1;
            count++;
        }
        else if (s[i] == c)
            in_word = 0;
        i++;
    }
    return (count);
}