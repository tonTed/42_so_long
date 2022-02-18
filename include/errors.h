/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:36:45 by tblanco           #+#    #+#             */
/*   Updated: 2022/02/18 11:47:21 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

int	err_only(void);
int	err_mess(char *message);
int	err_custom(char *message);

int	err_argc_invalid(int argc);
int	err_open(char *error_message, char *path);

#endif