/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:20:42 by mfrancoi          #+#    #+#             */
/*   Updated: 2017/02/08 17:32:42 by mfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>

int main()
{
	unsigned char c;
	wchar_t *i;
	int d;

	d = 25;
	i = L"Ж";
	c = 0xe1;
	write(1, &c, 1);
	c = 0x88;
	write(1, &c, 1);
	c = 0xb4;
	write(1, &c, 1);
	c = 0x0a;
	write(1, &c, 1);

	c = 0x04;
	write(1, &c, 1);
	c = 0x19;
	write(1, &c, 1);



	printf("%lu\n", sizeof(0x0e188b40a));
//	printf("%#X\n", i);
	//printf("%X\n", i);
	printf("%c\n", 97);
	printf("%C\n", 97);
	printf("%s\n", "connard");
	printf("%S\n", i);
	printf("%5d\n", d);
	printf("%D\n", d);
}
