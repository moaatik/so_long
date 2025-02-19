/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:34:29 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/18 00:15:16 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(char *file)
{
	int	i;
	int	fd;

	i = 0;
	while (file[i] != '.')
		i++;
	if (!file[i])
		return (-1);
	i++;
	if (ft_strcmp(file + i, "ber"))
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

int	check_input(char *str)
{
	int		i;

	i = 0;
	if (!str[0])
		return (1);
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != '\n' \
			&& str[i] != 'C' && str[i] != 'E' && str[i] != 'P')
			return (1);
		i++;
	}
	return (0);
}

char	*get_map(int fd)
{
	char	*line;
	char	*temp;
	char	*map;

	line = get_next_line(fd);
	map = NULL;
	while (line)
	{
		temp = map;
		map = ft_strjoin(temp, line);
		free(line);
		free(temp);
		line = get_next_line(fd);
	}
	return (map);
}

char	**handle_input(char **av)
{
	int		fd;
	char	*map;
	char	**splitted_map;

	fd = check_file(av[1]);
	if (fd < 0)
		return (NULL);
	map = get_map(fd);
	if (!map || check_input(map))
		return (NULL);
	splitted_map = ft_split(map, '\n');
	free(map);
	return (splitted_map);
}
