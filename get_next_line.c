/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:08:46 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/08 14:22:13 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*buffer;
	char	*res;

	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	res = read_buffer(buffer);
	free(buffer);
	return(res);
}
