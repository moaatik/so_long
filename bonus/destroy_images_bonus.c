/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:36:50 by moaatik           #+#    #+#             */
/*   Updated: 2025/03/12 15:28:41 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_player(t_game *game)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if (game->player[i])
			mlx_destroy_image(game->mlx, game->player[i]);
		i++;
	}
	i = 0;
	while (i <= 7)
	{
		if (game->rev_player[i])
			mlx_destroy_image(game->mlx, game->rev_player[i]);
		i++;
	}
}

void	destroy_numbers_coins_exit(t_game *game)
{
	int	i;

	i = 0;
	while (i <= 9)
	{
		if (game->numbers[i])
			mlx_destroy_image(game->mlx, game->numbers[i]);
		i++;
	}
	i = 0;
	while (i <= 5)
	{
		if (game->coin[i])
			mlx_destroy_image(game->mlx, game->coin[i]);
		i++;
	}
	i = 0;
	while (i <= 4)
	{
		if (game->exit[i])
			mlx_destroy_image(game->mlx, game->exit[i]);
		i++;
	}
}

void	destroy_images(t_game *game)
{
	if (game->ground)
		mlx_destroy_image(game->mlx, game->ground);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	destroy_numbers_coins_exit(game);
	destroy_player(game);
	free_strs(game->map);
}
