/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:26:34 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/04/30 13:13:26 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

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
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	ssize_t		bytes_read;
	char		*newline;

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
	return (process_buffer(&buf, newline));
}

/*
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("tests/fd1.txt");
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
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
