/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:59:09 by tonted            #+#    #+#             */
/*   Updated: 2022/02/22 22:59:28 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		{
			ret[i - 1] = '\0';
			return (ret);    
		}
	}
	if (ret)
		return (ret);
	return (NULL);
}
