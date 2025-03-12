/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:05:23 by moaatik           #+#    #+#             */
/*   Updated: 2025/03/12 14:57:00 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**map;
	void	*ground;
	void	*wall;
	void	*exit[6];
	void	*coin[7];
	void	*numbers[11];
	void	*player[9];
	void	*rev_player[9];
	int		player_frame;
	int		counter;
	int		direction;
	int		coin_frame;
	int		all_coins;
	int		current_exit;
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

int		count(long i);
void	ft_error(void);
char	*ft_itoa(int n);
void	put_nbr(int nbr);
void	update(t_game *game);
void	free_strs(char **strs);
int		handle_frames(t_game *game);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);

char	*get_map(int fd);
int		check_file(char *file);
int		check_input(char *str);
void	render_map(t_game *game);
int		init_images(t_game *game);
char	**handle_input(char **av);
int		handle_cross(t_game *game);
void	destroy_images(t_game *game);
int		check_valid_path(t_game *game);
int		input(char **av, t_game *game);
int		key_press(int keycode, t_game *game);
int		init_numbers(t_game *game, int img_height, int img_width);

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
