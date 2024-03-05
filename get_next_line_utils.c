/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:33:08 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/05 17:29:42 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	search_end_file(char *buffer, int i)
{
	static int	end;

	if (end == 0)
	{
		end = 1;
		buffer[i] = 0;
		return (1);
	}
	else
		return(0);
}

int	read_next_part(char *buffer, int fd)
{
	// size_t		i
	int			i;
	int			check;
	char		c;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		check = read(fd, &c, 1);
		if (!check)
			return (search_end_file(buffer, i));
		buffer[i] = c;
		if (c == '\n')
		{
			if (i + 1 == BUFFER_SIZE)
				return (0);
			buffer[i + 1] = 0;
			return(1);
		}
		i++;
	}
	return (0);
}
