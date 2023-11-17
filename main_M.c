/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_M.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:59:04 by muel-bak          #+#    #+#             */
/*   Updated: 2023/11/17 18:05:07 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		indx;

	indx = 1;
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%d==>%s", indx, line);
		free(line);
		indx++;
		line = get_next_line(fd);
	}
	printf("\n");
	sleep(100);
	return (0);
}
