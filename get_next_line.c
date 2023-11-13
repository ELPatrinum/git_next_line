/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:00:30 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/13 16:41:59 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

void	*helper2(t_data *data)
{
	data->line = malloc(data->newline - data->remainder + 1 + 1);
	data->line[data->newline - data->remainder] = '\0';
	if (!data->line)
		return (NULL);
	ft_strncpy(data->line, data->remainder,
		data->newline - data->remainder + 1);
	data->remainder = update_remainder(data->newline + 1,
			data->remainder);
	if (!data->remainder)
		return (NULL);
	return (data->line);
}

char	*helper1(t_data *data, int fd)
{
	data->bytes_read = read(fd, data->buffer, BUFFER_SIZE);
	while (data->bytes_read >= 0)
	{
		data->buffer[data->bytes_read] = '\0';
		data->remainder = ft_join(data->remainder, data->buffer);
		if (!data->remainder)
			return (NULL);
		data->newline = ft_strchr(data->remainder, '\n');
		if (data->newline)
		{
			if (!helper2(data))
				return (NULL);
			return (data->line);
		}
		else if (!data->bytes_read && !data->remainder[0])
			break ;
		else if (!data->bytes_read)
		{
			data->line = update_remainder(data->remainder, data->remainder);
			data->remainder = NULL;
			return (data->line);
		}
		data->bytes_read = read(fd, data->buffer, BUFFER_SIZE);
	}
	free(data->remainder);
	data->remainder = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_data	data;

	if (!BUFFER_SIZE || fd == -1)
		return (NULL);
	return (helper1(&data, fd));
}
