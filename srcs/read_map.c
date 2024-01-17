/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:05:25 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/15 11:37:59 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static char *read_maps_1(char *s, char *stack, int fd, int i)
// {
// 	char *tmp;

// 	i = read(fd, s, 10000);
// 	if (i == -1)
// 	{
// 		free(stack);
// 		free(s);
// 		return (NULL);
// 	}
// 	s[i] = '\0';
// 	tmp = stack;
// 	stack = ft_strjoin(stack, s);
// 	free(tmp);
// 	return(stack);
// }

static char	*read_maps_2(char *path)
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
		if (i == -1)
		{
			free(stack);
			free(s);
			return (NULL);
		}
		s[i] = '\0';
		tmp = stack;
		stack = ft_strjoin(stack, s);
		free(tmp);
	}
	close(fd);
	return (free(s), stack);
}
// read_maps_1(s, stack, fd, i);
char	**split_map(char *path)
{
	char **split;
	char *stack;

	stack = read_maps_2(path);
	split = ft_split(stack, '\n');
	free(stack);
	return (split);
}