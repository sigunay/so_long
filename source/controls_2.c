/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigunay <sigunay@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:49:46 by sigunay           #+#    #+#             */
/*   Updated: 2024/05/03 15:49:47 by sigunay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "../printf/ft_printf.h"

void	copy_map(t_win *win, t_map *map)
{
	t_map	copy_map;
	int		i;

	i = 0;
	copy_map.map = malloc(sizeof(char *) * map->height);
	if (copy_map.map == NULL)
		ft_free(win, 1);
	while (i < map->height)
	{
		copy_map.map[i] = ft_strdup(map->map[i]);
		if (copy_map.map[i] == NULL)
			ft_free(win, 1);
		i++;
	}
	copy_map.height = map->height;
	copy_map.width = map->width;
	win->copy_map = copy_map;
}

void	check_wall_access(t_win *win)
{
	if (win->path_coin != win->coin_count || win->path_exit != win->exit_count)
	{
		ft_printf("ERROR: Unaccessible coin or exit\n");
		ft_free(win, 1);
	}
}

void	is_accessible(t_win *win, int y, int x)
{
	if (win->copy_map.map[x][y] == '1' || win->copy_map.map[x][y] == '#')
		return ;
	if (win->copy_map.map[x][y] == 'C')
		win->path_coin++;
	if (win->copy_map.map[x][y] == 'E')
	{
		win->path_exit = 1;
		return ;
	}
	win->copy_map.map[x][y] = '#';
	is_accessible(win, y, x + 1);
	is_accessible(win, y, x - 1);
	is_accessible(win, y + 1, x);
	is_accessible(win, y - 1, x);
}

void	rec_control(t_win *win)
{
	int	a;
	int	i;

	a = ft_strlen(win->map.map[0]);
	i = 0;
	while (i < (win->map.height))
	{
		if (ft_strlen(win->map.map[i]) != a)
		{
			ft_printf("Map is not rectangular\n");
			ft_free(win, 1);
		}
		i++;
	}
}
