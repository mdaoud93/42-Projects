/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:37:46 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/03 09:51:11 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

# include <inttypes.h>

typedef struct		s_point
{
	int			x;
	int			y;
}					t_point;

t_point				*create_point(int x, int y);
int					on_board(int dim, t_point *point);
void				shift_point(int dim, t_point *point);
void				print_point(t_point *point);

#endif
