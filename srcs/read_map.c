/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:05:25 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/31 18:40:15 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_maps(char *path)
{
	int		i;
	int		fd;
	char	*s;
	char	*stack;
	char	*tmp;

	i = 1;
	fd = open(path, O_RDONLY);
	s = ft_calloc(10001, sizeof(char));
	stack = ft_strdup("");
	if (!s)
		return (NULL);
	while (i != 0)
	{
		i = read(fd, s, 10000);
		s[i] = '\0';
		tmp = stack;
		stack = ft_strjoin(stack, s);
		free(tmp);
	}
	close(fd);
	return (free(s), stack);
}

char	**split_map(char *path)
{
	char	**split;
	char	*stack;
	
	stack = read_maps(path);
	split = ft_split(stack, '\n');
	free(stack);
	return (split);
}

size_t	count_ligne_split(char **split)
{
	size_t	y;

	y = 0;
	while (split[y])
		y++;
	return (y);
}
