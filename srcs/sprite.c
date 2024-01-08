/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:05:25 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/08 18:46:36 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *read_map(char *path)
{
	int i;
	int fd;
	char *s;
	char *tmp;
	char *stack;
	
	i = 1;
	fd = open(path, O_RDONLY);
	s = ft_calloc(10001, sizeof(char));
	stack = ft_strdup("");
	if (!s)
		return(NULL);
	while(i != 0)
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
	return(free(s), stack);
}
char **split_map(char *path)
{
	char **split;
	char *stack;
	
	stack = read_map(path);
	split = ft_split(stack, '\n');
	free(stack);
	return(split);
}