/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:42:26 by tonted            #+#    #+#             */
/*   Updated: 2022/02/01 23:09:42 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define BUFFER_SIZE 1

char *get_next_line(int fd)
{
	char	*ret = NULL;
	char	*tmp = NULL;
	char	buffer[2] = {0};
	ssize_t	i;

	if (read(fd, ret, 0) < 0)
		return (NULL);
	while ((i = read(fd, buffer, 1)))
	{
		if (ret)
			tmp = ret;
		ret = malloc(sizeof(char) * (ft_strlen(ret) + 2));
		i = 0;
		while (tmp && tmp[i])
		{
			ret[i] = tmp[i];
			i++;
		}
		ret[i++] = buffer[0];
		ret[i] = '\0';
		if (tmp)
			free(tmp);
		if (ret[i - 1] == '\n')
			return (ret);    
	}
	if (ret)
		return (ret);
	return (NULL);
}
