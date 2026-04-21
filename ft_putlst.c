/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:58:11 by gblas-he          #+#    #+#             */
/*   Updated: 2026/04/21 18:11:22 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

void	ft_putlst(t_list *list)
{
	t_list *current;

	current = list;
	while (current != NULL)
	{
		ft_putnbr(current->data);
		current = current->next;
		if (current != NULL)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}