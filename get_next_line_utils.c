/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:47:30 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/13 05:44:45 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int	find_newline(t_list *line_list)
{
	int	i;

	if (line_list == NULL)
		return (0);
	while (line_list)
	{
		i = 0;
		while (line_list->content[i])
		{
			if (line_list->content[i] == '\n')
				return (1);
			i++;
		}
		line_list = line_list->next;
	}
	return (0);
}

t_list *find_last(t_list *line_list)
{
	if (line_list == NULL)
		return (NULL);
	while (line_list->next)
	{
		line_list = line_list->next;
	}
	return (line_list);
}

void	make_line(t_list *line_list, char *str)
{
	int	i;
	int	j;
	
	if (line_list == NULL)
		return ;
	i = 0;
	while (line_list)
	{
		j = 0;
		while (line_list->content[j] != '\0')
		{
			if (line_list->content[j] == '\n')
				{
					str[i] = '\n';
					i++;
					str[i] = '\0';
					return ;
				}
			str[i] = line_list->content[j];
			i++;
			j++;
		}
		line_list = line_list->next;
	}
	str[i] = '\0';
}

int	line_len(t_list *line_list)
{
	int	i;
	int	len;

	len = 0;
	while (line_list)
	{
		i = 0;
		while (line_list->content[i])
		{
			if (line_list->content[i] == '\n')
				{
					len++;
					return (len);
				}
			len++;
			i++;
		}
		line_list = line_list->next;
	}
	return (len);
}

void	free_list(t_list **line_list, t_list *ready_element, char *str)
{
	t_list	*temp;
	
	if (line_list == NULL)
		return ;
	while (*line_list)
	{
		temp = (*line_list)->next;
		free((*line_list)->content);
		free((*line_list));
		*line_list = temp;
	}
	if (ready_element->content[0])
		*line_list = ready_element;
	else
	{
		free(ready_element);
		free (str);
	}
	
}