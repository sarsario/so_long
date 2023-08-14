/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:05:14 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/14 16:14:34 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	ft_read(int fd, char **str)
{
	char	*buff;
	char	*temp;
	int		ret;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	ret = read(fd, buff, BUFFER_SIZE);
	if (ret == -1)
	{
		free(buff);
		return (-1);
	}
	buff[ret] = '\0';
	temp = ft_strjoin(*str, buff);
	free(*str);
	*str = temp;
	free(buff);
	return (ret);
}

static int	ft_line(char **str, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
	{
		*line = ft_substr(*str, 0, i);
		temp = ft_strdup(&((*str)[i + 1]));
		free(*str);
		*str = temp;
		if ((*str)[0] == '\0')
			ft_free(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_free(str);
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!str)
		str = ft_strdup("");
	ret = 1;
	while (ret > 0 && !ft_strchr(str, '\n'))
		ret = ft_read(fd, &str);
	if (ret == -1)
		return (-1);
	return (ft_line(&str, line));
}
