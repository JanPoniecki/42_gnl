/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:33:08 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/03 22:33:12 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_next_part(char *buffer, int fd)
{
	// static size_t	p;
	// size_t		i
	static int	p;
	int			i;
	int			check;
	char		c;

	i = 0;
	while (p < BUFFER_SIZE)
	{
		check = read(fd, &c, 1);
		if (!check)
			return (0);
		buffer[i] = c;
		if (c == '\n')
		{
			buffer[i + 1] = 0;
			return(1);
		}
		i++;
		p++;
	}
	return (1);
}