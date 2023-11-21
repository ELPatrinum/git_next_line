/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:07:35 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/18 10:40:57 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_from_fd(int fd, char *remains)
{
	char		*buff;
	long long	size;

	size = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(remains), NULL);
	while (size > 0 && !new_line_check(remains))
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == 0)
			break ;
		if (size == -1)
		{
			free(buff);
			free(remains);
			return (NULL);
		}
		buff[size] = '\0';
		remains = ft_strjoin(remains, buff);
	}
	free(buff);
	return (remains);
}

char	*get_theline(char *str)
{
	int		i;
	char	*line;

	if (!*str)
		return (NULL);
	line = malloc((ft_strlen(str, 0, '\n') + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_remains(char *remains)
{
	char	*new_remains;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!remains)
		return (free(remains), NULL);
	while (remains[i] && remains[i] != '\n')
		i++;
	if (!remains[i])
	{
		free(remains);
		return (NULL);
	}
	new_remains = malloc((ft_strlen(remains, i, '\0')) * sizeof(char));
	if (!new_remains)
		return (free(remains), NULL);
	i++;
	while (remains[i])
		new_remains[j++] = remains[i++];
	new_remains[j] = '\0';
	free(remains);
	return (new_remains);
}

char	*get_next_line(int fd)
{
	static char	*remains[OPEN_MAX];
	char		*theline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remains[fd] = read_from_fd(fd, remains[fd]);
	if (!remains[fd])
		return (NULL);
	theline = get_theline(remains[fd]);
	if (!theline)
		return (free(remains[fd]), remains[fd] = NULL, NULL);
	remains[fd] = update_remains(remains[fd]);
	return (theline);
}
