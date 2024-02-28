/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naatoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:10:33 by naatoyan          #+#    #+#             */
/*   Updated: 2024/02/28 13:58:07 by naatoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*buffer[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (00);
	buffer[fd] = gnl(buffer[fd], fd);
	if (!buffer[fd])
		return (00);
	i = 0;
	while (buffer[fd][i] && buffer[fd][i] != '\n')
		i++;
	if (buffer[fd][i] == '\n')
		i++;
	dest = ft_substr(buffer[fd], 0, i);
	d_b = ft_substr(buffer[fd], i, ft_strlen(buffer[fd]) - i);
	free(buffer[fd]);
	buffer[fd] = d_b;
	return (dest);
}
