/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:22:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/07/25 17:00:53 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long_bonus.h"

int	ft_enemy_position(t_status *status)
{
	int		row;
	int		col;

	row = 0;
	while (row < status->map->size->y)
	{
		col = 0;
		while (col <= status->map->size->x)
		{
			if (status->map->map[row][col] == 'Y')
			{
				status->enemy->pos->x = col;
				status->enemy->pos->y = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	ft_player_position(t_status *status)
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
				status->enemy->pos->x = col;
				status->enemy->pos->y = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	ft_enemy_collision(int key, t_status *s)
{
	if ((key == A_KEY)
		&& (s->map->map[s->img->pos->y][s->img->pos->x - 1] == 'Y'))
	{
		ft_exit(s, "GAME OVER\n!!!! You LOST !!!!");
	}
	if ((key == D_KEY)
		&& (s->map->map[s->img->pos->y][s->img->pos->x + 1] == 'Y'))
	{
		ft_exit(s, "GAME OVER\n!!!! You LOST !!!!");
	}
	if ((key == S_KEY)
		&& (s->map->map[s->img->pos->y + 1][s->img->pos->x] == 'Y'))
	{
		ft_exit(s, "GAME OVER\n!!!! You LOST !!!!");
	}
	if ((key == W_KEY)
		&& (s->map->map[s->img->pos->y - 1][s->img->pos->x] == 'Y'))
	{
		ft_exit(s, "GAME OVER\n!!!! You LOST !!!!");
	}
	return (0);
}

int	ft_enemy_animation(t_status *s)
{
	if (s->game->steps % 2 == 1)
		s->img->img = mlx_xpm_file_to_image(s->mlx, "./images/32-enemy.xpm",
				&s->img->size->x, &s->img->size->y);
	else
		s->img->img = mlx_xpm_file_to_image(s->mlx, "./images/32-tree.xpm",
				&s->img->size->x, &s->img->size->y);
	s->animation++;
	return (0);
}
