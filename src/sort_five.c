/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:52:29 by nsahakya          #+#    #+#             */
/*   Updated: 2025/07/04 10:58:30 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int	find_min_pos(t_stack *stack)
{
	int		min;
	int		pos;
	int		i;
	t_node	*cur;

	min = stack->top->value;
	pos = 0;
	i = 0;
	cur = stack->top;
	while (cur)
	{
		if (min > cur->value)
		{
			min = cur->value;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

static void	move_min_to_top(t_stack *a, int pos)
{
	if (pos == 1)
		ra(a);
	else if (pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (pos == 3 && a->size == 5)
	{
		rra(a);
		rra(a);
	}
	else if (pos == 4 || (pos == 3 && a->size == 4))
		rra(a);
}

void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	pos;

	pos = find_min_pos(a);
	if (pos != 0)
		move_min_to_top(a, pos);
	pb(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
	if (a->top->value > a->top->next->value)
		sa(a);
}
