/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:07:17 by jtomala           #+#    #+#             */
/*   Updated: 2022/06/15 20:10:34 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *output;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	output = (char *) malloc(BUFFER_SIZE + 1);
	if (!output)
		return (NULL);
	output[0] = '\0';
	return (gnl_handler(fd, buffer, output));
}

char *gnl_handler(int fd, char *buffer, char *output)
{
	ssize_t read_result;

	while (1)
	{
		if (buffer[0])
		{
			if (ft_strchr(buffer, '\n'))
				return (ft_found_new_line(buffer, output));
			output = ft_realloc(output, buffer, 1, 0);
		}
		read_result = read(fd, (void *) buffer, BUFFER_SIZE);
		if (read_result == -1 || (read_result == 0 && output[0] == '\0'))
		{
			free(output);
			return (NULL);
		}
		buffer[read_result] = '\0';
		if (read_result == 0)
			return (output);
	}
}

char *ft_found_new_line(char *buffer, char *output)
{
	int copy_size;
	char *tmp;

	copy_size = (ft_strchr(buffer, '\n') - buffer) + 1;
	tmp = (char *) malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	ft_copy(tmp, buffer, copy_size + 1);
	output = ft_realloc(output, tmp, 1, 1);
	ft_copy(buffer, &buffer[copy_size], 0);
	return (output);
}

char *ft_realloc(char *s1, char *s2, int free_s1, int free_s2)
{
	int s1_len;
	int s2_len;
	char *output;
	int i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	output = (char *) malloc(s1_len + s2_len + 1);
	if (!output)
		return (NULL);
	i = ft_copy(output, s1, 0);
	ft_copy(&output[i], s2, 0);
	if (free_s1)
		free(s1);
	if (free_s2)
		free(s2);
	return (output);
}

int	ft_copy(char *dst, char *src, int len)
{
	int i;

	i = 0;
	if (len == 0)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		len--;
		while (i < len && src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (i);
}

// int main(void)
// {
// 	int fd = open("file", O_RDONLY);
// 	printf("%d\n", fd);
// 	char *line = get_next_line(fd);
// 	printf("%s\n", line);
// 	return (0);
// }