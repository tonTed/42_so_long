/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_invalid_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:37:28 by tblanco           #+#    #+#             */
/*   Updated: 2022/02/18 11:46:29 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

int	err_argc_invalid(int argc)
{
	if (argc == 1)
		return (err_mess("Program must be have one argument"));
	else
		return (err_mess("Program has too many arguments"));
}

int	err_open(char *error_message, char *path)
{
	err_only();
	err_custom("Opening file: ");
	err_custom(path);
	return (EXIT_FAILIURE);
}
