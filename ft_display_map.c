/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__display_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:16:37 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 15:26:41 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
