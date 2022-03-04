/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:46:10 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 18:45:23 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int		i;
	int		bytes;
	char	nbr[10];

	i = 0;
	bytes = 0;
	if (nb == 0)
		return (ft_putstr("0"));
	if (nb < 0)
	{
		if (nb == -2147483648)
			return (ft_putstr("-2147483648"));
		else
			bytes += write(1, "-", 1);
		nb = nb * -1;
	}
	while (nb)
	{
		nbr[i++] = nb % 10 + 48;
		nb = nb / 10;
	}
	bytes += i;
	while (--i >= 0)
		write(1, &nbr[i], 1);
	return (bytes);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		bytes;

	va_start(args, str);
	i = 0;
	bytes = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				bytes += write(1, "%", 1);
			else if (str[i] == 's')
				bytes += ft_putstr(va_arg(args, char *));
			else if (str[i] == 'd')
				bytes += ft_putnbr(va_arg(args, int));
		}
		else
			bytes += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (bytes);
}
