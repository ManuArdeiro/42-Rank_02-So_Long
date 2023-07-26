/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:15:29 by jolopez-          #+#    #+#             */
/*   Updated: 2023/07/26 18:19:57 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long_bonus.h"

int	enemy_move_right(t_status *s)
{
	if (s->map->map[s->enemy->pos->y][s->enemy->pos->x + 1] == 'P')
		ft_exit(s, "GAME OVER!!!! \nYou LOST !!!!");
	s->map->map[s->enemy->pos->y][s->enemy->pos->x] = '0';
	s->enemy->pos->x += 1;
	s->map->map[s->enemy->pos->y][s->enemy->pos->x] = 'Y';
	s->game->enemies++;
	return (0);
}

int	enemy_move_down(t_status *s)
{
	if (s->map->map[s->enemy->pos->y + 1][s->enemy->pos->x] == 'P')
		ft_exit(s, "GAME OVER!!!! \nYou LOST !!!!");
	s->map->map[s->enemy->pos->y][s->enemy->pos->x] = '0';
	s->enemy->pos->y += 1;
	s->map->map[s->enemy->pos->y][s->enemy->pos->x] = 'Y';
	s->game->enemies++;
	return (0);
}

int	enemy_move_left(t_status *s)
{
	if (s->map->map[s->enemy->pos->y][s->enemy->pos->x - 1] == 'P')
		ft_exit(s, "GAME OVER!!!! \nYou LOST !!!!");
	s->map->map[s->enemy->pos->y][s->enemy->pos->x] = '0';
	s->enemy->pos->x -= 1;
	s->map->map[s->enemy->pos->y][s->enemy->pos->x] = 'Y';
	s->game->enemies++;
	return (0);
}

int	enemy_move_up(t_status *s)
{
	if (s->map->map[s->enemy->pos->y - 1][s->enemy->pos->x] == 'P')
		ft_exit(s, "GAME OVER!!!! \nYou LOST !!!!");
	s->map->map[s->enemy->pos->y][s->enemy->pos->x] = '0';
	s->enemy->pos->y -= 1;
	s->map->map[s->enemy->pos->y][s->enemy->pos->x] = 'Y';
	s->game->enemies++;
	return (0);
}
