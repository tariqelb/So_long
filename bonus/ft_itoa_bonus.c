/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:08:50 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 14:44:25 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static size_t	ft_length(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	char	*ft_nbr_to_str(char *nbr, int n, int sign, int len)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			nbr[--len] = 56;
			n = n / 10;
		}
		n = n * -1;
	}
	while (n)
	{
		nbr[--len] = n % 10 + 48;
		n /= 10;
	}
	if (sign)
		nbr[--len] = '-';
	return (nbr);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*nbr;
	int		sign;

	nbr = NULL;
	sign = 0;
	if (n < 0)
		sign = 1;
	len = ft_length(n) + sign;
	nbr = (char *) malloc(sizeof(char) * (len + 1));
	if (nbr == NULL)
		return (NULL);
	nbr[len] = '\0';
	if (n == 0)
	{
		nbr[0] = 48;
		return (nbr);
	}
	nbr = ft_nbr_to_str(nbr, n, sign, len);
	return (nbr);
}
