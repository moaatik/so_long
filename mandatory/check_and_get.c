/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:34:29 by moaatik           #+#    #+#             */
/*   Updated: 2025/03/08 17:08:37 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(char *file)
{
	int	len;
	int	fd;

	len = ft_strlen(file);
	if (ft_strcmp(file + len - 4, ".ber"))
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
		if (!map || *line == '\n')
			return (free(temp), free(line), NULL);
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
		return (write(2, "Error\nwhile opening the file\n", 29), NULL);
	map = get_map(fd);
	if (!map)
		return (write(2, "Error\nwhile reading the file\n", 29), \
		close(fd), NULL);
	if (check_input(map))
		return (write(2, "Error\nUnknown element in map\n", 29), free(map), \
		close(fd), NULL);
	splitted_map = ft_split(map, '\n');
	if (!splitted_map)
		return (write(2, "Error\nFailed while splitting map\n", 33), free(map), \
		close(fd), NULL);
	free(map);
	close(fd);
	return (splitted_map);
}
