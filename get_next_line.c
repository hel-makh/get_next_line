/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:56:01 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/11 10:56:02 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

static int	add_next_line(int fd, char **next_line)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*has_newline;
	int			ret;
	size_t		len;

	if (!*buffer)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		if (ret < 1)
			return (0);
	}
	has_newline = ft_strchr(buffer, '\n');
	len = ft_strlen(buffer);
	if (has_newline)
		len += 1 - ft_strlen(has_newline);
	*next_line = ft_strnjoin(*next_line, buffer, len);
	ft_strcpy(buffer, buffer + len);
	if (has_newline)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	char	*next_line;

	next_line = (char *) malloc (1 * sizeof(char));
	if (next_line == NULL)
		return (0);
	*next_line = '\0';
	while (add_next_line(fd, &next_line))
		;
	if (!*next_line)
		next_line = ft_free(next_line);
	return (next_line);
}
