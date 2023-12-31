/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:00:27 by jolopez-          #+#    #+#             */
/*   Updated: 2023/08/10 16:30:30 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_error(int code, char *text, t_status *status)
{
	ft_printf("\e[31m\e[1mArguments Error -> %s \e[32m\e[0m \n", text);
	free(status);
	exit (code);
}

int	ft_mem_error(int code, t_status *status)
{
	ft_printf("\e[31m\e[1mMem Error! \e[32m\e[0m \n");
	free(status);
	exit (code);
}

int	ft_map_error(int code, char *text, t_status *status)
{
	ft_printf("\e[35m\e[1mMap Error -> %s \e[32m\e[0m \n", text);
	free(status);
	exit (code);
}

int	ft_exit(t_status *status, char *text)
{
	ft_printf("\e[37m\e[1m%s \e[32m\e[0m \n", text);
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
