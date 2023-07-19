/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:12:48 by jolopez-          #+#    #+#             */
/*   Updated: 2023/07/19 19:20:05 by jolopez-         ###   ########.fr       */
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
		return (1);
	(*s)->img->img = malloc(sizeof(void *) * 1);
	(*s)->img->addr = malloc(sizeof(int *) * 1);
	(*s)->img->spt_path = malloc(sizeof(char *) * 1);
	(*s)->img->size = malloc(sizeof(t_vector) * 1);
	(*s)->img->pos = malloc(sizeof(t_vector) * 1);
	if (!(*s)->img->img || !(*s)->img->addr || !(*s)->img->spt_path
		|| !(*s)->img->size || !(*s)->img->pos)
	(*s)->enemy->img = malloc(sizeof(void *) * 1);
	(*s)->enemy->addr = malloc(sizeof(int *) * 1);
	(*s)->enemy->spt_path = malloc(sizeof(char *) * 1);
	(*s)->enemy->size = malloc(sizeof(t_vector) * 1);
	(*s)->enemy->pos = malloc(sizeof(t_vector) * 1);
	if (!(*s)->enemy->img || !(*s)->enemy->addr || !(*s)->enemy->spt_path
		|| !(*s)->enemy->size || !(*s)->enemy->pos)
		return (1);
	return (0);
}

void	ft_mem_free(t_status **s)
{
	free((*s)->img->img);
	free((*s)->img->addr);
	free((*s)->img->spt_path);
	free((*s)->img->size);
	free((*s)->img->pos);
	free((*s)->game);
	free((*s)->map);
	free((*s)->img);
	free((*s)->enemy);
}
