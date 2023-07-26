/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:51:41 by marvin            #+#    #+#             */
/*   Updated: 2023/07/26 18:22:30 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long_bonus.h"

static int	ft_vars_init(t_status *status)
{
	status->animation = 0;
	status->previous = 'r';
	status->game->steps = 0;
	status->game->enemies = 0;
	status->game->collects = 0;
	status->enemy->pos->x = 0;
	status->enemy->pos->y = 0;
	status->img->size->x = 0;
	status->img->size->y = 0;
	return (0);
}

static int	ft_arguments_tester(int argc, char **argv, t_status *status)
{
	if (argc < 2)
		ft_error(EXIT_FAILURE, "No map (.ber) as argument.", status);
	if (argc > 2)
	{
		ft_error(EXIT_FAILURE, "Use just one .ber map as argument!!", status);
		return (-1);
	}
	if (argv[1][ft_strlen(argv[1]) - 1] != 'r')
		ft_error(EXIT_FAILURE, "Invalid map extension! (.ber)", status);
	else if (argv[1][ft_strlen(argv[1]) - 2] != 'e')
		ft_error(EXIT_FAILURE, "Invalid map extension! (.ber)", status);
	else if (argv[1][ft_strlen(argv[1]) - 3] != 'b')
		ft_error(EXIT_FAILURE, "Invalid map extension! (.ber)", status);
	else if (argv[1][ft_strlen(argv[1]) - 4] != '.')
		ft_error(EXIT_FAILURE, "Invalid map extension! (.ber)", status);
	return (0);
}

static int	ft_player_init_position(t_status *status)
{
	int		row;
	int		col;

	row = 0;
	while (row < status->map->size->y)
	{
		col = 0;
		while (col <= status->map->size->x)
		{
			if (status->map->map[row][col] == 'P')
			{
				status->img->pos->x = col;
				status->img->pos->y = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}

static int	ft_expose(t_status *status)
{
	ft_print_map(status);
	ft_print_steps(status);
	return (0);
}

int	main(int argc, char **argv)
{
	t_status	*status;

	status = malloc(sizeof(t_status) * 1);
	if (!status)
		return (1);
	if (ft_mem_allocation(&status) != 0)
		ft_mem_error(1, status);
	ft_arguments_tester(argc, argv, status);
	ft_get_map_dim(status, argv);
	ft_vars_init(status);
	ft_get_map(status, argv);
	ft_map_tester(status);
	status->mlx = mlx_init();
	status->win = mlx_new_window(status->mlx, status->map->size->x * SPRITE_W,
			status->map->size->y * SPRITE_H, "So long");
	ft_player_init_position(status);
	status->game->enemies = ft_count_items(status, 'Y');
	status->game->collects = ft_count_items(status, 'C');
	ft_print_map(status);
	mlx_hook(status->win, X_EVENT_KEY_PRESS, 1L << 0, ft_key_press, status);
	mlx_hook(status->win, X_EVENT_KEY_EXIT, 1L << 0, ft_mlx_close, status);
	mlx_expose_hook(status->win, ft_expose, status);
	if (status->game->enemies > 0)
		mlx_loop_hook(status->mlx, ft_enemy_movement, status);
	mlx_loop(status->mlx);
	ft_mem_free(&status);
}
