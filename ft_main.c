/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:43:16 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/05/01 14:12:26 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"
#include <fcntl.h>

#include "ft_get_next_line.h"
#include <fcntl.h>
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("fd1.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
		return (1);
	}
	printf("%d \n", fd);
	line = get_next_line(fd);
	while ((line) != NULL && *line != '\0')
	{
		printf("%s\n", line);
		if (*line == '\0')
		{
			free(line);
			break ;
		}
		free(line);
	}
	close(fd);
	printf("yeaaaah");
	return (0);
}
*/
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("fd3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
