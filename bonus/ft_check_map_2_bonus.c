/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:39:15 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/03/03 21:08:14 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_line(char *line, int **map_cmp, char *err)
{
	int	i;
	int	len;

	len = ft_strlen(line) - 1;
	if (len != map_cmp[0][0])
		return (ft_printf("%s%s\n", err, "map is not rectangular"));
	if (line[0] != '1' || line[len - 1] != '1')
		return (ft_printf("%s%s\n", err, "incomplete vertical wall"));
	i = -1;
	while (line[++i + 1])
	{
		if (line[i] == 'C')
			map_cmp[0][2]++;
		else if (line[i] == 'E')
			map_cmp[0][3]++;
		else if (line[i] == 'P')
			map_cmp[0][4]++;
		else if (line[i] == 'N')
			map_cmp[0][5]++;
		else if (line[i] == '0' || line[i] == '1')
			i = i + 0;
		else
			return (ft_printf("%s%s\n", err, "unknown key"));
	}
	return (0);
}

int	ft_check_wall(char *line, int **map_cmp, char *err)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '1')
			return (ft_printf("%s%s\n", err, "Invalide wall"));
		i++;
	}
	if (map_cmp[0][0] < 3)
		return (ft_printf("%s%s\n", err, "Incomplite map"));
	if (i != map_cmp[0][0])
		return (ft_printf("%s%s\n", err, "Incomplite wall"));
	return (0);
}

void	ft_number_of_line(int **map_cmp, int fd)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	while (i < 6)
		map_cmp[0][i++] = 0;
	line = get_next_line(fd);
	if (line != NULL)
		map_cmp[0][0] = ft_strlen(line) - 1;
	i = 0;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	map_cmp[0][1] = i;
}
