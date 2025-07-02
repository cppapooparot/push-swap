/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:58:43 by nsahakya          #+#    #+#             */
/*   Updated: 2025/06/30 14:37:51 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;
	int	n;

	max_bits = 0;
	size = a->size;
	i = 0;
	while ((size - 1) >> max_bits)
		max_bits++;

	for (i = 0; i < max_bits; i++)
	{
		j = 0;
		n = a->size;
		while (j < n)
		{
			if ((a->top->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (b->size)
			pa(a, b);
	}
} 
