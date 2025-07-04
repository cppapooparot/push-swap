/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:55:22 by nsahakya          #+#    #+#             */
/*   Updated: 2025/07/04 14:12:28 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_BONUS_H
# define STACK_BONUS_H

# include "../../libft/libft.h"
# include "get_next_line.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Stack node
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

// Stack
typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

// Stack core operations
t_node				*create_node(int value);
t_stack				*init_stack(void);
void				push_top(t_stack *stack, t_node *node);
void				push_bottom(t_stack *stack, t_node *node);
t_node				*pop_top(t_stack *stack);
t_node				*pop_bottom(t_stack *stack);
void				free_stack(t_stack *stack);
void				print_stack(t_stack *stack, const char *name);
void				print_stack_indexes(t_stack *stack, const char *name);

// Sorting stack operations
void				swap(t_stack *stack);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

void				push(t_stack *source, t_stack *dest);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

void				rotate(t_stack *stack);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

void				reverse_rotate(t_stack *stack);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

// Parsing
int					is_number(const char *s);
int					atoi_with_limit_check(const char *s);
int					is_duplicate(t_stack *stack, int value);
void				fill_stack(t_stack *stack, int argc, char **argv);

// Sorting logic
void				sort_two(t_stack *a);
int					is_sorted(t_stack *stack);
void				sort_three(t_stack *stack);
void				sort_four(t_stack *a, t_stack *b);
int					find_min_pos(t_stack *stack);
void				push_min_to_b(t_stack *a, t_stack *b);
void				sort_five(t_stack *a, t_stack *b);
void				index_stack(t_stack *stack);
void				radix_sort(t_stack *a, t_stack *b);
void				butterfly_sort(t_stack *a, t_stack *b);

// Utils
void				error_and_exit(void);
int					splitted_len(char **splitted);
int					check_empty(char *string);
void				free_splitted(char **splitted);
void				parse_and_fill(t_stack *stack, char *joined);
void				free_stack(t_stack *stack);
void				fill_stack(t_stack *stack, int argc, char **argv);
char				*join_arguments(int argc, char **argv);
#endif
