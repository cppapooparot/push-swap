/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:53:23 by nsahakya          #+#    #+#             */
/*   Updated: 2025/07/04 10:59:08 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int	is_sorted(t_stack *stack)
{
	t_node	*cur;

	if (stack->size < 2)
		return (1);
	cur = stack->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

static void	sort_three_cases(t_stack *s, int f, int sec, int t)
{
	if (f > sec && sec < t && f < t)
		sa(s);
	else if (f > sec && sec > t)
	{
		sa(s);
		rra(s);
	}
	else if (f > sec && sec < t && f > t)
		ra(s);
	else if (f < sec && sec > t && f < t)
	{
		sa(s);
		ra(s);
	}
	else if (f < sec && sec > t && f > t)
		rra(s);
}

void	sort_three(t_stack *s)
{
	int	f;
	int	sec;
	int	t;

	if (!s || s->size < 3 || !s->top || !s->bottom)
		error_and_exit();
	f = s->top->value;
	sec = s->top->next->value;
	t = s->bottom->value;
	if (is_sorted(s))
		return ;
	sort_three_cases(s, f, sec, t);
}
