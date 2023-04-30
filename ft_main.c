/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:43:16 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/04/30 14:00:15 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("fd3.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
		return (1);
	}
	printf("%d \n", fd);
	line = get_next_line(fd);
	printf("%s \n", line);
	while (line)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	printf("yeah");
	return (0);
}
