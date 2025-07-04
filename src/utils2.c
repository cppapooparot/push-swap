/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:37:12 by nsahakya          #+#    #+#             */
/*   Updated: 2025/07/04 14:37:14 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		error_and_exit();
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	parse_and_fill(t_stack *stack, char *joined)
{
	char	**nums;
	int		i;
	int		value;

	nums = ft_split(joined, ' ');
	i = 0;
	while (nums[i])
	{
		value = atoi_with_limit_check(nums[i]);
		if (is_duplicate(stack, value))
			error_and_exit();
		push_bottom(stack, create_node(value));
		i++;
	}
	free_splitted(nums);
}

void	free_stack(t_stack *stack)
{
	t_node	*cur;
	t_node	*next;

	cur = stack->top;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(stack);
}
