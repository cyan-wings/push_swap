/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_get_next_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:23:34 by myeow             #+#    #+#             */
/*   Updated: 2024/04/07 00:13:33 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"
#include <unistd.h>

t_error	ps_checker_get_next_line(int fd, char *line)
{
	int		i;
	char	c;
	int		read_bytes;

	i = 0;
	c = 0;
	while (c != '\n')
	{
		read_bytes = read(fd, &c, 1);
		if (read_bytes == -1)
			return (PARSE_ERROR);
		if (read_bytes == 0)
			break ;
		line[i++] = c;
		if (i > 4)
			return (PARSE_ERROR);
	}
	if ((i > 0 && line[i - 1] != '\n') || line[0] == '\n')
		return (PARSE_ERROR);
	if (read_bytes == 0)
		line[0] = 0;
	else
		line[i - 1] = 0;
	return (OK);
}
