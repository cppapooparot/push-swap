/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:55:46 by nsahakya          #+#    #+#             */
/*   Updated: 2025/06/30 13:48:37 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	is_empty(const char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] != ' ' && string[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	check_empty(char *string)
{
	if (!string || string[0] == '\0' || is_empty(string))
		return (1);
	return (0);
}

int	splitted_len(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		i++;
	return (i);
}

void	free_splitted(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}
