/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigunay <sigunay@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:49:50 by sigunay           #+#    #+#             */
/*   Updated: 2024/05/03 15:49:52 by sigunay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "../printf/ft_printf.h"

void	check_file_path(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (file_name[i - 1] != 'r' || file_name[i - 2] != 'e'
		|| file_name[i - 3] != 'b' || file_name[i - 4] != '.')
	{
		ft_printf("Wrong path name!!\n");
		exit(1);
	}
}

void	empty_check(char *line, char **ret)
{
	if (*line == '\n')
	{
		ft_printf("Empty Line in Map\n");
		free(*ret);
		free(line);
		exit(1);
	}
}

void	init_values(t_win *win)
{
	win->player_count = 0;
	win->move_count = 0;
	win->coin_count = 0;
	win->collected_coin = 0;
	win->path_coin = 0;
	win->path_exit = 0;
	win->exit_count = 0;
}
