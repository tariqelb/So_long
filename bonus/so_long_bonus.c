/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:54:14 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 18:05:06 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_free_1(t_mlx *game)
{
	free(game->tab);
	free(game);
	return (1);
}

t_mlx	*ft_initialize_images(t_mlx *g)
{
	g->img_w = mlx_xpm_file_to_image(g->mlx, "g_bonus/w.xpm", &g->h, &g->w);
	g->img_s = mlx_xpm_file_to_image(g->mlx, "g_bonus/s.xpm", &g->h, &g->w);
	g->img_p = mlx_xpm_file_to_image(g->mlx, "g_bonus/p.xpm", &g->h, &g->w);
	g->img_c = mlx_xpm_file_to_image(g->mlx, "g_bonus/c.xpm", &g->h, &g->w);
	g->img_e = mlx_xpm_file_to_image(g->mlx, "g_bonus/e.xpm", &g->h, &g->w);
	g->img_en1 = mlx_xpm_file_to_image(g->mlx, "g_bonus/n1.xpm", &g->h, &g->w);
	g->img_en2 = mlx_xpm_file_to_image(g->mlx, "g_bonus/n2.xpm", &g->h, &g->w);
	g->img_en3 = mlx_xpm_file_to_image(g->mlx, "g_bonus/n3.xpm", &g->h, &g->w);
	g->img_en4 = mlx_xpm_file_to_image(g->mlx, "g_bonus/n4.xpm", &g->h, &g->w);
	g->img_en5 = mlx_xpm_file_to_image(g->mlx, "g_bonus/n5.xpm", &g->h, &g->w);
	g->img_en6 = mlx_xpm_file_to_image(g->mlx, "g_bonus/mm.xpm", &g->h, &g->w);
	g->img_en7 = mlx_xpm_file_to_image(g->mlx, "g_bonus/fk.xpm", &g->h, &g->w);
	if (g->img_w == NULL || g->img_s == NULL || g->img_p == NULL
		|| g->img_c == NULL || g->img_e == NULL || g->img_en1 == NULL
		|| g->img_en2 == NULL || g->img_en3 == NULL || g->img_en4 == NULL
		|| g->img_en5 == NULL || g->img_en6 == NULL || g->img_en7 == NULL)
	{
		ft_printf("Error\nFail to lead image\n");
		ft_free_1(g);
		mlx_destroy_window(g->mlx, g->win);
		return (NULL);
	}
	return (g);
}

int	ft_initialize(t_mlx *game, int *tab)
{
	int	i;

	game->w = 64;
	game->h = 64;
	game->emove = 0;
	game->nbr_of_move = 0;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (1);
	game->win = mlx_new_window(game->mlx, tab[0] * 64, tab[1] * 64, "Oska");
	if (game->win == NULL)
		return (1);
	game = ft_initialize_images(game);
	if (game == NULL)
		return (1);
	game->move = (int *) malloc(sizeof(int) * game->tab[1]);
	if (game->move == NULL)
	{
		ft_printf("Error\nFail in memory allocation\n");
		ft_free(game);
	}
	i = 0;
	while (i < game->tab[1])
		game->move[i++] = 0;
	return (0);
}

int	ft_get_map(char *av, int *tab, t_mlx **game)
{
	int	fd;
	int	i;

	fd = open(av, O_RDONLY);
	game[0]->map = NULL;
	game[0]->map = (char **) malloc(sizeof(char *) * (tab[1] + 1));
	if (game[0]->map == NULL)
	{
		ft_printf("Error\nFail in memory allocation\n");
		free(game[0]->tab);
		free(game[0]->move);
		free(game[0]);
		return (1);
	}
	i = -1;
	while (++i < tab[1])
	{
		game[0]->map[i] = get_next_line(fd);
		game[0]->map[i][tab[0]] = 0;
	}
	game[0]->map[i] = NULL;
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	*game;

	if (ac == 1)
		return (ft_printf("Error\nMessing Map file\n"));
	game = NULL;
	game = (t_mlx *) malloc(sizeof(t_mlx));
	if (game == NULL)
		return (ft_printf("Error\nFail to allocate memory."));
	game->file = av[1];
	if (ft_check_map("Error\n", &game->tab, game->file))
		return (ft_free_1(game));
	game->move = NULL;
	if (ft_initialize(&game[0], game->tab))
		return (1);
	if (ft_get_map(av[1], game->tab, &game) == 1)
		return (1);
	ft_display_map(game, game->map);
	mlx_hook(game->win, 17, 0, ft_destroy, &game);
	mlx_key_hook(game->win, ft_handle_key, &game);
	mlx_loop_hook(game->mlx, ft_enemy, &game);
	mlx_loop(game->mlx);
	return (0);
}
