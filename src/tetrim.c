/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:43:02 by jlepere           #+#    #+#             */
/*   Updated: 2015/12/16 15:49:19 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>

t_tetrim	*create_tetrim(void)
{
	int			c;
	t_tetrim	*tetrim;

	c = -1;
	tetrim = (t_tetrim*)malloc(sizeof(t_tetrim));
	while (++c < 16)
		tetrim->data[c / 4][c % 4] = 0;
	tetrim->next = NULL;
	tetrim->index = 65;
	return (tetrim);
}

int			count_tetrim(t_tetrim *tetrim)
{
	int			c;
	t_tetrim	*t;

	c = 0;
	t = tetrim;
	while (t)
	{
		t = t->next;
		c++;
	}
	return (c);
}

void		add_tetrim(t_tetrim *tetrim)
{
	t_tetrim	*new_tetrim;

	new_tetrim = create_tetrim();
	tetrim->next = new_tetrim;
	tetrim->next->index = tetrim->index + 1;
}

static void	move_data(t_tetrim *tetrim, int data[6][6])
{
	int	c;
	int	y;
	int	i;

	i = 0;
	c = -1;
	y = -1;
	while (++c < 16)
	{
		if (data[c / 4 + 1][c % 4 + 1] == '#')
		{
			if (y == -1)
				y = c / 4;
			data[c / 4 + 1][c % 4 + 1] = '.';
			data[c / 4 + 1 - y][c % 4 + 1] = '#';
			tetrim->data[i][0] = c / 4 - y;
			tetrim->data[i][1] = c % 4;
			i++;
		}
	}
}

int			is_valid(t_tetrim *tetrim, int data[6][6])
{
	int	c;
	int	x;
	int	link;

	c = -1;
	x = -1;
	link = 0;
	while (++c < 16)
	{
		if (data[c % 4 + 1][c / 4 + 1] == '#')
		{
			if (data[c % 4 + 1][c / 4 + 2] == '#')
				link++;
			if (data[c % 4 + 2][c / 4 + 1] == '#')
				link++;
			if (x == -1)
				x = c / 4;
			data[c % 4 + 1][c / 4 + 1] = '.';
			data[c % 4 + 1][c / 4 + 1 - x] = '#';
		}
	}
	move_data(tetrim, data);
	if (link < 3)
		return (-1);
	return (0);
}
