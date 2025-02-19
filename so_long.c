/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:08:25 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/20 00:52:33 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (0);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	if (input(av, game))
		ft_error();
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map_y * TILE_SIZE, \
		game->map_x * TILE_SIZE, "so_long");
	if (init_images(game))
	{
		mlx_destroy_window(game->mlx, game->window);
		destroy_images(game);
		return (1);
	}
	game->moves = 0;
	render_map(game);
	mlx_hook(game->window, 2, 0, key_press, game);
	mlx_loop(game->mlx);
}
