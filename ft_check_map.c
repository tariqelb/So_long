/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tariqelb093@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:59:20 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/03/04 12:13:15 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_at_less(int *map_cmp, char *err)
{
	if (map_cmp[2] < 1)
		return (ft_printf("%s%s\n", err, "At less one collectable"));
	if (map_cmp[3] < 1)
		return (ft_printf("%s%s\n", err, "At less one exit door"));
	if (map_cmp[4] != 1)
		return (ft_printf("%s%s\n", err, "This version handle only one player"));
	if (map_cmp[0] == map_cmp[1])
		return (ft_printf("%s%s\n", err, "bay--bay this is a square map"));
	return (0);
}

int	ft_check(int fd, int **map_comp, char *err)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		if (i == 1 || i == map_comp[0][1])
		{
			if (ft_check_wall(line, &map_comp[0], err))
				return (1);
		}
		else if (ft_check_line(line, &map_comp[0], err))
			return (1);
		free(line);
		line = get_next_line(fd);
	}
	if (ft_at_less(map_comp[0], err))
		return (1);
	return (0);
}

int	ft_file_extension(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (i < 5)
		return (0);
	if (av[i - 1] == 'r' && av[i - 2] == 'e' && av[i - 3] == 'b'
		&& av[i - 4] == '.')
		return (1);
	return (0);
}

int	ft_check_map(char *err, int	**map_comp, char *av)
{
	int	fd;
	int	fd2;

	map_comp[0] = NULL;
	map_comp[0] = (int *) malloc(sizeof(int) * 5);
	if (map_comp[0] == NULL)
		return (ft_printf("%s%s\n", err, "Fail in memory allocation."));
	fd = open(av, O_RDONLY);
	fd2 = open(av, O_RDONLY);
	if (fd < 0 || fd2 < 0)
		return (ft_printf("%s%s\n", err, "Opening .bar file failed"));
	if (ft_file_extension(av) == 0)
		return (ft_printf("%s%s\n", err, "Invalid file extension"));
	ft_number_of_line(map_comp, fd2);
	if (map_comp[0][1] < 2)
		return (ft_printf("%s%s\n", err, "Invalide number of lines in map"));
	if (ft_check(fd, map_comp, err))
		return (1);
	close(fd);
	close(fd2);
	return (0);
}
