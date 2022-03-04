/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:46:05 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 15:24:23 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img_w;
	void	*img_s;
	void	*img_p;
	void	*img_c;
	void	*img_e;
	int		h;
	int		w;
	char	**map;
	int		*tab;
	char	*file;
	int		nbr_of_move;
}				t_mlx;

int		ft_check(int fd, int **map_comp, char *err);
void	ft_number_of_line(int **map_cmp, int fd);
int		ft_check_wall(char *line, int **map_cmp, char *err);
int		ft_check_line(char *line, int **map_cmp, char *err);
int		ft_check_map(char *err, int **tab, char *av);
void	ft_display_map(t_mlx *game, char **map);
void	ft_player_position(t_mlx *game, int **p_pos, char c);
char	**ft_modify_map(char **map, int *pos, char c);
t_mlx	*ft_move_player(t_mlx **game, char c);
void	ft_print_nbr_of_move(t_mlx **game);
int		ft_handle_key(int key, t_mlx **game);
int		ft_destroy(t_mlx **game);
void	ft_free(t_mlx *game);
int		ft_down(t_mlx *game, int i, int j);
int		ft_up(t_mlx *game, int i, int j);
int		ft_left_side(t_mlx *game, int i, int j);
int		ft_right_side(t_mlx *game, int i, int j);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_printf(const char *str, ...);

#endif
