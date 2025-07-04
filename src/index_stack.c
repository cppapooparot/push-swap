/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:47:50 by nsahakya          #+#    #+#             */
/*   Updated: 2025/07/04 10:56:11 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

static t_node	*get_next_min(t_stack *stack)
{
	t_node	*cur;
	t_node	*min;
	int		has_min;

	cur = stack->top;
	min = NULL;
	has_min = 0;
	while (cur)
	{
		if (cur->index == -1 && (!has_min || cur->value < min->value))
		{
			min = cur;
			has_min = 1;
		}
		cur = cur->next;
	}
	return (min);
}

void	index_stack(t_stack *stack)
{
	t_node	*cur;
	int		index;
	t_node	*min;

	cur = stack->top;
	while (cur)
	{
		cur->index = -1;
		cur = cur->next;
	}
	index = 0;
	min = get_next_min(stack);
	while (min)
	{
		min->index = index++;
		min = get_next_min(stack);
	}
}
