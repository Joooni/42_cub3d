/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:36:41 by jtomala           #+#    #+#             */
/*   Updated: 2022/06/15 18:39:28 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_or(const char *s)
{
	int	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	if (s == 0)
		return (0);
	i = 0;
	len = ft_strlen_or(s);
	while (i <= len)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
