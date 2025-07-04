/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:02:48 by nsahakya          #+#    #+#             */
/*   Updated: 2025/07/04 12:17:28 by nsahakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

char	*ft_get_line(char **line);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*f_strchr(const char *s, int c);
char	*f_strjoin(char *s1, char *s2);
char	*f_substr(char *s, unsigned int start, size_t len);

#endif
