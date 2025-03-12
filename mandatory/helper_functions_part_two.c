/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_part_two.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:59:23 by moaatik           #+#    #+#             */
/*   Updated: 2025/03/10 17:43:36 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	destroy_images(t_game *game)
{
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->ground)
		mlx_destroy_image(game->mlx, game->ground);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->coin)
		mlx_destroy_image(game->mlx, game->coin);
	free_strs(game->map);
}

void	ft_error(void)
{
	write(2, "Error\nFailed to load images\n", 28);
	exit(1);
}

void	put_nbr(int nbr)
{
	char	c;

	if (nbr > 9)
	{
		put_nbr(nbr / 10);
		put_nbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
}
