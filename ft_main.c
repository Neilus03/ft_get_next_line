/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:43:16 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/05/01 15:03:35 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("tests/fd3.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
		return (1);
	}
	i = 0;
	while (i < 10)
	{
		line = get_next_line(fd);
		printf("line[%d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	printf("\narrived till the end\n");
	return (0);
}
