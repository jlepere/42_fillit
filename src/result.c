/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:16:35 by jlepere           #+#    #+#             */
/*   Updated: 2015/12/22 15:25:35 by mfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>

t_result		*create_result(void)
{
	int			c;
	t_result	*result;

	c = -1;
	result = (t_result*)malloc(sizeof(t_result));
	result->size = 2;
	result->next = NULL;
	while (++c < (15 * 15))
		result->map[c / 15][c % 15] = 0;
	return (result);
}

static t_result	*add_result(t_result *res, t_result *tmp, int size)
{
	tmp->size = size;
	res = tmp;
	return (res);
}

static t_result	*new_result(t_result *r, t_tetrim *t, t_result *res)
{
	int	size;

	size = r->size;
	free(r);
	if (t->index == 'A' && !res)
	{
		r = create_result();
		r->size = size + 1;
		res = algo_result(r, t, res);
	}
	return (res);
}

t_result		*algo_result(t_result *r, t_tetrim *t, t_result *res)
{
	int			x;
	int			y;
	t_result	*tmp;

	x = -1;
	y = -1;
	while (++x < r->size)
	{
		while (++y < r->size)
		{
			if (is_exist(r, t, x, y))
			{
				tmp = place_tetrim(r, t, x, y);
				if (t->next)
					res = algo_result(tmp, t->next, res);
				else if (!t->next)
					return (add_result(res, tmp, r->size));
				if (res)
					return (res);
			}
		}
		y = -1;
	}
	return (new_result(r, t, res));
}

void			view_result(t_result *r)
{
	int	c;

	c = -1;
	while (++c < (r->size * r->size))
	{
		if (r->map[c / r->size][c % r->size] == 0)
			ft_putchar('.');
		else
			ft_putchar(r->map[c / r->size][c % r->size]);
		if (c % r->size == r->size - 1)
			ft_putchar('\n');
	}
}
