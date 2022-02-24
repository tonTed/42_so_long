/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:03:03 by tblanco           #+#    #+#             */
/*   Updated: 2022/02/23 21:15:18 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *begin, char *end)
{
	char	*ret;
	size_t	len_begin;
	size_t	len_end;

	
	len_begin = ft_strlen(begin);
	len_end = ft_strlen(end);
	ret = (char *)malloc(sizeof(char) * (len_begin + len_end + 1));
	ft_strlcpy(ret, begin, len_begin);
	ft_strlcpy(&ret[len_begin], end, len_end);
	free(begin);
	free(end);
	return (ret);
}