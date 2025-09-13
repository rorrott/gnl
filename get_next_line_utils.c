/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:52:25 by rtorres           #+#    #+#             */
/*   Updated: 2024/06/13 11:13:55 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&((char *)str)[i]);
		i++;
	}
	if ((char) c == '\0')
		return (&((char *)str)[i]);
	return (0);
}

char	*ft_substr(char *str, unsigned int start, size_t size)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!str)
		return (0);
	if (start > ft_strlen(str))
	{
		res = malloc(sizeof(char) * (1));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(str) - start < size)
		size = ft_strlen(str) - start;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (start < ft_strlen(str) && i < size && str[start])
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!str1)
	{
		str1 = malloc(sizeof(char) + 1);
		if (!str1)
			return (0);
		str1[0] = 0;
	}
	ptr = (char *)malloc(sizeof(char) * ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!ptr)
		return (ft_free(&str1));
	while (str1[++i])
		ptr[i] = str1[i];
	j = -1;
	while (str2[++j])
		ptr[i + j] = str2[j];
	ptr[i + j] = '\0';
	free(str1);
	return (ptr);
}
