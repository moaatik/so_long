/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:26:36 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/20 00:03:41 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	**copy_map(t_game *game)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (game->map_x + 1));
	if (!map)
		return (NULL);
	while (i < game->map_x)
	{
		map[i] = malloc(game->map_y + 1);
		if (!map[i])
		{
			free_strs(map);
			return (NULL);
		}
		ft_strcpy(map[i], game->map[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	flood_fill(char **map, int point_x, int point_y, t_game *game)
{
	char	c;

	if (point_x < 0 || point_y < 0 || point_x >= game->map_x \
		|| point_y >= game->map_y)
		return ;
	c = map[point_x][point_y];
	if (c == 'X' || c == '1')
		return ;
	if (c == 'P' || c == 'C' || c == 'E' || c == '0')
		map[point_x][point_y] = 'X';
	flood_fill(map, point_x + 1, point_y, game);
	flood_fill(map, point_x, point_y + 1, game);
	flood_fill(map, point_x - 1, point_y, game);
	flood_fill(map, point_x, point_y - 1, game);
}

int	check_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'E' || map[x][y] == 'C' || map[x][y] == 'P')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int	check_valid_path(t_game *game)
{
	char	**map;
	int		begin_x;
	int		begin_y;

	begin_x = game->player_x;
	begin_y = game->player_y;
	map = copy_map(game);
	if (!map)
		return (1);
	flood_fill(map, begin_x, begin_y, game);
	if (check_map(map))
	{
		free_strs(map);
		return (1);
	}
	free_strs(map);
	return (0);
}
