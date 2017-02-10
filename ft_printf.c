/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:33:43 by mfrancoi          #+#    #+#             */
/*   Updated: 2017/02/08 19:11:30 by mfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//////////////////////////////////== START ==///////////////////////////////////////
/*             FONCTION DE LIB - NOUVELLES OU MOFIDIEES OU ANCIENNES              */
////////////////////////////////////////////////////////////////////////////////////

void	ft_putchar(char c)  // ft_putchar : - JE VEUX GERER L UNICODE !
{
	t_r.r++;
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		ft_putchar(s[i]);  // Unicode ... 
}

int		ft_size(int nbr)
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

void	ft_recursive(char *str, int nbr, int nb, int i)
{
	if (i > 0)
		ft_recursive(str, nbr / 10, nb, i - 1);
	str[i - 1] = (nbr % 10) + 48;
}

char	*ft_itoa(int nbr)
{
	int		nb;
	int		neg;
	char	*str;

	neg = 0;
	if (nbr == -2147483648)
	{
		str = (char *)malloc(sizeof(*str) * 11 + 1);
		str[0] = '-';
		str[1] = '2';
		str[2] = '1';
		str[3] = '4';
		str[4] = '7';
		str[5] = '4';
		str[6] = '8';
		str[7] = '3';
		str[8] = '6';
		str[9] = '4';
		str[10] = '8';
		str[11] = '\0';
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

////////////////////////////////////== END ==////////////////////////////////////////
/*                            FONCTION DE LIB AU DESSUS                            */
/////////////////////////////////////////////////////////////////////////////////////
/*
int		ft_space(const char *str, int end, va_list ap)
{
	int t;
	int i;
	i = end;
	while (str[i] >= 0 && str[i] >= 9)
		i++;
	if (str[end] == '0')
	{
		end++;
		if
	}
	else
	{
		t = ft_atoi(str + end);
		while ( t != 0)
		{
			ft_putchar(' ');
		}
	}

	return (i);
}
*/

void		ft_dieze(char c)
{
	if (c == 'o')
		ft_putchar('0');
	if (c == 'x')
		ft_putstr("0x");
	if (c == 'X')
		ft_putstr("0X");
}

int	ft_check(const char *str, va_list ap)
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
			else if (str[end] == 'd' || str[end] == 'D')
				ft_putstr(ft_itoa(va_arg(ap, int)));
			else if (str[end] == 's')
				ft_putstr(va_arg(ap, char *));
			else if (str[end] == 'c' || str[end] == 'C')
				ft_putchar(va_arg(ap, int));
			else if (str[end] == '%')
				ft_putstr("%");
	//		else if (str[end] >= 0 && str[end] <= 9)
	//			end += ft_space(*str, end, ap);
			else					// BOF.Seulement si il faut gerer les cas d erreur.
				return (0);         // BOF.Seulement si il faut gerer les cas d erreur.
			end++;
		}
		else
			ft_putchar(str[end++]);
	}
	return (0);
}

int		ft_printf(const char * format, ...)
{
	t_r.r = 0;
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	if (format)
		len = ft_check(format, ap); // Faut renvoyer la longueur totale.
	va_end(ap);
	return (t_r.r);
}

int main()
{
	int vrai;
	int res;
	int		nb = 100;
	char	*sentence = "Bonne journee.";
	  
		// TEST : RIEN [OK]
		// Retour de longueur {OK}
	ft_printf("");

		// TEST : %d [OK] ||  %s [OK] ||  et chaine simple : [OK]  || Double % pour ecrire un [OK]
		// Retour de longueur {OK}
	ft_printf("Il y a %d et demi %s dans le mixeur.\nA peu pres 99%% ne seront pas contents.", 65, "sac a merde");
	ft_printf("\n.    .\nUn, %s, %d, S%sleil.\n", "deux", 3, "0");

		// TEST : Variable INT : [OK]  || Variable CHAR * : [OK] || Variable CHAR : [OK]
		// Retour de longueur {OK}
	res = ft_printf("Au final%c:%c %d%% ont ete traite.\n%c%s%c", ' ', ' ', nb, '\n', sentence, '\n');

		// TEST : ft_printf imbrique avec phrase simple : [OK]
		// Retour de longueur {OK}
	ft_printf("\nPour l instant la fonction retourne de la merde, genre : %d", ft_printf("\nTest 1."));
	ft_printf("\n\n");

		// TEST : ft_printf imbrique dans d autre ft_printf imbrique avec variable : [OK]
		// Retour de longueur {OK}
	ft_printf("Test_0 : [%d]\n", ft_printf("Test_1 : [%d] Test_2 : [%d] ", ft_printf("Test_3 : "),	ft_printf("Test_4 : ")));
	ft_printf("\n\n");
	ft_printf("\n\n");
	ft_printf("\n\n");
	ft_printf("%d%s ", 46, "bidule");
	ft_printf("\n\n");
	ft_printf("%d\n", res);
	ft_printf("\n\n");
	ft_printf("\n\n");
	char g = 65;
	printf("%+\n", g);
	return 0;
}
