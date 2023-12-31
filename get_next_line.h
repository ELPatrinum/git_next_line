/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:08:54 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/18 10:40:10 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*get_remains(char *remains);
char	*get_theline(char *str);
char	*read_from_fd(int fd, char *res);

int		ft_strlen(char *s, int j, char c);
int		new_line_check(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif