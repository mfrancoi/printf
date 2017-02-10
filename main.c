/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:20:42 by mfrancoi          #+#    #+#             */
/*   Updated: 2017/02/10 17:27:55 by mfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include "includes/ft_printf.h"

int main()
{
	int		vrai;
	int		res;
	int     nb = 100;
	char    *sentence = "Bonne journee.";
	int		intmin = -2147483648;

	ft_printf("");

	ft_printf("Il y a %d et demi %s dans le mixeur.\nA peu pres 99%% ne seront pas contents.", 65, "sac a merde");
	ft_printf("\n.    .\nUn, %s, %d, S%sleil.\n", "deux", 3, "0");
	res = ft_printf("Au final%c:%c %d%% ont ete traite.\n%c%s%c", ' ', ' ', nb, '\n', sentence, '\n');

	ft_printf("\nPour l instant la fonction retourne de la merde, genre : %d", ft_printf("\nTest 1."));
	ft_printf("\n\n");

	ft_printf("Test_0 : [%d]\n", ft_printf("Test_1 : [%d] Test_2 : [%d] ", ft_printf("Test_3 : "),  ft_printf("Test_4 : ")));
	ft_printf("\n\n");
	ft_printf("\n\n");
	ft_printf("%i\n", 65);
	printf("%5d\n", 65);
	ft_printf("\n\n");
	ft_printf("\n\n");
	ft_printf("|%-5%|\n", 65);
	ft_printf("\n\n");
	ft_printf("\n\n");
	ft_printf("Il y a %d et demi %s dans le mixeur.\nA peu pres 99%% ne seront pas contents.", 65, "sac a merde");
	ft_printf("\n.    .\nUn, %s, %d, S%sleil.\n", "deux", 3, "0");
	res = ft_printf("Au final%c:%c %d%% ont ete traite.\n%c%s%c", ' ', ' ', nb, '\n', sentence, '\n');
	return 0;
}
