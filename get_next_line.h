/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:07:16 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/13 16:07:48 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

typedef struct data
{
	char	*remainder;
	char	buffer[BUFFER_SIZE + 1];
	char	*newline;
	char	*line;
	int		bytes_read;
}	t_data;

char	*get_next_line(int fd);

char	*ft_strchr(const char *s, int c);
char	*update_remainder(const char *new_line, char *old_remainder);
char	*ft_join(char *s1, char const *s2);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strlen(const char *s);
void	ft_cpy(char *res, char *s1, const char *s2);
void	*helper2(t_data *data);
void	little_helper(t_data *data);

#endif
