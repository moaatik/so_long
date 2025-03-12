/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:36:43 by moaatik           #+#    #+#             */
/*   Updated: 2025/03/12 14:56:14 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	init_exit(t_game *game, int img_height, int img_width)
{
	game->exit[0] = mlx_xpm_file_to_image(game->mlx, \
		"textures/exit/1.xpm", &img_width, &img_height);
	game->exit[1] = mlx_xpm_file_to_image(game->mlx, \
		"textures/exit/2.xpm", &img_width, &img_height);
	game->exit[2] = mlx_xpm_file_to_image(game->mlx, \
		"textures/exit/3.xpm", &img_width, &img_height);
	game->exit[3] = mlx_xpm_file_to_image(game->mlx, \
		"textures/exit/4.xpm", &img_width, &img_height);
	game->exit[4] = mlx_xpm_file_to_image(game->mlx, \
		"textures/exit/5.xpm", &img_width, &img_height);
	game->exit[5] = NULL;
	if (!game->exit[0] || !game->exit[1] || !game->exit[2] \
	|| !game->exit[3] || !game->exit[4])
		return (1);
	return (0);
}

int	init_rev_player(t_game *game, int img_height, int img_width)
{
	game->rev_player[0] = mlx_xpm_file_to_image(game->mlx, \
		"textures/rev_player/1.xpm", &img_width, &img_height);
	game->rev_player[1] = mlx_xpm_file_to_image(game->mlx, \
		"textures/rev_player/2.xpm", &img_width, &img_height);
	game->rev_player[2] = mlx_xpm_file_to_image(game->mlx, \
		"textures/rev_player/3.xpm", &img_width, &img_height);
	game->rev_player[3] = mlx_xpm_file_to_image(game->mlx, \
		"textures/rev_player/4.xpm", &img_width, &img_height);
	game->rev_player[4] = mlx_xpm_file_to_image(game->mlx, \
		"textures/rev_player/5.xpm", &img_width, &img_height);
	game->rev_player[5] = mlx_xpm_file_to_image(game->mlx, \
		"textures/rev_player/6.xpm", &img_width, &img_height);
	game->rev_player[6] = mlx_xpm_file_to_image(game->mlx, \
		"textures/rev_player/7.xpm", &img_width, &img_height);
	game->rev_player[7] = mlx_xpm_file_to_image(game->mlx, \
		"textures/rev_player/8.xpm", &img_width, &img_height);
	game->rev_player[8] = NULL;
	if (!game->rev_player[0] || !game->rev_player[1] || !game->rev_player[2] \
		|| !game->rev_player[3] || !game->rev_player[4] || !game->rev_player[5] \
		|| !game->rev_player[6] || !game->rev_player[7] \
		|| init_exit(game, img_height, img_width))
		return (1);
	return (0);
}

int	init_coin(t_game *game, int img_height, int img_width)
{
	game->coin[0] = mlx_xpm_file_to_image(game->mlx, \
		"textures/coins/1.xpm", &img_width, &img_height);
	game->coin[1] = mlx_xpm_file_to_image(game->mlx, \
		"textures/coins/2.xpm", &img_width, &img_height);
	game->coin[2] = mlx_xpm_file_to_image(game->mlx, \
		"textures/coins/3.xpm", &img_width, &img_height);
	game->coin[3] = mlx_xpm_file_to_image(game->mlx, \
		"textures/coins/4.xpm", &img_width, &img_height);
	game->coin[4] = mlx_xpm_file_to_image(game->mlx, \
		"textures/coins/5.xpm", &img_width, &img_height);
	game->coin[5] = mlx_xpm_file_to_image(game->mlx, \
		"textures/coins/6.xpm", &img_width, &img_height);
	game->coin[6] = NULL;
	if (!game->coin[0] || !game->coin[1] || !game->coin[2] \
		|| !game->coin[3] || !game->coin[4] || !game->coin[5] \
		|| init_rev_player(game, img_height, img_width))
		return (1);
	return (0);
}

int	init_player(t_game *game, int img_height, int img_width)
{
	game->player[0] = mlx_xpm_file_to_image(game->mlx, \
		"textures/player/1.xpm", &img_width, &img_height);
	game->player[1] = mlx_xpm_file_to_image(game->mlx, \
		"textures/player/2.xpm", &img_width, &img_height);
	game->player[2] = mlx_xpm_file_to_image(game->mlx, \
		"textures/player/3.xpm", &img_width, &img_height);
	game->player[3] = mlx_xpm_file_to_image(game->mlx, \
		"textures/player/4.xpm", &img_width, &img_height);
	game->player[4] = mlx_xpm_file_to_image(game->mlx, \
		"textures/player/5.xpm", &img_width, &img_height);
	game->player[5] = mlx_xpm_file_to_image(game->mlx, \
		"textures/player/6.xpm", &img_width, &img_height);
	game->player[6] = mlx_xpm_file_to_image(game->mlx, \
		"textures/player/7.xpm", &img_width, &img_height);
	game->player[7] = mlx_xpm_file_to_image(game->mlx, \
		"textures/player/8.xpm", &img_width, &img_height);
	game->player[8] = NULL;
	if (!game->player[0] || !game->player[1] || !game->player[2] \
		|| !game->player[3] || !game->player[4] || !game->player[5] \
		|| !game->player[6] || !game->player[7] \
		|| init_coin(game, img_height, img_width))
		return (1);
	return (0);
}

int	init_numbers(t_game *game, int img_height, int img_width)
{
	game->numbers[1] = mlx_xpm_file_to_image(game->mlx, \
		"textures/numbers/1.xpm", &img_width, &img_height);
	game->numbers[2] = mlx_xpm_file_to_image(game->mlx, \
		"textures/numbers/2.xpm", &img_width, &img_height);
	game->numbers[3] = mlx_xpm_file_to_image(game->mlx, \
		"textures/numbers/3.xpm", &img_width, &img_height);
	game->numbers[4] = mlx_xpm_file_to_image(game->mlx, \
		"textures/numbers/4.xpm", &img_width, &img_height);
	game->numbers[5] = mlx_xpm_file_to_image(game->mlx, \
		"textures/numbers/5.xpm", &img_width, &img_height);
	game->numbers[6] = mlx_xpm_file_to_image(game->mlx, \
		"textures/numbers/6.xpm", &img_width, &img_height);
	game->numbers[7] = mlx_xpm_file_to_image(game->mlx, \
		"textures/numbers/7.xpm", &img_width, &img_height);
	game->numbers[8] = mlx_xpm_file_to_image(game->mlx, \
		"textures/numbers/8.xpm", &img_width, &img_height);
	game->numbers[9] = mlx_xpm_file_to_image(game->mlx, \
		"textures/numbers/9.xpm", &img_width, &img_height);
	game->numbers[10] = NULL;
	if (!game->numbers[1] || !game->numbers[2] \
		|| !game->numbers[3] || !game->numbers[4] || !game->numbers[5] \
		|| !game->numbers[6] || !game->numbers[7] || !game->numbers[8] \
		|| !game->numbers[9] || init_player(game, img_height, img_width))
		return (1);
	return (0);
}
