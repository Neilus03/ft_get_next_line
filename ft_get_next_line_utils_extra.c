/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils_extra.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:53:06 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/04/30 14:06:14 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t len_dst)
{
	size_t	i;

	i = 0;
	if (len_dst <= 0)
		return (ft_strlen(src));
	while ((i < len_dst - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	i = 0;
	if (size < dst_len)
		return (ft_strlen(src) + size);
	while (size > 0 && dst_len < size - 1 && src[i])
	{
		dst[dst_len++] = src[i++];
	}
	dst[dst_len] = '\0';
	while (src[i++])
		dst_len++;
	return (dst_len);
}

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
	if (ft_strlcpy(dst, s1, len) < len)
		return (NULL);
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
