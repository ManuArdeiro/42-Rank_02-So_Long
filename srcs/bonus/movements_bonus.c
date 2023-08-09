/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:34:49 by jolopez-          #+#    #+#             */
/*   Updated: 2023/08/09 18:38:20 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long_bonus.h"

static int	move_left(t_status *status)
{
	status->map->map[status->img->pos->y][status->img->pos->x] = '0';
	status->img->pos->x -= 1;
	status->map->map[status->img->pos->y][status->img->pos->x] = 'P';
	status->game->steps++;
	return (0);
}

static int	move_right(t_status *status)
{
	status->map->map[status->img->pos->y][status->img->pos->x] = '0';
	status->img->pos->x += 1;
	status->map->map[status->img->pos->y][status->img->pos->x] = 'P';
	status->game->steps++;
	return (0);
}

static int	move_down(t_status *status)
{
	status->map->map[status->img->pos->y][status->img->pos->x] = '0';
	status->img->pos->y += 1;
	status->map->map[status->img->pos->y][status->img->pos->x] = 'P';
	status->game->steps++;
	return (0);
}

static int	move_up(t_status *status)
{
	status->map->map[status->img->pos->y][status->img->pos->x] = '0';
	status->img->pos->y -= 1;
	status->map->map[status->img->pos->y][status->img->pos->x] = 'P';
	status->game->steps++;
	return (0);
}

int	ft_movements(int key, t_status *s)
{
	if ((key == A_KEY)
		&& (s->map->map[s->img->pos->y][s->img->pos->x - 1] == 'E'))
		ft_exit_found(s);
	else if ((key == A_KEY)
		&& (s->map->map[s->img->pos->y][s->img->pos->x - 1] != '1'))
		move_left(s);
	if ((key == D_KEY)
		&& (s->map->map[s->img->pos->y][s->img->pos->x + 1] == 'E'))
		ft_check_collects(s);
	else if ((key == D_KEY)
		&& (s->map->map[s->img->pos->y][s->img->pos->x + 1] != '1'))
		move_right(s);
	if ((key == S_KEY)
		&& (s->map->map[s->img->pos->y + 1][s->img->pos->x] == 'E'))
		ft_check_collects(s);
	else if ((key == S_KEY)
		&& (s->map->map[s->img->pos->y + 1][s->img->pos->x] != '1'))
		move_down(s);
	if ((key == W_KEY)
		&& (s->map->map[s->img->pos->y - 1][s->img->pos->x] == 'E'))
		ft_check_collects(s);
	else if ((key == W_KEY)
		&& (s->map->map[s->img->pos->y - 1][s->img->pos->x] != '1'))
		move_up(s);
	return (0);
}
