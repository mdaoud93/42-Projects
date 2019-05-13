/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 14:26:41 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:36:21 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <limits.h>
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <libft.h>

# define RET_KEY		0xA
# define ESC_KEY		0x1B
# define SPCE_KEY		0x20
# define BCKSPCE_KEY	0x7F
# define UP_KEY			0x415B1B
# define DOWN_KEY		0x425B1B
# define RIGHT_KEY		0x435B1B
# define LEFT_KEY		0x445B1B
# define DEL_KEY		0x7E335B1B
# define HOME_KEY		0x485B1B
# define END_KEY		0x465B1B
# define CTRL_C			0x3
# define CTRL_Z			0x1A

# define REMOVED		0
# define NORMAL			1
# define UNDERLINED		2
# define SELECTED		4

# define COL_CYAN		"\033[36m"
# define COL_RES		"\033[00m"
# define COL_MAGENTA	"\033[35m"

/*
** Implementation of a doubly-linked list.
** status:	 0: Argument is deleted from the list (Does not show).
**			 1: Argument is neither pointed at nor selected.
**			 2: Argument is pointed at (Underlined).
**			 4: Argument is selected (Reverse video).
** name: Name of the argument.
*/
struct					s_list
{
	int					status;
	char				name[NAME_MAX];
	struct s_list		*prev;
	struct s_list		*next;
};

/*
** Our main structure.
** @max_arg_len:	Lngth of the longest argument name.
** @argc:			Number of arguments.
** @win_height:		Height of the terminal window.
** @win_width:		Width of the terminal window.
** @col_count:		Number of output columns.
** @row_count:		Number of output rows.
** @lst:	 		A doubly-linked circular list containing program arguments.
** @term:	 		Our current termios structure.
** @oldterm:		Original termios structure.
**	 (we store it to restore the original termios configuration at the end).
*/
struct					s_select
{
	int					fd;
	size_t				max_arg_len;
	size_t				argc;
	size_t				win_width;
	size_t				win_height;
	size_t				col_count;
	size_t				row_count;
	size_t				selected_arg_count;
	struct s_list		*lst;
	struct termios		*term;
	struct termios		*oldterm;
};

typedef struct termios	t_termios;
typedef struct s_list	t_list;
typedef struct s_select	t_select;

/*
** Our global variable, for better signal handling.
*/
t_select				*g_sel;

t_list					*lst_del(t_list *rmv);
t_list					*lst_append(t_list *lst, char *name);
void					ft_exit(char *message, int to_free, int exit_value);
void					restore_default_conf(void);
int						tputs_char(int c);
void					display_list(void);
void					display_status(void);
t_list					*get_cursor_pos(void);
void					detect_key_presses(void);
void					free_select(void);
int						process_keypress(unsigned int key_val);
void					keypress_space(void);
void					keypress_right(void);
void					keypress_left(void);
void					keypress_up(void);
void					keypress_down(void);
void					keypress_del(void);
void					keypress_home(void);
void					display_selected();
void					keypress_end(void);
void					init_signal_handlers(void);
void					init_term(void);

#endif
