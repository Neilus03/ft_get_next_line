/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:26:34 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/06/23 10:51:09 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

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
/*
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("tests/fd3.txt", O_RDONLY);
	i = 1;
	line = get_next_line(fd1);
	while (line != NULL)
	{
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
		line = get_next_line(fd1);
	}
	close(fd1);
	return (0);
}
*/
/*
This was my previous GNL file before splitting it up in 2
parts for meeting the 25 line criteria


#include "ft_get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	ssize_t		bytes_read;
	char		*newline;
	char		*result;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!buf)
		buf = ft_strdup("");
	if (!buf)
		return (NULL);
	newline = ft_find_char(buf, '\n');
	while (newline == NULL)
	{
		bytes_read = read_buffer(fd, &buf);
		if (bytes_read <= 0)
			break ;
		newline = ft_find_char(buf, '\n');
	}
	if (newline)
	{
		result = ft_substr(buf, 0, newline - buf);
		tmp = ft_strdup(newline + 1);
		free(buf);
		buf = tmp;
	}
	else
	{
		result = ft_strdup(buf);
		free(buf);
		buf = NULL;
	}
	return (result);
}
*/
