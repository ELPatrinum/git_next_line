/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 05:14:55 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/13 05:47:48 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_and_prepare(t_list *line_list)
{
	t_list	*last_element;
	t_list	*ready_element;
	int		i;
	int		j;
	char	*str;

	ready_element = malloc(sizeof(t_list));
	str = malloc(sizeof(BUFFER_SIZE) + 1);
	if (ready_element == NULL || str == NULL)
		return ;
	last_element = find_last(line_list);
	i = 0;
	while (last_element->content[i] && last_element->content[i] != '\n')
			i++;
	i++;
	j = 0;
	while (last_element->content[i])
			str[j++] = last_element->content[i++];
	str[j] = '\0';
	ready_element->content = str;
	ready_element->next = NULL;
	free_list(&line_list, ready_element, str);
}
char	*get_the_line(t_list *line_list)
{
	int		len;
	char	*str;

	if (line_list == NULL)
		return (NULL);
	len = line_len(line_list);
	str = malloc(sizeof(BUFFER_SIZE));
	if (str == NULL)
		return (NULL);
	make_line(line_list, str);
	return (str);
}
void	link_it(t_list **line_list, char *buffer)
{
	t_list *last_element;
	t_list *new_element;

	last_element = find_last(*line_list);
	new_element = malloc(sizeof(t_list));
	if (new_element == NULL)
		return;
	if (last_element == NULL)
		*line_list = new_element;
	else
	{
		last_element->next = new_element;
		new_element->content = buffer;
		new_element->next = NULL;
	}
}
void	make_the_list(t_list *line_list, int fd)
{
	char	*buffer;
	int		we_read;

	buffer = malloc(sizeof(BUFFER_SIZE) + 1);
	if (buffer == NULL)
		return;
	we_read = read(fd, buffer, BUFFER_SIZE);
	if (!we_read)
	{
		free(buffer);
		return;
	}
	buffer[we_read] = '\0';
	link_it(&line_list, buffer);
}

char	*get_next_line(int fd)
{
	static t_list	*line_list;
	char			*theline;

	if (fd < 0 || BUFFER_SIZE <= 0 || !read(fd, &make_the_list, 0))
		return (NULL);
	make_the_list(line_list, fd);
	if (line_list == NULL)
		return (NULL);
	theline = get_the_line(line_list);
	clean_and_prepare(line_list);
	return (theline);
}