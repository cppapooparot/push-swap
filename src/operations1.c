/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:22:56 by nsahakya          #+#    #+#             */
/*   Updated: 2025/07/04 10:56:36 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	push(t_stack *src, t_stack *dst)
{
	t_node	*node;

	node = pop_top(src);
	if (node)
		push_top(dst, node);
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return ;
	node = pop_top(stack);
	push_bottom(stack, node);
}

void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}
