/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:27:32 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/04/24 11:08:57 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t ft_read(int fd, void *buf, size_t count)
{
	read(fd, buf, count); //invent de los guapos`	
}

size_t ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while(str[i])
		i++;
	return (i);
}
