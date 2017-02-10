/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeahoare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:02:04 by jeahoare          #+#    #+#             */
/*   Updated: 2017/02/09 15:10:09 by jeahoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(unsigned int nbr, int base)
{
	int i;

	i = 1;
	while (nbr / base > 0)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}

static void	ft_recursive_min(char *str, unsigned int nbr, int base, int i)
{
	char *t;

	t = "0123456789abcdef";
	if (i > 0)
		ft_recursive_min(str, nbr / base, base, i - 1);
	str[i - 1] = t[nbr % base];
}

static void	ft_recursive_maj(char *str, unsigned int nbr, int base, int i)
{
	char *t;

	t = "0123456789ABCDEF";
	if (i > 0)
		ft_recursive_maj(str, nbr / base, base, i - 1);
	str[i - 1] = t[nbr % base];
}
char		*ft_itoa_base(unsigned int nbr, int base, char maj)
{
	int		nb;
	char	*str;

	nb = ft_size(nbr, base);
	str = (char *)malloc(sizeof(*str) * nb + 1);
	if (str == NULL)
		return (NULL);
	if (maj == 0)
		ft_recursive_min(str, nbr, base, nb);
	else
		ft_recursive_maj(str, nbr, base, nb);
	str[nb] = '\0';
	return (str);
}
