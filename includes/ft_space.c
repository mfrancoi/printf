/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:36:13 by mfrancoi          #+#    #+#             */
/*   Updated: 2017/02/10 16:41:08 by mfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_space_d(int t, va_list ap, int c)
{
	char *str;

	str = ft_itoa(va_arg(ap, int));
	if (t_r.s == 0)
	{
		while (ft_strlen(str) < t)
		{
			ft_putchar(c);
			t--;
		}
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
		while (ft_strlen(str) < t)
		{
			ft_putchar(32);
			t--;
		}
	}
}

void	ft_space_o(int t, va_list ap, int c)
{
	char *str;

	str = ft_itoa_base(va_arg(ap, int), 8, 0);
	if (t_r.s == 0)
	{
		while (ft_strlen(str) < t)
		{
			ft_putchar(c);
			t--;
		}
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
		while (ft_strlen(str) < t)
		{
			ft_putchar(32);
			t--;
		}
	}
}

void	ft_space_x(int t, va_list ap, int c)
{
	char *str;

	str = ft_itoa_base(va_arg(ap, int), 16 ,0);
	if (t_r.s == 0)
	{
		while (ft_strlen(str) < t)
		{
			ft_putchar(c);
			t--;
		}
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
		while (ft_strlen(str) < t)
		{
			ft_putchar(32);
			t--;
		}
	}
}

void	ft_space_X(int t, va_list ap, int c)
{
	char *str;

	str = ft_itoa_base(va_arg(ap, int), 16 ,1);
	if (t_r.s == 0)
	{
		while (ft_strlen(str) < t)
		{
			ft_putchar(c);
			t--;
		}
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
		while (ft_strlen(str) < t)
		{
			ft_putchar(32);
			t--;
		}
	}
}

void	ft_space_s(int t, va_list ap, int c)
{
	char *str;

	str = va_arg(ap, char *);
	if (t_r.s == 0)
	{
		while (ft_strlen(str) < t)
		{
			ft_putchar(c);
			t--;
		}
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
		while (ft_strlen(str) < t)
		{
			ft_putchar(32);
			t--;
		}
	}
}

void	ft_space_c(int t, va_list ap, int c)
{
	char str;

	str = va_arg(ap, int);
	if (t_r.s == 0)
	{
		while (1 < t)
		{
			ft_putchar(c);
			t--;
		}
		ft_putchar(str);
	}
	else
	{
		ft_putchar(str);
		while (1 < t)
		{
			ft_putchar(32);
			t--;
		}
	}
}

void	ft_space_percent(int t, va_list ap, int c)
{
	char str;

	str = '%';
	if (t_r.s == 0)
	{
		while (1 < t)
		{
			ft_putchar(c);
			t--;
		}
		ft_putchar(str);
	}
	else
	{
		ft_putchar(str);
		while (1 < t)
		{
			ft_putchar(32);
			t--;
		}
	}
}
