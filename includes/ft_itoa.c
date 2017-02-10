/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeahoare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:26:51 by jeahoare          #+#    #+#             */
/*   Updated: 2017/02/09 15:12:39 by jeahoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(int nbr)
{
	int i;

	i = 1;
	while (nbr / 10 > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static void	ft_recursive(char *str, int nbr, int nb, int i)
{
	if (i > 0)
		ft_recursive(str, nbr / 10, nb, i - 1);
	str[i - 1] = (nbr % 10) + 48;
}

char		*ft_itoa(int nbr)
{
	int		nb;
	int		neg;
	char	*str;

	neg = 0;
	if (nbr == -2147483648)
	{
		str = (char *)malloc(sizeof(*str) * 11 + 1);
		str = "-2147483648";
		return (str);
	}
	else
	{
		if (nbr < 0)
		{
			neg++;
			nbr = nbr * -1;
		}
		nb = ft_size(nbr);
		if (neg == 1)
			nb++;
		str = (char *)malloc(sizeof(*str) * nb + 1);
		if (str == NULL)
			return (NULL);
		ft_recursive(str, nbr, nb, nb);
		if (neg == 1)
			str[0] = '-';
		str[nb] = '\0';
	}
	return (str);
}
