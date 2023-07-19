/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:00:14 by jolopez-          #+#    #+#             */
/*   Updated: 2023/07/15 16:32:25 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static int	ft_walls_tester(t_status *status)
{
	int		row;
	int		col;

	row = 0;
	while (row < status->map->size->y)
	{
		col = 0;
		if (row == 0 || row == (status->map->size->y - 1))
		{
			while (status->map->map[row][col])
			{
				if (status->map->map[row][col] != '1')
					ft_map_error(EXIT_FAILURE,
						"Invalid upper/lower walls!", status);
				col++;
			}
		}
		if (status->map->map[row][0] != '1'
			|| status->map->map[row][status->map->size->x - 1] != '1')
			ft_map_error(EXIT_FAILURE, "Invalid lateral walls!", status);
		row++;
	}
	return (0);
}

static int	ft_sprites_tester(t_status *status, char PEC)
{
	int		number;
	int		row;
	int		col;

	number = 0;
	row = 0;
	while (row < status->map->size->y)
	{
		col = 0;
		while (col <= status->map->size->x)
		{
			if (status->map->map[row][col] == PEC)
				number = number + 1;
			col++;
		}
		row++;
	}
	return (number);
}

static int	ft_chars_tester(t_status *status)
{
	int		row;
	int		col;	

	row = 0;
	while (row < status->map->size->y)
	{
		col = 0;
		while (status->map->map[row][col])
		{
			if (status->map->map[row][col] != '0'
				&& status->map->map[row][col] != '1'
				&& status->map->map[row][col] != 'P'
				&& status->map->map[row][col] != 'E'
				&& status->map->map[row][col] != 'C'
				&& status->map->map[row][col] != 'Y')
				ft_error(EXIT_FAILURE, "Invalid map: unknown char");
			col++;
		}
		row++;
	}
	return (0);
}

int	ft_map_tester(t_status *status)
{
	int	players;
	int	exits;
	int	collects;

	ft_walls_tester(status);
	players = ft_sprites_tester(status, 'P');
	if (players != 1)
		ft_map_error(EXIT_FAILURE, "This game is for 1 player!", status);
	exits = ft_sprites_tester(status, 'E');
	if (exits == 0)
		ft_map_error(EXIT_FAILURE, "No exits!", status);
	collects = ft_sprites_tester(status, 'C');
	if (collects == 0)
		ft_map_error(EXIT_FAILURE, "No collects!", status);
	ft_chars_tester(status);
	return (0);
}
