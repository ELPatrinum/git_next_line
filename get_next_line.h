/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 05:15:04 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/13 05:23:47 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define  BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char 	*get_next_line(int fd);
int		find_newline(t_list *line_list);
t_list 	*find_last(t_list *line_list);
void	link_it(t_list **line_list, char *buffer);
void	make_the_list(t_list *line_list, int fd);
char	*get_the_line(t_list *line_list);
void	make_line(t_list *line_list, char *str);
int		line_len(t_list *line_list);
void	clean_and_prepare(t_list *line_list);
void	free_list(t_list **line_list, t_list *ready_element, char *str);

#endif
