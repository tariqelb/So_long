/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:54:38 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 14:45:04 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_right_side(t_mlx *game, int i, int j)
{
	if (game->map[i][j + 1] == '1')
		return (0);
	else if (game->map[i][j + 1] == 'N')
		return (-1);
	else if (game->map[i][j + 1] == '0')
		return (1);
	else if (game->map[i][j + 1] == 'C')
	{
		game->tab[2]--;
		return (2);
	}
	else if (game->map[i][j + 1] == 'E')
		return (3);
	return (0);
}

int	ft_left_side(t_mlx *game, int i, int j)
{
	if (game->map[i][j - 1] == '1')
		return (0);
	else if (game->map[i][j - 1] == 'N')
		return (-1);
	else if (game->map[i][j - 1] == '0')
		return (1);
	else if (game->map[i][j - 1] == 'C')
	{
		game->tab[2]--;
		return (2);
	}
	else if (game->map[i][j - 1] == 'E')
		return (3);
	return (0);
}

int	ft_up(t_mlx *game, int i, int j)
{
	if (game->map[i - 1][j] == '1')
		return (0);
	else if (game->map[i - 1][j] == 'N')
		return (-1);
	else if (game->map[i - 1][j] == '0')
		return (1);
	else if (game->map[i - 1][j] == 'C')
	{
		game->tab[2]--;
		return (2);
	}
	else if (game->map[i - 1][j] == 'E')
		return (3);
	return (0);
}

int	ft_down(t_mlx *game, int i, int j)
{
	if (game->map[i + 1][j] == '1')
		return (0);
	else if (game->map[i + 1][j] == 'N')
		return (-1);
	else if (game->map[i + 1][j] == '0')
		return (1);
	else if (game->map[i + 1][j] == 'C')
	{
		game->tab[2]--;
		return (2);
	}
	else if (game->map[i + 1][j] == 'E')
		return (3);
	return (0);
}
