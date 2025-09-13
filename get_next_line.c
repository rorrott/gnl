/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:27:17 by rtorres           #+#    #+#             */
/*   Updated: 2024/06/20 15:24:52 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **string)
{
	free(*string);
	*string = NULL;
	return (NULL);
}

char	*clean_stash(char *stash)
{
	char	*new_stash;
	char	*str;
	int		len;

	str = ft_strchr(stash, '\n');
	if (!str)
	{
		new_stash = NULL;
		return (ft_free(&stash));
	}
	else
		len = (str - stash) + 1;
	if (!stash[len])
		return (ft_free(&stash));
	new_stash = ft_substr(stash, len, ft_strlen(stash) - len);
	ft_free(&stash);
	if (!new_stash)
		return (NULL);
	return (new_stash);
}

char	*ft_get_new_line(char *stash)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(stash, '\n');
	len = (ptr - stash) + 1;
	line = ft_substr(stash, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_buffer(int fd, char *stash)
{
	int		read_bytes;
	char	*buffer;

	read_bytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&stash));
	buffer[0] = '\0';
	while (read_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buffer[read_bytes] = '\0';
			stash = ft_strjoin(stash, buffer);
		}
	}
	free(buffer);
	if (read_bytes == -1)
		return (ft_free(&stash));
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if ((stash && !ft_strchr(stash, '\n')) || !stash)
		stash = read_buffer(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_new_line(stash);
	if (!line)
		return (ft_free(&stash));
	stash = clean_stash(stash);
	return (line);
}
