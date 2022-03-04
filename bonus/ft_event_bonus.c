/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:19:09 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 14:43:59 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_handle_key(int key, t_mlx **game)
{
	char	c;

	c = 0;
	if (key == 123 || key == 0)
		c = 'l';
	else if (key == 124 || key == 2)
		c = 'r';
	else if (key == 125 || key == 1)
		c = 'd';
	else if (key == 126 || key == 13)
		c = 'u';
	else if (key == 53)
		ft_free(game[0]);
	else
		return (0);
	game[0] = ft_move_player(&game[0], c);
	mlx_clear_window(game[0]->mlx, game[0]->win);
	ft_display_map(game[0], game[0]->map);
	return (0);
}

int	ft_move_enemy(t_mlx **game, int i, int j)
{
	if (game[0]->map[i][j + 1] == 'P' || game[0]->map[i][j - 1] == 'P')
	{
		ft_printf("You lose\nGame over\n");
		ft_free(game[0]);
	}
	if (game[0]->map[i][j + 1] != '0' && game[0]->map[i][j + 1] != 'P')
		game[0]->move[i] = 1;
	if (game[0]->map[i][j - 1] != '0' && game[0]->map[i][j - 1] != 'P')
		game[0]->move[i] = 0;
	if (game[0]->move[i] == 0 && game[0]->map[i][j + 1] == '0')
	{
		game[0]->map[i][j] = '0';
		game[0]->map[i][j + 1] = 'N';
		return (1);
	}
	if (game[0]->move[i] == 1 && game[0]->map[i][j - 1] == '0')
	{
		game[0]->map[i][j] = '0';
		game[0]->map[i][j - 1] = 'N';
		return (-1);
	}
	return (0);
}

int	ft_enemy(t_mlx **game)
{
	int	i;
	int	j;

	if (game[0]->emove == 5000)
	{
		i = 0;
		while (game[0]->map[++i])
		{
			j = 0;
			while (game[0]->map[i][++j])
			{
				if (game[0]->map[i][j] == 'N')
					if (ft_move_enemy(game, i, j) == 1)
						j++;
			}
		}
		ft_display_map(game[0], game[0]->map);
		game[0]->emove = 0;
	}
	game[0]->emove++;
	return (0);
}

void	ft_free(t_mlx *game)
{
	int	i;

	i = 0;
	while (i < game->tab[1])
	{
		free(game->map[i]);
		i++;
	}
	free(game->move);
	free(game->tab);
	free(game->map[i]);
	free(game->map);
	free(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	ft_destroy(t_mlx **game)
{
	ft_free(game[0]);
	return (0);
}
