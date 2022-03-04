/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:16:37 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 14:43:37 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*en(t_mlx *game, int n)
{
	if (n == 0)
		return (game->img_en1);
	else if (n == 1 || n == 7 || n == 13)
		return (game->img_en2);
	else if (n == 2 || n == 8 || n == 14)
		return (game->img_en3);
	else if (n == 3 || n == 9 || n == 15)
		return (game->img_en4);
	else if (n == 4 || n == 10 || n == 16)
		return (game->img_en5);
	else if (n == 5 || n == 11 || n == 17)
		return (game->img_en6);
	else if (n == 6 || n == 12 || n == 18)
		return (game->img_en7);
	else
		return (game->img_en7);
}

int	ft_display_image(t_mlx *g, int n, int i, int j)
{
	if (g->map[i][j] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img_w, 64 * j, 64 * i);
	if (g->map[i][j] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->img_s, 64 * j, 64 * i);
	if (g->map[i][j] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img_p, 64 * j, 64 * i);
	if (g->map[i][j] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img_c, 64 * j, 64 * i);
	if (g->map[i][j] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img_e, 64 * j, 64 * i);
	if (g->map[i][j] == 'N')
	{
		mlx_put_image_to_window(g->mlx, g->win, en(g, n), 64 * j, 64 * i);
		n++;
	}
	ft_print_nbr_of_move(&g);
	return (n);
}

void	ft_display_map(t_mlx *game, char **map)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			n = ft_display_image(game, n, i, j);
			j++;
		}
		i++;
	}
}
