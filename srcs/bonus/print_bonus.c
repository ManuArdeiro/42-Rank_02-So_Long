/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:34:28 by jolopez-          #+#    #+#             */
/*   Updated: 2023/08/09 18:38:23 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long_bonus.h"

int	ft_error(int code, char *text, t_status *status)
{
	printf("\e[31m\e[1mArguments Error -> %s \e[32m\e[0m \n", text);
	free(status);
	exit (code);
}

int	ft_mem_error(int code, t_status *status)
{
	printf("\e[31m\e[1mMem Error! \e[32m\e[0m \n");
	free(status);
	exit (code);
}

int	ft_map_error(int code, char *text, t_status *status)
{
	printf("\e[35m\e[1mMap Error -> %s \e[32m\e[0m \n", text);
	mlx_destroy_window(status->mlx, status->win);
	free(status);
	exit (code);
}

int	ft_exit(t_status *status, char *text)
{
	printf("\e[37m\e[1m%s \e[32m\e[0m \n", text);
	mlx_destroy_window(status->mlx, status->win);
	free(status);
	exit(0);
}

int	ft_print_steps(t_status *s)
{
	char	*str;

	str = ft_itoa(s->game->steps);
	mlx_string_put(s->mlx, s->win, (s->img->pos->x * SPRITE_W) + 5,
		(s->img->pos->y * SPRITE_H) + 5, 0x833000, str);
	return (0);
}
