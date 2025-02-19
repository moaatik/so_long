/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:36:36 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/20 00:26:32 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update(t_game *game)
{
	game->collect = 0;
	game->map_x = 0;
	while (game->map[game->map_x])
	{
		game->map_y = 0;
		while (game->map[game->map_x][game->map_y])
		{
			if (game->map[game->map_x][game->map_y] == 'C')
				game->collect++;
			if (game->map[game->map_x][game->map_y] == 'P')
			{
				game->player_x = game->map_x;
				game->player_y = game->map_y;
			}
			if (game->map[game->map_x][game->map_y] == 'E')
			{
				game->exit_x = game->map_x;
				game->exit_y = game->map_y;
			}
			game->map_y++;
		}
		game->map_x++;
	}
}

int	init_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->player = mlx_xpm_file_to_image(game->mlx, \
		"images/death.xpm", &img_width, &img_height);
	game->ground = mlx_xpm_file_to_image(game->mlx, \
		"images/floor.xpm", &img_width, &img_height);
	game->exit_closed = mlx_xpm_file_to_image(game->mlx, \
		"images/exit.xpm", &img_width, &img_height);
	game->wall = mlx_xpm_file_to_image(game->mlx, \
		"images/wall.xpm", &img_width, &img_height);
	game->coin = mlx_xpm_file_to_image(game->mlx, \
		"images/skull.xpm", &img_width, &img_height);
	if (!game->player || !game->ground || !game->exit_closed || \
		!game->wall || !game->coin)
		return (1);
	return (0);
}

void	put_on_window(t_game *game, int i, int j)
{
	j = 0;
	while (j <= game->map_y)
	{
		if (game->map[i][j] == '0')
			mlx_put_image_to_window(game->mlx, game->window, \
				game->ground, j * TILE_SIZE, i * TILE_SIZE);
		if (game->map[i][j] == '1')
			mlx_put_image_to_window(game->mlx, game->window, \
				game->wall, j * TILE_SIZE, i * TILE_SIZE);
		if (game->map[i][j] == 'P')
		{
			mlx_put_image_to_window(game->mlx, game->window, \
				game->ground, j * TILE_SIZE, i * TILE_SIZE);
			mlx_put_image_to_window(game->mlx, game->window, \
				game->player, j * TILE_SIZE, i * TILE_SIZE);
		}
		if (game->map[i][j] == 'C')
		{
			mlx_put_image_to_window(game->mlx, game->window, \
				game->ground, j * TILE_SIZE, i * TILE_SIZE);
			mlx_put_image_to_window(game->mlx, game->window, \
				game->coin, j * TILE_SIZE, i * TILE_SIZE);
		}
		j++;
	}
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window(game->mlx, game->window);
	update(game);
	while (game->map[i])
		put_on_window(game, i++, j);
	mlx_put_image_to_window(game->mlx, game->window, game->ground, \
		game->exit_y * TILE_SIZE, game->exit_x * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->window, \
			game->exit_closed, game->exit_y * TILE_SIZE, \
				game->exit_x * TILE_SIZE);
	if (game->player_x == game->exit_x && game->exit_y == game->player_y)
		mlx_put_image_to_window(game->mlx, game->window, \
			game->player, game->player_y * TILE_SIZE, \
				game->player_x * TILE_SIZE);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->window);
		destroy_images(game);
		exit(0);
	}
	else if (keycode == 13 || keycode == 126)
		move_up(game);
	else if (keycode == 1 || keycode == 125)
		move_down(game);
	else if (keycode == 0 || keycode == 123)
		move_left(game);
	else if (keycode == 2 || keycode == 124)
		move_right(game);
	render_map(game);
	if (game->collect == 0 && game->player_x == game->exit_x && \
		game->player_y == game->exit_y)
	{
		mlx_destroy_window(game->mlx, game->window);
		destroy_images(game);
		exit(0);
	}
	return (0);
}
