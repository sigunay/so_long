/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigunay <sigunay@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:49:07 by sigunay           #+#    #+#             */
/*   Updated: 2024/05/03 15:49:09 by sigunay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_char
{
	void	*player;
	int		ply_x;
	int		ply_y;
}	t_char;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
}	t_map;

typedef struct s_win
{
	t_map	map;
	t_map	copy_map;
	t_char	player;
	void	*mlx_win;
	void	*mlx_ptr;
	int		height;
	int		width;
	void	*background;
	void	*wall;
	void	*exit;
	void	*coin;
	int		collected_coin;
	int		move_count;
	int		player_count;
	int		coin_count;
	int		exit_count;
	int		path_exit;
	int		path_coin;
	int		px;
	int		py;
}	t_win;

//functions
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);

//map_funcs
void	get_map(t_win *win, char *path);
void	add_images(t_win *win);
void	put_images_right_places(t_win *win, char c, int x, int y);
void	init_values(t_win *win);

//free_funcs
void	ft_free(t_win *win, int a);
int		close_game(void *param);
void	close_images(t_win *win);

//check_funcs
void	check_file_path(char *file_name);
void	check_file_status(char *file_name);
void	empty_check(char *line, char **ret);

//controls
void	wall_control(t_win *win, int height, int width);
void	value_control(t_win *win);
void	check_wall_access(t_win *win);
void	is_accessible(t_win *win, int y, int x);
void	copy_map(t_win *win, t_map *map);
void	rec_control(t_win *win);

#endif
