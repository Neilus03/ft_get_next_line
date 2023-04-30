/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:26:34 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/04/27 09:12:31 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	newline = ft_strchr(buf, '\n');
	while (newline == NULL)
	{
		bytes_read = read_buffer(fd, &buf);
		if (bytes_read <= 0)
			break ;
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
