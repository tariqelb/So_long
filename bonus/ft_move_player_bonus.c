/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:00:53 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 14:45:31 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_player_position(t_mlx *game, int **p_pos, char c)
{
	int	i;
	int	j;

	i = 0;
	while (++i < game->tab[1])
	{
		j = 0;
		while (++j < game->tab[0])
		{
			if (game->map[i][j] == 'P')
			{
				p_pos[0][0] = j;
				p_pos[0][1] = i;
				if (c == 'r')
					p_pos[0][2] = ft_right_side(game, i, j);
				else if (c == 'l')
					p_pos[0][2] = ft_left_side(game, i, j);
				else if (c == 'd')
					p_pos[0][2] = ft_down(game, i, j);
				else if (c == 'u')
					p_pos[0][2] = ft_up(game, i, j);
				return ;
			}
		}
	}
}

char	**ft_modify_map(char **map, int *pos, char c)
{
	map[pos[1]][pos[0]] = '0';
	if (c == 'r')
		map[pos[1]][pos[0] + 1] = 'P';
	else if (c == 'l')
		map[pos[1]][pos[0] - 1] = 'P';
	else if (c == 'd')
		map[pos[1] + 1][pos[0]] = 'P';
	else if (c == 'u')
		map[pos[1] - 1][pos[0]] = 'P';
	return (map);
}

void	ft_print_nbr_of_move(t_mlx **game)
{
	char	*str;
	char	*nbr;
	int		x;

	x = 64 * ((game[0]->tab[0] / 2) - 3);
	str = "The current number of movements ";
	nbr = ft_itoa(game[0]->nbr_of_move);
	str = ft_strjoin(str, nbr);
	if (nbr == NULL || str == NULL)
	{
		ft_printf("Error\nFail in memory allocation\n");
		ft_free(game[0]);
	}
	mlx_string_put(game[0]->mlx, game[0]->win, x, 10, 0xFFFFFF, str);
	free(nbr);
	free(str);
}

t_mlx	*ft_move_player(t_mlx **game, char c)
{
	int	*p_pos;

	p_pos = NULL;
	p_pos = (int *) malloc(sizeof(int) * 3);
	if (p_pos == NULL)
	{
		ft_printf("Error\nFail to allocate memory.");
		return (NULL);
	}	
	ft_player_position(game[0], &p_pos, c);
	if (p_pos[2] == -1 || (p_pos[2] == 3 && game[0]->tab[2] == 0))
	{
		if ((p_pos[2] == 3 && game[0]->tab[2] == 0))
			ft_printf("You win\nGame over\n");
		ft_free(game[0]);
	}
	else if (p_pos[2] == 1 || p_pos[2] == 2)
	{
		game[0]->map = ft_modify_map(game[0]->map, p_pos, c);
		game[0]->nbr_of_move++;
	}
	free(p_pos);
	return (game[0]);
}
