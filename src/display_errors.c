/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 17:26:39 by ggane             #+#    #+#             */
/*   Updated: 2016/10/12 07:53:02 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_invalid_identifier(char *invalid)
{
	ft_putstr_fd("minishell: setenv: `", 2);
	ft_putstr_fd(invalid, 2);
	ft_putendl_fd("': not a valid identifier", 2);
}

void	print_oldpwd_not_set(void)
{
	ft_putendl_fd("minishell: cd: OLDPWD not set", 2);
}

void	print_permission_denied(char *source, char *target)
{
	ft_putstr_fd(source, 2);
	ft_putstr_fd(": permission denied: ", 2);
	ft_putendl_fd(target, 2);
}

int		print_command_not_found(char *source, char *target)
{
	ft_putstr_fd(source, 2);
	ft_putstr_fd(": command not found: ", 2);
	ft_putendl_fd(target, 2);
	return (1);
}

void	print_no_such_file_or_dir(char *source, char *target)
{
	ft_putstr_fd(source, 2);
	ft_putstr_fd(": no such file or directory: ", 2);
	ft_putendl_fd(target, 2);
}
