/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:51:18 by nsahakya          #+#    #+#             */
/*   Updated: 2025/07/04 12:26:08 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include "stack_bonus.h"

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

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static void	strip_newline(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		if (*str == '\n')
		{
			*str = '\0';
			break ;
		}
		str++;
	}
}

static void	execute_instruction(char *instr, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(instr, "sa"))
		sa(a);
	else if (!ft_strcmp(instr, "sb"))
		sb(b);
	else if (!ft_strcmp(instr, "ss"))
		ss(a, b);
	else if (!ft_strcmp(instr, "pa"))
		pa(a, b);
	else if (!ft_strcmp(instr, "pb"))
		pb(a, b);
	else if (!ft_strcmp(instr, "ra"))
		ra(a);
	else if (!ft_strcmp(instr, "rb"))
		rb(b);
	else if (!ft_strcmp(instr, "rr"))
		rr(a, b);
	else if (!ft_strcmp(instr, "rra"))
		rra(a);
	else if (!ft_strcmp(instr, "rrb"))
		rrb(b);
	else if (!ft_strcmp(instr, "rrr"))
		rrr(a, b);
	else
		error_and_exit();
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	fill_stack(a, argc, argv);
	line = get_next_line(0);
	while (line != NULL)
	{
		strip_newline(line);
		execute_instruction(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a);
	free_stack(b);
	return (0);
}
