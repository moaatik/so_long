/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_get_part_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:48:12 by moaatik           #+#    #+#             */
/*   Updated: 2025/03/10 14:59:49 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_borders(char **map, t_game *game)
{
	int	x;
	int	y;

	update(game);
	x = 0;
	while (x < game->map_x)
	{
		y = 0;
		while (y < game->map_y)
		{
			if (game->map_y > 128 || game->map_x >= game->map_y \
			|| ft_strlen(map[x]) < game->map_y \
			|| map[0][y] != '1' || map[x][0] != '1' \
			|| map[game->map_x - 1][y] != '1' || map[x][game->map_y - 1] != '1')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int	check_all_elements(char **map, int *found, int x, int y)
{
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '1')
				found[0] = 1;
			else if (map[x][y] == 'E')
				found[1] += 1;
			else if (map[x][y] == 'C')
				found[2] = 1;
			else if (map[x][y] == 'P')
				found[3] += 1;
			y++;
		}
		x++;
	}
	if (found[0] && found[1] == 1 && found[2] && found[3] == 1)
		return (0);
	if (found[1] > 1 || found[3] > 1)
		return (write(2, "Error\nExit or player duplicated\n", 32), 1);
	return (write(2, "Error\nNot all required elements exist\n", 38), 1);
}

int	check_all_elements_exist(char **map)
{
	int	x;
	int	y;
	int	found[4];

	if (!map || !map[0])
		return (1);
	x = 0;
	while (x < 4)
		found[x++] = 0;
	x = 0;
	y = 0;
	return (check_all_elements(map, found, x, y));
}

int	input(char **av, t_game *game)
{
	game->map = handle_input(av);
	if (!game->map)
		return (1);
	if (check_borders(game->map, game))
		return (write(2, "Error\nSomething wrong with map's borders\n", 41), \
		free(game->map), 1);
	if (check_all_elements_exist(game->map))
		return (free(game->map), 1);
	if (check_valid_path(game))
		return (write(2, "Error\nThe map should have a valid path\n", 39), \
		free(game->map), 1);
	update(game);
	return (0);
}

int	handle_cross(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	destroy_images(game);
	exit(0);
	return (0);
}
