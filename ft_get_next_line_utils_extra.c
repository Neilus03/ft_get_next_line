/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils_extra.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:53:06 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/04/30 12:25:24 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	dst = (char *)malloc(len * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, len);
	return (dst);
}

ssize_t	read_buffer(int fd, char **buffer)
{
	char	tmp_buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*new_buffer;

	bytes_read = read(fd, tmp_buf, BUFFER_SIZE);
	if (bytes_read < 0)
		return (-1);
	if (bytes_read > 0)
	{		
		tmp_buf[bytes_read] = '\0';
		new_buffer = ft_strjoin(*buffer, tmp_buf);
		if (new_buffer == NULL)
		{
			free(*buffer);
			return (-1);
		}
		free(*buffer);
		*buffer = new_buffer;
	}
	return (bytes_read);
}
