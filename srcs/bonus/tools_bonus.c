/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:03:58 by jolopez-          #+#    #+#             */
/*   Updated: 2023/08/09 20:05:35 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long_bonus.h"

int	ft_count_items(t_status *status, char item)
{
	int	row;
	int	col;
	int	count;

	count = 0;
	row = 0;
	while (row < status->map->size->y)
	{
		col = 0;
		while (status->map->map[row][col])
		{
			if (status->map->map[row][col] == item)
				count++;
			col++;
		}
		row++;
	}
	return (count);
}

int	ft_key_press(int key, t_status *status)
{
	int	init_steps;

	init_steps = status->game->steps;
	if (key == ESC)
		ft_exit(status, "Game closed!");
	else
	{
		ft_movements(key, status);
		if (status->game->enemies > 0)
			ft_enemy_collision(key, status);
	}
	if (init_steps != status->game->steps)
		ft_printf("Steps: %d\n", status->game->steps);
	ft_print_map(status);
	ft_print_steps(status);
	return (0);
}

int	ft_exit_found(t_status *status)
{
	if (ft_count_items(status, 'C') == 0)
		ft_exit(status, "CONGRATS\n!!!! You WON !!!!");
	else
		ft_printf("\e[35m\e[1mPlease, collect all diamonds!!!\e[0m\n");
	return (0);
}

int	ft_mlx_close(t_status *status)
{
	ft_exit(status, "Game closed!");
	return (0);
}

int	ft_check_collects(t_status *status)
{
	int	collects;

	collects = ft_count_items(status, 'C');
	if (collects == 0)
	{
		ft_exit(status, "CONGRATS\n!!!! You WON !!!");
	}
	else
		ft_printf("Please, take all collects before leaving!!\n");
	return (0);
}
