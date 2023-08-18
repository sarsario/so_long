/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:32:10 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/18 10:00:18 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_array_free(char **array)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

int	ft_array_len(char **array)
{
	int	i;

	if (!array)
		return (0);
	i = -1;
	while (array[++i])
		;
	return (i);
}

char	**ft_array_dup(char **array)
{
	char	**dup;
	int		i;

	if (!array)
		return (NULL);
	dup = ft_calloc(ft_array_len(array) + 1, sizeof(char *));
	if (!dup)
		return (NULL);
	i = -1;
	while (array[++i])
	{
		dup[i] = ft_strdup(array[i]);
		if (!dup[i])
		{
			ft_array_free(dup);
			return (NULL);
		}
	}
	return (dup);
}

int	ft_array_join(char ***array, char *str)
{
	char	**new;
	int		i;

	if (!*array)
	{
		new = ft_calloc(2, sizeof(char *));
		if (!new)
			return (0);
		new[0] = str;
		*array = new;
		return (1);
	}
	new = ft_calloc(ft_array_len(*array) + 2, sizeof(char *));
	if (!new)
		return (0);
	i = -1;
	while ((*array)[++i])
		new[i] = (*array)[i];
	new[i] = str;
	free(*array);
	*array = new;
	return (1);
}
