/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:23:37 by jlepere           #+#    #+#             */
/*   Updated: 2015/12/22 15:24:34 by mfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		open_file(t_tetrim *t, char const *file)
{
	int			fd;
	char		*data;

	data = (char*)malloc(sizeof(char));
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	if (parse_file(t, fd, data) == -1)
		return (-1);
	return (0);
}

int		parse_file(t_tetrim *t, int fd, char *data)
{
	char		last;
	t_buffer	*buffer;
	int			i;

	i = 0;
	buffer = create_buffer();
	while ((read(fd, data, 1)) > 0)
	{
		if ((i == 20 || i == 21) && (last == '\n' &&
					data[0] == '\n' && parse_buffer(buffer, t, 0)))
			return (-1);
		else if ((i == 20 || i == 21) && last == '\n' &&
				data[0] == '\n' && (t = t->next) != NULL)
		{
			buffer = reset_buffer(buffer);
			i = 0;
		}
		add_buffer(buffer, data[0]);
		last = data[0];
		i++;
	}
	if ((i != 21 && i != 20) || (parse_buffer(buffer, t, 1) || close(fd)))
		return (-1);
	free(buffer);
	return (0);
}

int		parse_buffer(t_buffer *buffer, t_tetrim *tetrim, int last)
{
	int	count_d;
	int	count_s;
	int	data[6][6];

	count_d = 0;
	count_s = 0;
	while (*buffer->data)
	{
		if (*buffer->data == '#' || *buffer->data == '.')
		{
			if (*buffer->data == '#')
				count_d++;
			data[count_s / 4 + 1][count_s % 4 + 1] = *buffer->data++;
			count_s++;
		}
		else if (*buffer->data == '\n' && !(count_s % 4))
			buffer->data++;
		else
			return (-1);
	}
	if (count_s != 16 || count_d != 4 || is_valid(tetrim, data))
		return (-1);
	if (!last)
		add_tetrim(tetrim);
	return (0);
}
