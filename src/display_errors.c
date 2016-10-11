/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 17:26:39 by ggane             #+#    #+#             */
/*   Updated: 2016/10/11 02:44:59 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_permission_denied(char *command)
{
	ft_putstr_fd("minishell: permission denied: ", 2);
	ft_putendl_fd(command, 2);
}

int		print_command_not_found(char *command)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(command, 2);
	return (1);
}

void	print_no_such_file_or_dir(char *command)
{
	ft_putstr_fd("minishell: no such file or directory: ", 2);
	ft_putendl_fd(command, 2);
}

void	choose_error_msg(char *command)
{
	if (ft_strchr(command, '/'))
		print_no_such_file_or_dir(command);
	else
		print_command_not_found(command);
}
