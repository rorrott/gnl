/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:24:02 by rtorres           #+#    #+#             */
/*   Updated: 2024/06/19 15:40:59 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, int c);
char	*ft_substr(char *str, unsigned int start, size_t size);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_free(char **string);
char	*clean_stash(char *stash);
char	*ft_get_new_line(char *stash);
char	*read_buffer(int fd, char *stash);
char	*get_next_line(int fd);

#endif