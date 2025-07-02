/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:26:40 by nsahakya          #+#    #+#             */
/*   Updated: 2025/07/02 16:12:52 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

#include "stack.h"

int generate_chunk(int size)
{
	int chunk = 1;

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

static void rotate_min_ops(t_stack *stack, int info[2], void (*rotate_func)(t_stack *), void (*rev_rotate_func)(t_stack *))
{
	int pos = info[0];
	int size = info[1];

	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate_func(stack);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rev_rotate_func(stack);
	}
}

void butterfly_sort(t_stack *a, t_stack *b)
{
	int chunk = generate_chunk(a->size);
	int counter = 0;
	t_node *cur;

	while (a->size > 0)
	{
		cur = a->top;
		if (cur->index <= counter)
		{
			pb(a, b);
			rb(b);
			counter++;
		}
		else if (cur->index <= counter + chunk)
		{
			pb(a, b);
			counter++;
		}
		else
			ra(a);
	}

	while (b->size > 0)
	{
		int max_pos = 0;
		int max_idx = -1;
		int i = 0;
		t_node *tmp = b->top;

		while (tmp)
		{
			if (tmp->index > max_idx)
			{
				max_idx = tmp->index;
				max_pos = i;
			}
			tmp = tmp->next;
			i++;
		}

		int info[2] = { max_pos, b->size };
		rotate_min_ops(b, info, rb, rrb);
		pa(a, b);
	}
}

