/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:54:33 by nsahakya          #+#    #+#             */
/*   Updated: 2025/07/04 10:59:42 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		error_and_exit();
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

void	push_top(t_stack *stack, t_node *node)
{
	node->prev = NULL;
	node->next = stack->top;
	if (stack->top)
		stack->top->prev = node;
	else
		stack->bottom = node;
	stack->top = node;
	stack->size++;
}

void	push_bottom(t_stack *stack, t_node *node)
{
	node->next = NULL;
	node->prev = stack->bottom;
	if (stack->bottom)
		stack->bottom->next = node;
	else
		stack->top = node;
	stack->bottom = node;
	stack->size++;
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size == 0)
		return (NULL);
	tmp = stack->top;
	stack->top = tmp->next;
	if (stack->top)
		stack->top->prev = NULL;
	else
		stack->bottom = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	stack->size--;
	return (tmp);
}

t_node	*pop_bottom(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size == 0)
		return (NULL);
	tmp = stack->bottom;
	stack->bottom = tmp->prev;
	if (stack->bottom)
		stack->bottom->next = NULL;
	else
		stack->top = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	stack->size--;
	return (tmp);
}
