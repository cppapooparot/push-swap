/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:56:31 by nsahakya          #+#    #+#             */
/*   Updated: 2025/07/04 15:49:01 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	print_stack(t_stack *stack, const char *name)
{
	t_node	*cur;

	cur = stack->top;
	printf("Stack %s (top to bottom): ", name);
	while (cur)
	{
		printf("%d ", cur->value);
		cur = cur->next;
	}
	printf("\n");
}

static void	free_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

static void	init_stacks(t_stack **a, t_stack **b)
{
	*a = init_stack();
	*b = init_stack();
}

static void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
	{
		index_stack(a);
		butterfly_sort(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		error_and_exit();
	init_stacks(&a, &b);
	fill_stack(a, argc, argv);
	if (is_sorted(a))
	{
		free_stacks(a, b);
		return (0);
	}
	else
		sort_stack(a, b);
//	print_stack(a, "a");
	free_stacks(a, b);
	return (0);
}
