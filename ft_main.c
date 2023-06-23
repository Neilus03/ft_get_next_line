/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:46:58 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/06/23 10:51:06 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"
#include <fcntl.h>

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
