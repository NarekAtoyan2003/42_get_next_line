/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naatoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:59:04 by naatoyan          #+#    #+#             */
/*   Updated: 2024/02/25 19:47:54 by naatoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl(char	*buffer, int fd)
{
	int		i;
	char	d_b[BUFFER_SIZE + 1];

	i = -1;
	while (++i <= BUFFER_SIZE)
		d_b[i] = '\0';
	i = 1;
	while (!ft_strchr(d_b, '\n') && i)
	{
		i = read(fd, d_b, BUFFER_SIZE);
		if (i < 0 || (!i && !buffer))
			return (00);
		d_b[i] = '\0';
		if (!buffer)
			buffer = ft_strdup(d_b);
		else
			buffer = ft_strjoin(buffer, d_b);
		if (!buffer)
			return (00);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*d_b;
	char		*dest;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (00);
	buffer = gnl(buffer, fd);
	if (!buffer)
		return (00);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	dest = ft_substr(buffer, 0, i);
	d_b = ft_substr(buffer, i, ft_strlen(buffer) - i);
	free(buffer);
	buffer = d_b;
	return (dest);
}
