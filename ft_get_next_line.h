/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:28:01 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/04/24 10:52:11 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
ssize_t	ft_strlen(char *str);

#endif //GET_NEXT_LINE_H

