/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:32:12 by moaatik           #+#    #+#             */
/*   Updated: 2025/03/11 19:15:56 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_moves(t_game *game)
{
	write(1, "\r", 1);
	write(1, "number of movements : ", 22);
	put_nbr(game->moves);
}

void	move_up(t_game *game)
{
	if (game->player_x <= 1 || \
		game->map[game->player_x - 1][game->player_y] == '1')
		return ;
	if (game->map[game->player_x - 1][game->player_y] == 'C')
		game->collect--;
	game->map[game->player_x][game->player_y] = '0';
	game->map[game->player_x - 1][game->player_y] = 'P';
	game->moves++;
	print_moves(game);
	update(game);
}

void	move_down(t_game *game)
{
	if (game->player_x == game->map_x || \
		game->map[game->player_x + 1][game->player_y] == '1')
		return ;
	if (game->map[game->player_x + 1][game->player_y] == 'C')
		game->collect--;
	game->map[game->player_x][game->player_y] = '0';
	game->map[game->player_x + 1][game->player_y] = 'P';
	game->moves++;
	print_moves(game);
	update(game);
}

void	move_right(t_game *game)
{
	if (game->player_y == game->map_y || \
		game->map[game->player_x][game->player_y + 1] == '1')
	{
		game->direction = 1;
		return ;
	}
	if (game->map[game->player_x][game->player_y + 1] == 'C')
		game->collect--;
	game->map[game->player_x][game->player_y] = '0';
	game->map[game->player_x][game->player_y + 1] = 'P';
	game->moves++;
	game->direction = 1;
	print_moves(game);
	update(game);
}

void	move_left(t_game *game)
{
	if (game->player_y <= 1 || \
		game->map[game->player_x][game->player_y - 1] == '1')
	{
		game->direction = 0;
		return ;
	}
	if (game->map[game->player_x][game->player_y - 1] == 'C')
		game->collect--;
	game->map[game->player_x][game->player_y] = '0';
	game->map[game->player_x][game->player_y - 1] = 'P';
	game->moves++;
	game->direction = 0;
	print_moves(game);
	update(game);
}
