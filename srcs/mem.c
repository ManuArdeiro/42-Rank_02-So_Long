/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:12:48 by jolopez-          #+#    #+#             */
/*   Updated: 2023/07/29 11:53:03 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_mem_allocation(t_status **s)
{
	(*s)->game = malloc(sizeof(t_game) * 1);
	(*s)->map = malloc(sizeof(t_map) * 1);
	(*s)->img = malloc(sizeof(t_img) * 1);
	(*s)->enemy = malloc(sizeof(t_img) * 1);
	if (!(*s)->game || !(*s)->map || !(*s)->img || !(*s)->enemy)
		return (10);
	(*s)->img->img = malloc(sizeof(void *) * 1);
	(*s)->img->size = malloc(sizeof(t_vector) * 1);
	(*s)->img->pos = malloc(sizeof(t_vector) * 1);
	if (!(*s)->img->img || !(*s)->img->size || !(*s)->img->pos)
		return (20);
	(*s)->enemy->img = malloc(sizeof(void *) * 1);
	(*s)->enemy->size = malloc(sizeof(t_vector) * 1);
	(*s)->enemy->pos = malloc(sizeof(t_vector) * 1);
	if (!(*s)->enemy->img || !(*s)->enemy->size || !(*s)->enemy->pos)
		return (30);
	(*s)->map->map = malloc(sizeof(char **) * 1);
	(*s)->map->size = malloc(sizeof(t_vector) * 1);
	if (!(*s)->map->size || !(*s)->map->map)
		return (40);
	return (0);
}

void	ft_mem_free(t_status **s)
{
	free((*s)->map->size);
	free((*s)->map->map);
	free((*s)->enemy->img);
	free((*s)->enemy->size);
	free((*s)->enemy->pos);
	free((*s)->img->img);
	free((*s)->img->size);
	free((*s)->img->pos);
	free((*s)->game);
	free((*s)->map);
	free((*s)->img);
	free((*s)->enemy);
}
