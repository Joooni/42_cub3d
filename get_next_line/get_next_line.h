/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:09:55 by jtomala           #+#    #+#             */
/*   Updated: 2022/06/15 18:39:48 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h> //printf
# include <fcntl.h> //open
# include "../libft/libft.h"

char	*get_next_line(int fd);
size_t	ft_strlen_or(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif