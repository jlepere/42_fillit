/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:18:23 by jlepere           #+#    #+#             */
/*   Updated: 2015/12/22 15:21:29 by mfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>

static int	myexit(void)
{
	ft_putendl("error");
	return (0);
}

int			main(int ac, char **av)
{
	t_tetrim	*tetrim;
	t_result	*result;
	t_result	*final;

	if (ac != 2)
		return (myexit());
	tetrim = create_tetrim();
	if (open_file(tetrim, av[1]))
		return (myexit());
	result = create_result();
	final = NULL;
	final = algo_result(result, tetrim, final);
	view_result(final);
	free(final);
	free(tetrim);
	return (0);
}
