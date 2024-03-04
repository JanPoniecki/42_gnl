/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:08:46 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/03 21:08:49 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	if (read_next_part(buffer, fd) != 0)
		return (buffer);
	else
		return (NULL);
}
