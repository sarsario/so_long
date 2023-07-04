/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:43:31 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/04 10:44:06 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen2(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*s++)
		len++;
	return (len);
}

void	ft_substr2(t_file *file, int start)
{
	size_t	s_len;
	size_t	i;

	if (file->buffer[0])
	{
		s_len = ft_strlen2(file->buffer);
		i = 0;
		while (i + start < s_len)
		{
			file->buffer[i] = file->buffer[i + start + 1];
			i++;
		}
		file->buffer[i] = 0;
	}
}

char	*ft_strdup2(char *s)
{
	char	*dup;
	size_t	i;

	if (!s)
	{
		dup = malloc(sizeof(char) * 1);
		if (!dup)
			return (NULL);
		dup[0] = 0;
		return (dup);
	}
	i = ft_strlen2(s);
	dup = malloc(sizeof(char) * (1 + i));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*join;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup2(s2));
	if (!s2)
		return (s1);
	len_s1 = ft_strlen2(s1);
	len_s2 = ft_strlen2(s2);
	join = malloc(sizeof(char) * (1 + len_s1 + len_s2));
	if (!join)
		return (NULL);
	while (*s1)
		*join++ = *s1++;
	s1 -= len_s1;
	free(s1);
	while (*s2)
		*join++ = *s2++;
	*join = 0;
	join -= len_s1 + len_s2;
	return (join);
}

char	*ft_join_free(char *s1, char *s2)
{
	char	*join;

	join = ft_strjoin2(s1, s2);
	if (!join)
		return (NULL);
	free(s2);
	return (join);
}
