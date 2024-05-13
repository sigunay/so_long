/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigunay <sigunay@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:49:35 by sigunay           #+#    #+#             */
/*   Updated: 2024/05/03 15:49:37 by sigunay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "../minilibx/mlx.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free(t_win *win, int a)
{
	int	i;

	if (win->map.map)
	{
		i = 0;
		while (i < win->map.height && win->map.map[i])
		{
			free(win->map.map[i]);
			i++;
		}
		free(win->map.map);
	}
	if (win->copy_map.map)
	{
		i = 0;
		while (i < win->copy_map.height && win->copy_map.map[i])
		{
			free(win->copy_map.map[i]);
			i++;
		}
		free(win->copy_map.map);
	}
	exit (a);
}

void	close_images(t_win *win)
{
	if (win->coin)
		mlx_destroy_image(win->mlx_ptr, win->coin);
	if (win->background)
		mlx_destroy_image(win->mlx_ptr, win->background);
	if (win->wall)
		mlx_destroy_image(win->mlx_ptr, win->wall);
	if (win->exit)
		mlx_destroy_image(win->mlx_ptr, win->exit);
	if (win->player.player)
		mlx_destroy_image(win->mlx_ptr, win->player.player);
	if (win->mlx_ptr)
		mlx_destroy_window(win->mlx_ptr, win->mlx_win);
}

int	close_game(void *param)
{
	t_win	*win;

	win = param;
	close_images(win);
	ft_free(win, 0);
	return (1);
}
