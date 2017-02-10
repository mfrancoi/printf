/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:55:09 by mfrancoi          #+#    #+#             */
/*   Updated: 2017/02/10 16:24:24 by mfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_printf(const char *format, ...);

struct		s_return
{
	int		r;
	int		s;
}			t_r;

void		ft_putchar(char c);
void		ft_putstr(char *s);
void		ft_space_d(int t, va_list ap, int c);
void		ft_space_o(int t, va_list ap, int c);
void		ft_space_x(int t, va_list ap, int c);
void		ft_space_X(int t, va_list ap, int c);
void		ft_space_s(int t, va_list ap, int c);
void		ft_space_c(int t, va_list ap, int c);
void		ft_space_percent(int t, va_list ap, int c);
char		*ft_itoa(int nbr);
char		*ft_itoa_base(unsigned int nbr, int base, char maj);
size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);

#endif
