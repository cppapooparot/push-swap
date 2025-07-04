/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:53:45 by nsahakya          #+#    #+#             */
/*   Updated: 2025/07/04 15:53:48 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_bonus.h"

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

void	fill_stack(t_stack *stack, int argc, char **argv)
{
	char	*joined;

	joined = join_arguments(argc, argv);
	parse_and_fill(stack, joined);
	free(joined);
}
