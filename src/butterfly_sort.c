/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:26:40 by nsahakya          #+#    #+#             */
/*   Updated: 2025/07/04 10:55:54 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int	generate_chunk(int size)
{
	int	chunk;

	chunk = 1;
	if (size < 50)
		chunk = 3 + (size - 6) / 7;
	else if (size < 100)
		chunk = 10 + (size - 50) / 8;
	else if (size < 350)
		chunk = 18 + (size - 100) / 9;
	else if (size <= 500)
		chunk = 27 + (size - 350) / 15;
	else
		chunk = 37 + (size - 500) / 20;
	return (chunk);
}

static void	rotate_min_ops(t_stack *stack, int info[2])
{
	int	pos;
	int	size;

	pos = info[0];
	size = info[1];
	if (pos <= size / 2)
		while (pos-- > 0)
			rb(stack);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(stack);
	}
}
// arr[0] = chunk arr[1] = counter arr[2] = max_pos arr[3] = max_indx arr[4] = i

void	push_chunks(t_stack *a, t_stack *b, int chunk)
{
	int		limit;
	t_node	*cur;

	limit = 0;
	while (a->size > 0)
	{
		cur = a->top;
		if (cur->index <= limit)
		{
			pb(a, b);
			rb(b);
			limit++;
		}
		else if (cur->index <= limit + chunk)
		{
			pb(a, b);
			limit++;
		}
		else
			ra(a);
	}
}

void	pop_back(t_stack *a, t_stack *b)
{
	int		arr[5];
	t_node	*tmp;

	while (b->size > 0)
	{
		arr[1] = -1;
		arr[0] = 0;
		arr[2] = 0;
		tmp = b->top;
		while (tmp)
		{
			if (tmp->index > arr[1])
			{
				arr[1] = tmp->index;
				arr[0] = arr[2];
			}
			tmp = tmp->next;
			arr[2]++;
		}
		arr[3] = arr[0];
		arr[4] = b->size;
		rotate_min_ops(b, arr + 3);
		pa(a, b);
	}
}

void	butterfly_sort(t_stack *a, t_stack *b)
{
	int	chunk;

	chunk = generate_chunk(a->size);
	push_chunks(a, b, chunk);
	pop_back(a, b);
}
