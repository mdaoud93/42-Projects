/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:43:21 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/08 16:06:36 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include "ft_point.h"
# include "../libft/includes/libft.h"

# define MAX_TETRIMINIO 26
# define READ_BUFF_SIZE 21
# define DIM 4

typedef struct		s_tetri
{
	int			width;
	int			height;
	t_point		*start;
	int			**shape;
}					t_tetri;

int					**create_board(int dimension);
int					**ft_malloc_2d(int height, int width);
int					can_place(int **board, int dim, t_tetri *t, t_point *pos);
int					place_tetri(int **board, int dim, t_tetri *t, t_point *pos);
int					remove_tetri(int **board, t_tetri *tetri);
int					solve_board(int **board, int dim, t_tetri **t, int ind);
int					solve(t_tetri **tetris, int count);
int					ceil_sqrt(int nb);
int					newline(int fd);
int					valid_tetris(int array[DIM][DIM]);
int					valid_input(char *str);
int					is_empty_col(int col, int array[DIM][DIM]);
int					is_empty_row(int row, int array[DIM][DIM]);
void				ft_exit(void);
void				print_board(int dim, t_tetri **tetris);
void				ft_usage();
void				free_board(char ***board, int dim);
void				free_tetri_array(t_tetri **tetris);
t_tetri				**input(int fd, int *count);
t_tetri				*create_tetris(char *str);

#endif
