/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:28:33 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/06 07:42:54 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tab_sort(int *tab, unsigned int size)
{
	unsigned int	j;
	unsigned int	i;
	int				c;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				c = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = c;
			}
			i++;
		}
		j++;
	}
}
