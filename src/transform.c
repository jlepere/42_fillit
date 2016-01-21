/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:31:28 by jlepere           #+#    #+#             */
/*   Updated: 2015/12/18 11:54:26 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			is_exist(t_result *r, t_tetrim *t, int x, int y)
{
	if (t->data[0][0] + x >= r->size || t->data[0][1] + y >= r->size ||
		t->data[1][0] + x >= r->size || t->data[1][1] + y >= r->size ||
		t->data[2][0] + x >= r->size || t->data[2][1] + y >= r->size ||
		t->data[3][0] + x >= r->size || t->data[3][1] + y >= r->size)
		return (0);
	if (!r->map[t->data[0][0] + x][t->data[0][1] + y] &&
			!r->map[t->data[1][0] + x][t->data[1][1] + y] &&
			!r->map[t->data[2][0] + x][t->data[2][1] + y] &&
			!r->map[t->data[3][0] + x][t->data[3][1] + y])
		return (1);
	return (0);
}

t_result	*place_tetrim(t_result *r, t_tetrim *t, int x, int y)
{
	int			c;
	int			size;
	t_result	*next;

	c = -1;
	size = r->size;
	next = create_result();
	next->size = size;
	while (++c < (size * size))
		if (r->map[c / size][c % size] != 0)
			next->map[c / size][c % size] = r->map[c / size][c % size];
	c = -1;
	while (++c < 4)
		next->map[t->data[c][0] + x][t->data[c][1] + y] = t->index;
	return (next);
}
