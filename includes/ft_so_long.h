/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:35:34 by jolopez-          #+#    #+#             */
/*   Updated: 2023/07/26 18:21:38 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# define SPRITE_H				32
# define SPRITE_W				32
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17
# define A_KEY					0
# define S_KEY					1
# define D_KEY					2
# define W_KEY					13
# define ESC 					53

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "./42_libft/libft.h"
# include "./42_GNL/get_next_line.h"

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_img
{
	void		*img;
	t_vector	*size;
	t_vector	*pos;
}	t_img;

typedef struct s_map
{
	char		**map;
	t_vector	*size;
}	t_map;

typedef struct s_game
{
	int			collects;
	int			steps;
	int			enemies;
}	t_game;

typedef struct s_status
{
	void		*mlx;
	void		*win;
	t_game		*game;
	t_map		*map;
	t_img		*img;
	t_img		*enemy;
}			t_status;

//	File map_tester.c
//	static int	ft_walls_tester(t_status *status);
//	static int	ft_sprites_tester(t_status *status, char PEC);
//	static int	ft_chars_tester(t_status *status);
//	int			ft_map_tester(t_status *status);
int				ft_map_tester(t_status *status);

//	File map_tools.c
int				ft_get_map_dim(t_status *status, char **argv);
void			ft_get_map_dim_aux(int fd, char *line, t_status *status);
int				ft_get_map(t_status *status, char **argv);
int				ft_print_map(t_status *status);
int				ft_load_map(t_status *s, int row, int col);

//	File mem.c
int				ft_mem_allocation(t_status **status);
void			ft_mem_free(t_status **status);

//	File movements.c
//	static int	move_left(t_status *status);
//	static int	move_right(t_status *status);
//	static int	move_down(t_status *status);
//	static int	move_up(t_status *status);
int				ft_movements(int key, t_status *s);

//	File print.c
int				ft_error(int code, char *text, t_status *status);
int				ft_mem_error(int code, t_status *status);
int				ft_map_error(int code, char *text, t_status *status);
int				ft_exit(t_status *status, char *text);
int				ft_print_steps(t_status *s);

//	File so_long.c
//	static int	ft_vars_init(t_status *status);
//	static int	ft_arguments_tester(int argc, char **argv);
//	static int	ft_player_init_position(t_status *status);
//	static int	ft_expose(t_status *status);
int				main(int argc, char **argv);

//	File tools.c
int				ft_count_items(t_status *status, char item);
int				ft_key_press(int key, t_status *status);
int				ft_exit_found(t_status *status);
int				ft_mlx_close(t_status *status);
int				ft_check_collects(t_status *status);

#endif
