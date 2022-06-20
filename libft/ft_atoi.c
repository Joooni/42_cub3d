/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:05:12 by jsubel            #+#    #+#             */
/*   Updated: 2022/06/20 09:52:57 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_whitespace(char c);

static int	check_calc_value(long res, int c, const char *str)
{
	res = (res * 10) + (str[c] - '0');
	if (res > 2147483647 || res < -2147483648)
		ft_end_process("Number is too high!");
	return ((int) res);
}

int	ft_atoi(const char *str)
{
	int	c;
	int	s;
	int	res;

	c = 0;
	s = 1;
	res = 0;
	while (is_whitespace(str[c]))
		c++;
	if (str[c] == '-' || str[c] == '+')
		if (str[c++] == '-')
			s = -1;
	while (str[c])
	{
		if (str[c] >= '0' && str[c] <= '9')
			res = check_calc_value(res, c, str);
		else if (str[c] == '\n')
			break ;
		else
			ft_end_process("Invalid character!");
		c++;
	}
	return (res * s);
}

static int	is_whitespace(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\r')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	return (0);
}
