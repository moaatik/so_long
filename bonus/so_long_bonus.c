/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:08:25 by moaatik           #+#    #+#             */
/*   Updated: 2025/03/12 14:31:21 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (0);
	if (input(av, &game))
		return (1);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (free_strs(game.map), 1);
	game.window = mlx_new_window(game.mlx, game.map_y * TILE_SIZE, \
		game.map_x * TILE_SIZE, "so_long");
	if (!game.window)
		return (free_strs(game.map), free(game.mlx), 1);
	if (init_images(&game))
	{
		mlx_destroy_window(game.mlx, game.window);
		destroy_images(&game);
		ft_error();
	}
	render_map(&game);
	mlx_hook(game.window, 2, 0, key_press, &game);
	mlx_hook(game.window, 17, 0, handle_cross, &game);
	mlx_loop_hook(game.mlx, handle_frames, &game);
	mlx_loop(game.mlx);
	return (0);
}
