/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:33:43 by mfrancoi          #+#    #+#             */
/*   Updated: 2017/02/10 16:30:37 by mfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>  // A SUPPRIMER


int		ft_space(const char *str, int end, va_list ap)
{
	int c;
	int t;
	int i;

	c = 32;
	i = end;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i = i - end;
	if (str[end] == '0')
	{
		end++;
		c = 48;
		i--;
	}
		t = ft_atoi(str + end);
		if (str[end + i] == 'd' || str[end + i] == 'D' || str[end + i] == 'i')
			ft_space_d(t, ap, c);
		else if (str[end + i] == 'o')
			ft_space_o(t, ap, c);
		else if (str[end + i] == 'x')
			ft_space_x(t, ap, c);
		else if (str[end + i] == 'X')
			ft_space_X(t, ap, c);
		else if (str[end + i] == 's')
			ft_space_s(t, ap, c);
		else if (str[end + i] == 'c' || str[end + i] == 'C')
			ft_space_c(t, ap, c);
		else if (str[end + i] == '%')
			ft_space_percent(t, ap, c);
	//	ft_putchar(' ');
		if (c== 48)
			i++;
return (i);
}


static void		ft_dieze(char c)
{
	if (c == 'o')
		ft_putchar('0');
	if (c == 'x')
		ft_putstr("0x");
	if (c == 'X')
		ft_putstr("0X");
}

static void	ft_check(const char *str, va_list ap)
{
	int	end;

	end = 0;
	while (str[end])
	{
		if (str[end] == '%')
		{
			end++;
			if (str[end] == ' ')
			{
				while (str[end] == ' ')
					end++;
				ft_putchar(' ');
			}
			if (str[end] == '#')
			{
				ft_dieze(str[end + 1]);
				end++;
			}
			else if (str[end] == '-')
			{
				t_r.s = 1;
				end++;
				end += ft_space(str, end, ap);
			}
			else if (str[end] >= '0' && str[end] <= '9')
			{
				end += ft_space(str, end, ap);
			}
			else if (str[end] == 'd' || str[end] == 'D' || str[end] == 'i')
				ft_putstr(ft_itoa(va_arg(ap, int)));
			else if (str[end] == 'o')
				ft_putstr(ft_itoa_base(va_arg(ap, int), 8, 0));
			else if (str[end] == 'x')
				ft_putstr(ft_itoa_base(va_arg(ap, int), 16, 0));
			else if (str[end] == 'X')
				ft_putstr(ft_itoa_base(va_arg(ap, int), 16, 1));
			else if (str[end] == 's')
				ft_putstr(va_arg(ap, char *));
			else if (str[end] == 'c' || str[end] == 'C')
				ft_putchar(va_arg(ap, int));
			else if (str[end] == '%')
				ft_putstr("%");
			//		else if (str[end] >= 0 && str[end] <= 9)
			//			end += ft_space(*str, end, ap);
			else					// BOF.Seulement si il faut gerer les cas d erreur.
				return ;         // BOF.Seulement si il faut gerer les cas d erreur.
			end++;
		}
		else
			ft_putchar(str[end++]);
	}
}

int		ft_printf(const char *format, ...)
{
	t_r.r = 0;
	t_r.s = 0;
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	if (format)
		ft_check(format, ap);
	va_end(ap);
	return (t_r.r);
}
