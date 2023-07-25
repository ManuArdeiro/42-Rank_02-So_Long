/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:24:24 by jolopez-          #+#    #+#             */
/*   Updated: 2023/07/25 17:03:18 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long_bonus.h"

static int	enemy_move_right(t_status *s)
{
	if (s->map->map[s->enemy->pos->y][s->enemy->pos->x + 1] == 'P')
		ft_exit(s, "GAME OVER!!!! \nYou LOST !!!!");
	s->map->map[s->enemy->pos->y][s->enemy->pos->x] = '0';
	s->enemy->pos->x += 1;
	s->map->map[s->enemy->pos->y][s->enemy->pos->x] = 'Y';
	s->game->enemies++;
	return (0);
}

static int	enemy_move_down(t_status *s)
{
	if (s->map->map[s->enemy->pos->y + 1][s->enemy->pos->x] == 'P')
		ft_exit(s, "GAME OVER!!!! \nYou LOST !!!!");
	s->map->map[s->enemy->pos->y][s->enemy->pos->x] = '0';
	s->enemy->pos->y += 1;
	s->map->map[s->enemy->pos->y][s->enemy->pos->x] = 'Y';
	s->game->enemies++;
	return (0);
}

static int	enemy_move_left(t_status *s)
{
	if (s->map->map[s->enemy->pos->y][s->enemy->pos->x - 1] == 'P')
		ft_exit(s, "GAME OVER!!!! \nYou LOST !!!!");
	s->map->map[s->enemy->pos->y][s->enemy->pos->x] = '0';
	s->enemy->pos->x -= 1;
	s->map->map[s->enemy->pos->y][s->enemy->pos->x] = 'Y';
	s->game->enemies++;
	return (0);
}

static int	enemy_move_up(t_status *s)
{
	if (s->map->map[s->enemy->pos->y - 1][s->enemy->pos->x] == 'P')
		ft_exit(s, "GAME OVER!!!! \nYou LOST !!!!");
	s->map->map[s->enemy->pos->y][s->enemy->pos->x] = '0';
	s->enemy->pos->y -= 1;
	s->map->map[s->enemy->pos->y][s->enemy->pos->x] = 'Y';
	s->game->enemies++;
	return (0);
}

int	ft_enemy_movement(t_status *s)
{
	usleep(1000000);
	if (s->animation % 10 == 0)
	{
		ft_enemy_position(s);
		if ((s->map->map[s->enemy->pos->y][s->enemy->pos->x + 1] == '0'
			|| s->map->map[s->enemy->pos->y][s->enemy->pos->x + 1] == 'P'))
			enemy_move_right(s);
		else if ((s->map->map[s->enemy->pos->y + 1][s->enemy->pos->x] == '0'
			|| s->map->map[s->enemy->pos->y + 1][s->enemy->pos->x] == 'P'))
			enemy_move_down(s);
		else if ((s->map->map[s->enemy->pos->y][s->enemy->pos->x - 1] == '0'
			|| s->map->map[s->enemy->pos->y][s->enemy->pos->x - 1] == 'P'))
			enemy_move_left(s);
		else if ((s->map->map[s->enemy->pos->y - 1][s->enemy->pos->x] == '0'
			|| s->map->map[s->enemy->pos->y - 1][s->enemy->pos->x] == 'P'))
			enemy_move_up(s);
	}
	ft_print_map(s);
	ft_print_steps(s);
	return (0);
}
