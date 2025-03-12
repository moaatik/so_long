/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_part_three_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:24:55 by moaatik           #+#    #+#             */
/*   Updated: 2025/03/12 14:56:20 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	count(long i)
{
	int	count;

	if (i == 0)
		return (1);
	count = 0;
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

int	handle_frames(t_game *game)
{
	game->counter++;
	if (game->counter == 3)
	{
		game->counter = 0;
		game->player_frame++;
		game->coin_frame++;
		if (game->player_frame >= 8)
			game->player_frame = 0;
		if (game->coin_frame >= 6)
			game->coin_frame = 0;
	}
	render_map(game);
	game->current_exit = 100 - ((game->collect * 100) / game->all_coins);
	if (game->current_exit < 25)
		game->current_exit = 0;
	else if (game->current_exit < 50)
		game->current_exit = 1;
	else if (game->current_exit < 75)
		game->current_exit = 2;
	else if (game->current_exit < 100)
		game->current_exit = 3;
	else
		game->current_exit = 4;
	return (0);
}

int	init_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->moves = 0;
	game->player_frame = 0;
	game->coin_frame = 0;
	update(game);
	game->all_coins = game->collect;
	game->counter = 0;
	game->ground = mlx_xpm_file_to_image(game->mlx, \
		"textures/floor.xpm", &img_width, &img_height);
	game->wall = mlx_xpm_file_to_image(game->mlx, \
		"textures/plant.xpm", &img_width, &img_height);
	game->numbers[0] = mlx_xpm_file_to_image(game->mlx, \
		"textures/numbers/0.xpm", &img_width, &img_height);
	if (!game->ground || !game->wall \
	|| !game->numbers[0] || init_numbers(game, img_height, img_width))
		return (1);
	return (0);
}
