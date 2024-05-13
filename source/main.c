/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigunay <sigunay@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:49:24 by sigunay           #+#    #+#             */
/*   Updated: 2024/05/03 15:49:26 by sigunay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../printf/ft_printf.h"
#include "../minilibx/mlx.h"

void	put_images_right_places(t_win *win, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, win->wall, x, y);
	else
		mlx_put_image_to_window(win->mlx_ptr, win->mlx_win,
			win->background, x, y);
	if (c == 'P')
	{
		win->player.ply_x = x;
		win->player.ply_y = y;
		mlx_put_image_to_window(win->mlx_ptr, win->mlx_win,
			win->player.player, x, y);
	}
	if (c == 'E')
		mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, win->exit, x, y);
	if (c == 'C')
		mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, win->coin, x, y);
}

static void	create_map(t_win *win)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (win->map.map[i])
	{
		j = 0;
		x = 0;
		while (win->map.map[i][j])
		{
			put_images_right_places(win, win->map.map[i][j], x, y);
			x += 64;
			j++;
		}
		i++;
		y += 64;
	}
}

static void	move_p(t_win *win, int x, int y)
{
	if (win->map.map[y / 64][x / 64] == 'C')
		win->collected_coin += 1;
	if (win->map.map[y / 64][x / 64] == 'E' &&
		win->collected_coin == win->coin_count)
	{
		ft_printf("Win!\n");
		close_game(win);
	}
	if (win->map.map[y / 64][x / 64] != '1' &&
		win->map.map[y / 64][x / 64] != 'E')
	{
		win->move_count++;
		win->map.map[win->player.ply_y / 64][win->player.ply_x / 64] = '0';
		win->map.map[y / 64][x / 64] = 'P';
		ft_printf("Move: %d\n", win->move_count);
	}
}

static int	move(int keycode, void *param)
{
	t_win	*win;

	win = param;
	if (keycode == 53)
		close_game(param);
	if (keycode == 13)
		move_p(win, win->player.ply_x, win->player.ply_y - 64);
	if (keycode == 1)
		move_p(win, win->player.ply_x, win->player.ply_y + 64);
	if (keycode == 0)
		move_p(win, win->player.ply_x - 64, win->player.ply_y);
	if (keycode == 2)
		move_p(win, win->player.ply_x + 64, win->player.ply_y);
	create_map(win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	win;

	if (argc == 2)
	{
		init_values(&win);
		check_file_path(argv[1]);
		get_map(&win, argv[1]);
		add_images(&win);
		create_map(&win);
		mlx_hook(win.mlx_win, 2, 0, move, &win);
		mlx_hook(win.mlx_win, 17, 0, close_game, &win);
		mlx_loop(win.mlx_ptr);
	}
	else
		ft_printf("Missing argument");
}
