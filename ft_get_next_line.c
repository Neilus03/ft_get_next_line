/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:26:34 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/06/23 11:29:23 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

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
	{	
		write(1, "Error Reading\n", 13);
		return (-1);
	}
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

char	*process_buffer(char **buf, char *newline)
{
	char	*result;
	char	*tmp;

	if (newline)
	{
		result = ft_substr(*buf, 0, newline - *buf);
		tmp = ft_strdup(newline + 1);
		free(*buf);
		*buf = tmp;
	}
	else
	{
		result = ft_strdup(*buf);
		free(*buf);
		*buf = NULL;
		if (!result || *result == '\0')
		{
			free(result);
			return (NULL);
		}
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	ssize_t		bytes_read;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		return (NULL);
	}
	if (!buf)
		buf = ft_strdup("");
	if (!buf)
	{
		return (NULL);
	}
	newline = ft_find_char(buf, '\n');
	while (newline == NULL)
	{
		bytes_read = read_buffer(fd, &buf);
		if (bytes_read <= 0)
			break ;
		newline = ft_find_char(buf, '\n');
	}
	return (process_buffer(&buf, newline));
}
