/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:36:36 by moaatik           #+#    #+#             */
/*   Updated: 2025/03/12 15:37:48 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_on_window(t_game *game, int i, int j)
{
	j = 0;
	while (j <= game->map_y)
	{
		mlx_put_image_to_window(game->mlx, game->window, \
			game->ground, j * TILE_SIZE, i * TILE_SIZE);
		if (game->direction)
			mlx_put_image_to_window(game->mlx, game->window, \
				game->player[game->player_frame], game->player_y * TILE_SIZE, \
					game->player_x * TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx, game->window, \
				game->rev_player[game->player_frame], \
				game->player_y * TILE_SIZE, \
					game->player_x * TILE_SIZE);
		if (game->map[i][j] == '1')
			mlx_put_image_to_window(game->mlx, game->window, \
				game->wall, j * TILE_SIZE, i * TILE_SIZE);
		if (game->map[i][j] == 'C')
			mlx_put_image_to_window(game->mlx, game->window, \
				game->coin[game->coin_frame], j * TILE_SIZE, i * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->window, \
			game->exit[game->current_exit], game->exit_y * TILE_SIZE, \
				game->exit_x * TILE_SIZE);
		j++;
	}
}

void	put_moves_part_two(char *number, int *i, t_game *game)
{
	if (number[*i] == '3')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->numbers[3], *i * TILE_SIZE / 2, 1);
	else if (number[*i] == '4')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->numbers[4], *i * TILE_SIZE / 2, 1);
	else if (number[*i] == '5')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->numbers[5], *i * TILE_SIZE / 2, 1);
	else if (number[*i] == '6')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->numbers[6], *i * TILE_SIZE / 2, 1);
	else if (number[*i] == '7')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->numbers[7], *i * TILE_SIZE / 2, 1);
	else if (number[*i] == '8')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->numbers[8], *i * TILE_SIZE / 2, 1);
	else if (number[*i] == '9')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->numbers[9], *i * TILE_SIZE / 2, 1);
}

int	put_moves_on_screen(t_game *game)
{
	char	*number;
	int		i;

	i = 0;
	number = ft_itoa(game->moves);
	if (!number)
		return (1);
	while (number[i])
	{
		if (number[i] == '0')
			mlx_put_image_to_window(game->mlx, game->window, \
			game->numbers[0], i * TILE_SIZE / 2, 1);
		else if (number[i] == '1')
			mlx_put_image_to_window(game->mlx, game->window, \
			game->numbers[1], i * TILE_SIZE / 2, 1);
		else if (number[i] == '2')
			mlx_put_image_to_window(game->mlx, game->window, \
			game->numbers[2], i * TILE_SIZE / 2, 1);
		else
			put_moves_part_two(number, &i, game);
		i++;
	}
	return (free(number), 0);
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
	if ((game->player_x == game->exit_x && game->exit_y == game->player_y) \
		&& game->direction == 0)
		mlx_put_image_to_window(game->mlx, game->window, \
			game->rev_player[game->player_frame], game->player_y * TILE_SIZE, \
					game->player_x * TILE_SIZE);
	else if (game->player_x == game->exit_x && game->exit_y == game->player_y)
		mlx_put_image_to_window(game->mlx, game->window, \
			game->player[game->player_frame], game->player_y * TILE_SIZE, \
				game->player_x * TILE_SIZE);
	if (put_moves_on_screen(game))
	{
		mlx_destroy_window(game->mlx, game->window);
		destroy_images(game);
		write(2, "Failed while putting moves on screen\n", 37);
		exit(1);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 53 || game->moves >= 2147483647)
	{
		mlx_destroy_window(game->mlx, game->window);
		destroy_images(game);
		if (game->moves >= 2147483647)
			write(2, "You have reached the limit of movements\n", 40);
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
	if (game->collect == 0 && game->player_x == game->exit_x && \
		game->player_y == game->exit_y)
	{
		mlx_destroy_window(game->mlx, game->window);
		destroy_images(game);
		write(1, "Congratulations, you won!\n", 26);
		exit(0);
	}
	return (0);
}
