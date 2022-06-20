/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:07:48 by jtomala           #+#    #+#             */
/*   Updated: 2022/06/18 12:51:11 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/fcntl.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);
char	*gnl_handler(int fd, char *buffer, char *output);
char	*ft_found_new_line(char *buffer, char *output);
char	*ft_realloc(char *s1, char *s2, int free_s1, int free_s2);
int		ft_copy(char *dst, char *src, int len);

#endif