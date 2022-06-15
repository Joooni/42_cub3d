/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:30:30 by jtomala           #+#    #+#             */
/*   Updated: 2021/12/21 09:03:50 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_save_buffer(int fd, char *tmp)
{
	int		read_done;
	char	*buff_part;

	read_done = 1;
	while ((read_done != 0) && (ft_strchr(tmp, '\n') == 0))
	{
		buff_part = (char *)ft_calloc ((BUFFER_SIZE + 1), sizeof(char));
		if (buff_part == 0)
			return (0);
		read_done = read(fd, buff_part, BUFFER_SIZE);
		if (read_done == -1)
		{
			free(buff_part);
			return (0);
		}
		else if (read_done > 0)
			tmp = ft_strjoin(tmp, buff_part);
		else
			free(buff_part);
	}
	return (tmp);
}

static char	*ft_save_line(char *tmp)
{
	char	*line;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(tmp);
	if (size == 0)
		return (0);
	line = (char *)ft_calloc ((1 + size), sizeof(char));
	while (i < size)
	{
		line[i] = tmp[i];
		i++;
	}
	return (line);
}

static char	*ft_trim_tmp(char *tmp)
{
	int		len;
	int		i;
	int		j;
	char	*new_tmp;

	i = 0;
	j = 0;
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\0' || tmp[0] == '\0')
	{
		free(tmp);
		return (0);
	}
	len = 0;
	while (tmp[i + 1 + len] != '\0')
		len++;
	new_tmp = (char *)ft_calloc((len + 1), sizeof(char));
	while (j < len)
	{
		new_tmp[j] = tmp[i + 1 + j];
		j++;
	}
	free(tmp);
	return (new_tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	tmp = ft_save_buffer(fd, tmp);
	if (tmp == 0)
		return (0);
	line = ft_save_line(tmp);
	tmp = ft_trim_tmp(tmp);
	return (line);
}

// int	main(void)
// {
// 	int	fd = open("file", O_RDONLY);
// 	char *line;

// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	return (0);
// }
