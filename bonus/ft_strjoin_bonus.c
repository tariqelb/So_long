/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:50:43 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 14:46:40 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	index_i;
	size_t	index_j;
	char	*joined;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined = NULL;
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *) malloc(sizeof(char) * (len + 1));
	if (joined == NULL)
		return (NULL);
	index_i = 0;
	index_j = 0;
	while (s1[index_j])
		joined[index_i++] = s1[index_j++];
	index_j = 0;
	while (s2[index_j])
		joined[index_i++] = s2[index_j++];
	joined[index_i] = 0;
	return (joined);
}
