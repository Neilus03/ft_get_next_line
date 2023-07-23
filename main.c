/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:49:44 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/07/23 11:42:15 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:49:44 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/06/23 14:11:27 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		i = 1;
	int		fd1;

	fd1 = open("/Users/nde-la-f/Documents/42/C_Cursus/GET_NEXT_LINE/GNL/tests/fd_strange_characters.txt", O_RDONLY);
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

/*
REMEMBER TO NOT DELIVER THIS BCS EVEN IF MOULINETTE ACCEPTS IT SOME PEOPLE IN CAMPUS DON´T. (UGH)
*/