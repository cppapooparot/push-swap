/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:01:52 by nsahakya          #+#    #+#             */
/*   Updated: 2025/07/04 12:18:57 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char **line)
{
	char	*next_line;
	char	*new_line;
	int		i;

	i = 0;
	if (!(*line) || !**line)
		return (NULL);
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	if ((*line)[i] == '\n')
		i++;
	next_line = f_substr(*line, 0, i);
	new_line = f_substr(*line, i, ft_strlen(*line) - i);
	if (!new_line || !*new_line)
	{
		free(new_line);
		new_line = NULL;
	}
	free(*line);
	*line = new_line;
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		buff[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (line == NULL || !f_strchr(line, '\n'))
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		line = f_strjoin(line, buff);
		if (!line)
			return (NULL);
	}
	return (ft_get_line(&line));
}
