/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:32:19 by jlepere           #+#    #+#             */
/*   Updated: 2015/12/19 16:10:10 by mfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

typedef struct		s_tetrim
{
	int				index;
	int				data[4][2];
	struct s_tetrim	*next;
}					t_tetrim;

typedef struct		s_result
{
	int				size;
	int				map[15][15];
	struct s_result	*next;
}					t_result;

int					open_file(t_tetrim *t, char const *file);
int					parse_file(t_tetrim *tetrim, int fd, char *data);
int					parse_buffer(t_buffer *buffer, t_tetrim *tetrim, int last);

t_tetrim			*create_tetrim(void);
int					count_tetrim(t_tetrim *tetrim);
void				add_tetrim(t_tetrim *tetrim);
int					is_valid(t_tetrim *tetrim, int data[6][6]);

t_result			*create_result(void);
t_result			*algo_result(t_result *r, t_tetrim *t, t_result *res);
void				view_result(t_result *result);

int					is_exist(t_result *r, t_tetrim *t, int x, int y);
t_result			*place_tetrim(t_result *r, t_tetrim *t, int x, int y);

#endif
