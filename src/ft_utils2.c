/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:59:24 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/22 14:14:42 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_realloc(char *str, int size)
{
	char	*new;
	int		i;

	new = ft_calloc(size + 1, sizeof(char));
	if (!new)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (str[++i])
		new[i] = str[i];
	free(str);
	return (new);
}

char	*gnl_return(char **line, char *c, int i)
{
	if (i == 0 && *c == '\n')
	{
		*line[i] = *c;
		return (*line);
	}
	if (i == 0)
	{
		free(*line);
		return (NULL);
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	char	c;
	char	*line;
	int		i;

	line = ft_calloc(1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			break ;
		line = ft_realloc(line, i + 2);
		if (!line)
			return (NULL);
		line[i++] = c;
	}
	return (gnl_return(&line, &c, i));
}
