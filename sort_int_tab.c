/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:31:03 by gblas-he          #+#    #+#             */
/*   Updated: 2026/04/25 13:31:39 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	int tmp;


	i = 0;
	while(i < size)
	{
		j = 0;
		tmp = 0;
		while(j < size - 1 - i)
		{			
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int main (void)
{
	int i;

	int arr []= {5, 2, 3, 10, 8};
	sort_int_tab(arr, 5);
	i = 0;
	while(i < 5)
	{
		printf("-->%d ", arr[i]);
		i++;
	}
	return(0);
}