/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:58:28 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/05 19:58:56 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_extension(const char *file)
{
	int	i;

	if (!file)
		return (0);
	i = ft_strlen(file);
	if (i < 5)
		return (0);
	if (file[i - 1] == 'r' && file[i - 2] == 'e'
		&& file[i - 3] == 'b' && file[i - 4] == '.')
		return (1);
	return (0);
}
