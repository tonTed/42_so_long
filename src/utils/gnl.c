/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:59:09 by tonted            #+#    #+#             */
/*   Updated: 2022/03/02 08:29:49 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	new_ret(char *ret, char *tmp, char *buffer)
{
	u_int32_t	i;

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
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char	*ret;
	char	*tmp;
	char	buffer[2];
	ssize_t	i;

	ret = NULL;
	tmp = NULL;
	if (read(fd, ret, 0) < 0)
		return (NULL);
	while (42)
	{
		i = read(fd, buffer, 1);
		if (i == 0)
			break ;
		buffer[i] = '\0';
		if (ret)
			tmp = ret;
		ret = malloc(sizeof(char) * (ft_strlen(ret) + 2));
		i = 0;
		if (new_ret(ret, tmp, buffer))
			return (ret);
	}
	if (ret)
		return (ret);
	return (NULL);
}
