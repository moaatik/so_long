/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:05:23 by moaatik           #+#    #+#             */
/*   Updated: 2025/02/20 00:19:07 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <limits.h>

# define TILE_SIZE 64

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**map;
	void	*player;
	void	*ground;
	void	*exit_closed;
	void	*wall;
	void	*coin;
	int		player_x;
	int		player_y;
	int		map_x;
	int		map_y;
	int		exit_x;
	int		exit_y;
	int		collect;
	int		img_size;
	int		moves;
}			t_game;

void	ft_error(void);
void	put_nbr(int nbr);
void	update(t_game *game);
void	free_strs(char **strs);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);

char	*get_map(int fd);
int		check_file(char *file);
int		check_input(char *str);
void	render_map(t_game *game);
int		init_images(t_game *game);
char	**handle_input(char **av);
void	destroy_images(t_game *game);
int		check_valid_path(t_game *game);
int		input(char **av, t_game *game);
int		key_press(int keycode, t_game *game);

void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
