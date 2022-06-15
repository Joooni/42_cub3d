/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:07:48 by jtomala           #+#    #+#             */
/*   Updated: 2022/06/15 20:08:34 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#include <unistd.h>
#include <stdlib.h> //malloc
#include <stdio.h> //printf
#include <sys/fcntl.h> //RDONLY
#include "../libft/libft.h"

char *get_next_line(int fd);
char *gnl_handler(int fd, char *buffer, char *output);
char *ft_found_new_line(char *buffer, char *output);
char *ft_realloc(char *s1, char *s2, int free_s1, int free_s2);
int	ft_copy(char *dst, char *src, int len);

#endif