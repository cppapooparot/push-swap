/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:50:36 by nsahakya          #+#    #+#             */
/*   Updated: 2025/07/04 10:58:02 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int	is_number(const char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

int	atoi_with_limit_check(const char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!*s)
		error_and_exit();
	while (*s)
	{
		if (*s < '0' || *s > '9')
			error_and_exit();
		res = res * 10 + (*s - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && - res < INT_MIN))
			error_and_exit();
		s++;
	}
	return ((int)(res * sign));
}

int	is_duplicate(t_stack *stack, int value)
{
	t_node	*cur;

	cur = stack->top;
	while (cur)
	{
		if (cur->value == value)
			return (1);
		cur = cur->next;
	}
	return (0);
}

static char	*join_arguments(int argc, char **argv)
{
	char	*joined;
	char	*tmp;
	int		i;

	i = 1;
	joined = ft_strdup("");
	while (i < argc)
	{
		if (check_empty(argv[i]))
			error_and_exit();
		tmp = ft_strjoin(joined, argv[i]);
		free(joined);
		joined = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	return (joined);
}

void	fill_stack(t_stack *stack, int argc, char **argv)
{
	char	*joined;

	joined = join_arguments(argc, argv);
	parse_and_fill(stack, joined);
	free(joined);
}
