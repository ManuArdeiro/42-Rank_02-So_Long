/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tool_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:24:40 by jolopez-          #+#    #+#             */
/*   Updated: 2023/07/25 17:22:29 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long_bonus.h"

int	ft_get_map_dim(t_status *status, char **argv)
{
	int		fd;
	char	*line;

	line = "";
	status->map->size->x = 0;
	status->map->size->y = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error(EXIT_FAILURE, "Map not found!\n", status);
	line = ft_gnl(fd);
	ft_get_map_dim_aux(fd, line, status);
	close(fd);
	return (0);
}

void	ft_get_map_dim_aux(int fd, char *line, t_status *status)
{
	int	len;

	while (line)
	{
		len = (int)ft_strlen(line);
		if (status->map->size->x > 0 && len != status->map->size->x)
			ft_error(EXIT_FAILURE, "Map is not a rectangle!", status);
		status->map->size->x = len;
		status->map->size->y++;
		if (status->map->size->x > 1000 || status->map->size->y > 1000)
			ft_error(EXIT_FAILURE, "Map is too big!", status);
		line = ft_gnl(fd);
	}
}

int	ft_get_map(t_status *status, char **argv)
{
	int		row;
	int		fd;

	row = 0;
	status->map->map = malloc(sizeof(char *) * status->map->size->x);
	if (!status->map->map)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error(EXIT_FAILURE, "Map not found", status);
	status->map->map[row] = ft_gnl(fd);
	while (status->map->map[row++])
		status->map->map[row] = ft_gnl(fd);
	close(fd);
	return (0);
}

int	ft_print_map(t_status *status)
{
	int		row;
	int		col;

	row = 0;
	while (row < status->map->size->y)
	{
		col = 0;
		while (col < status->map->size->x)
		{
			ft_load_map(status, row, col);
			col++;
		}
		row++;
	}
	return (0);
}

int	ft_load_map(t_status *s, int row, int col)
{
	if (s->map->map[row][col] == '1')
		s->img->img = mlx_xpm_file_to_image(s->mlx,
				"./images/32 bush.xpm", &s->img->size->x, &s->img->size->y);
	else if (s->map->map[row][col] == '0')
		s->img->img = mlx_xpm_file_to_image(s->mlx,
				"./images/32 grass.xpm", &s->img->size->x, &s->img->size->y);
	else if (s->map->map[row][col] == 'E')
		s->img->img = mlx_xpm_file_to_image(s->mlx,
				"./images/32-exit.xpm", &s->img->size->x, &s->img->size->y);
	else if (s->map->map[row][col] == 'C')
		s->img->img = mlx_xpm_file_to_image(s->mlx,
				"./images/32-food.xpm", &s->img->size->x, &s->img->size->y);
	else if (s->map->map[row][col] == 'P')
		s->img->img = mlx_xpm_file_to_image(s->mlx,
				"./images/32 player.xpm", &s->img->size->x, &s->img->size->y);
	else if (s->map->map[row][col] == 'Y')
		ft_enemy_animation(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img->img,
		SPRITE_W * col, SPRITE_H * row);
	mlx_destroy_image(s->mlx, s->img->img);
	return (0);
}
