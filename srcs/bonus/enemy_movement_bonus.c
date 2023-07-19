/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:24:24 by jolopez-          #+#    #+#             */
/*   Updated: 2023/07/19 19:24:26 by jolopez-         ###   ########.fr       */
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
	usleep(200000);
	ft_enemy_position(s);
	if ((s->map->map[s->enemy->pos->y][s->enemy->pos->x + 1] == '0'
		|| s->map->map[s->enemy->pos->y][s->enemy->pos->x + 1] == 'P')
		&& s->game->enemies < s->map->size->x)
		enemy_move_right(s);
	if ((s->map->map[s->enemy->pos->y + 1][s->enemy->pos->x] == '0'
		|| s->map->map[s->enemy->pos->y + 1][s->enemy->pos->x] == 'P')
		&& s->game->enemies < (s->map->size->x + s->map->size->y))
		enemy_move_down(s);
	if ((s->map->map[s->enemy->pos->y][s->enemy->pos->x - 1] == '0'
		|| s->map->map[s->enemy->pos->y][s->enemy->pos->x - 1] == 'P')
		&& s->game->enemies <
		((2 * s->map->size->x) + s->map->size->y))
		enemy_move_left(s);
	if ((s->map->map[s->enemy->pos->y - 1][s->enemy->pos->x] == '0'
		|| s->map->map[s->enemy->pos->y - 1][s->enemy->pos->x] == 'P')
		&& s->game->enemies <
		(2 * (s->map->size->x + s->map->size->y)))
		enemy_move_up(s);
	else
		s->game->enemies = 0;
	ft_print_map(s);
	ft_print_steps(s);
	return (0);
}
