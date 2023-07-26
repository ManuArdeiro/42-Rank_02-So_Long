/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:24:24 by jolopez-          #+#    #+#             */
/*   Updated: 2023/07/26 21:06:52 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long_bonus.h"

int	ft_enemy_movement(t_status *s)
{
	usleep(100000);
	if (s->animation % 5 == 0)
	{
		if (s->previous == 'r')
			ft_try_right(s);
		else if (s->previous == 'l')
			ft_try_left(s);
		else if (s->previous == 'u')
			ft_try_up(s);
		else if (s->previous == 'd')
			ft_try_down(s);
	}
	ft_print_map(s);
	ft_print_steps(s);
	return (0);
}

void	ft_try_right(t_status *s)
{	
	ft_enemy_position(s);
	if ((s->map->map[s->enemy->pos->y][s->enemy->pos->x + 1] == '0'
		|| s->map->map[s->enemy->pos->y][s->enemy->pos->x + 1] == 'P'))
		{
			enemy_move_right(s);
			s->previous = 'r';
		}
	else if ((s->map->map[s->enemy->pos->y + 1][s->enemy->pos->x] == '0'
		|| s->map->map[s->enemy->pos->y + 1][s->enemy->pos->x] == 'P'))
		{
			enemy_move_down(s);
			s->previous = 'd';
		}
	else if ((s->map->map[s->enemy->pos->y - 1][s->enemy->pos->x] == '0'
		|| s->map->map[s->enemy->pos->y - 1][s->enemy->pos->x] == 'P'))
		{
			enemy_move_up(s);
			s->previous = 'u';
		}
	else if ((s->map->map[s->enemy->pos->y][s->enemy->pos->x - 1] == '0'
		|| s->map->map[s->enemy->pos->y][s->enemy->pos->x - 1] == 'P'))
		{
			enemy_move_left(s);
			s->previous = 'l';
		}
}

void	ft_try_left(t_status *s)
{	
	ft_enemy_position(s);
	if ((s->map->map[s->enemy->pos->y][s->enemy->pos->x - 1] == '0'
		|| s->map->map[s->enemy->pos->y][s->enemy->pos->x - 1] == 'P'))
		{
			enemy_move_left(s);
			s->previous = 'l';
		}
	else if ((s->map->map[s->enemy->pos->y - 1][s->enemy->pos->x] == '0'
		|| s->map->map[s->enemy->pos->y - 1][s->enemy->pos->x] == 'P'))
		{
			enemy_move_up(s);
			s->previous = 'u';
		}
	else if ((s->map->map[s->enemy->pos->y + 1][s->enemy->pos->x] == '0'
		|| s->map->map[s->enemy->pos->y + 1][s->enemy->pos->x] == 'P'))
		{
			enemy_move_down(s);
			s->previous = 'd';
		}
	else if ((s->map->map[s->enemy->pos->y][s->enemy->pos->x + 1] == '0'
		|| s->map->map[s->enemy->pos->y][s->enemy->pos->x + 1] == 'P'))
		{
			enemy_move_right(s);
			s->previous = 'r';
		}
}

void	ft_try_up(t_status *s)
{	
	ft_enemy_position(s);
	if ((s->map->map[s->enemy->pos->y - 1][s->enemy->pos->x] == '0'
		|| s->map->map[s->enemy->pos->y - 1][s->enemy->pos->x] == 'P'))
		{
			enemy_move_up(s);
			s->previous = 'u';
		}
	else if ((s->map->map[s->enemy->pos->y][s->enemy->pos->x - 1] == '0'
		|| s->map->map[s->enemy->pos->y][s->enemy->pos->x - 1] == 'P'))
		{
			enemy_move_left(s);
			s->previous = 'l';
		}
	else if ((s->map->map[s->enemy->pos->y][s->enemy->pos->x + 1] == '0'
		|| s->map->map[s->enemy->pos->y][s->enemy->pos->x + 1] == 'P'))
		{
			enemy_move_right(s);
			s->previous = 'r';
		}
	else if ((s->map->map[s->enemy->pos->y + 1][s->enemy->pos->x] == '0'
		|| s->map->map[s->enemy->pos->y + 1][s->enemy->pos->x] == 'P'))
		{
			enemy_move_down(s);
			s->previous = 'd';
		}
}

void	ft_try_down(t_status *s)
{	
	ft_enemy_position(s);
	if ((s->map->map[s->enemy->pos->y + 1][s->enemy->pos->x] == '0'
		|| s->map->map[s->enemy->pos->y + 1][s->enemy->pos->x] == 'P'))
		{
			enemy_move_down(s);
			s->previous = 'd';
		}
	else if ((s->map->map[s->enemy->pos->y][s->enemy->pos->x - 1] == '0'
		|| s->map->map[s->enemy->pos->y][s->enemy->pos->x - 1] == 'P'))
		{
			enemy_move_left(s);
			s->previous = 'l';
		}
	else if ((s->map->map[s->enemy->pos->y][s->enemy->pos->x + 1] == '0'
		|| s->map->map[s->enemy->pos->y][s->enemy->pos->x + 1] == 'P'))
		{
			enemy_move_right(s);
			s->previous = 'r';
		}
	else if ((s->map->map[s->enemy->pos->y - 1][s->enemy->pos->x] == '0'
		|| s->map->map[s->enemy->pos->y - 1][s->enemy->pos->x] == 'P'))
		{
			enemy_move_up(s);
			s->previous = 'u';
		}
}