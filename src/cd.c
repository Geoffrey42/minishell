/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 22:35:07 by ggane             #+#    #+#             */
/*   Updated: 2016/10/11 04:06:20 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		change_directory(t_shell *info)
{
	chdir(info->args[1]);
	return (0);
}

int		ft_cd(t_shell *info)
{
	if (!(access(info->args[1], F_OK)) && !(access(info->args[1], X_OK)))
		change_directory(info);
	else if (!(access(info->args[1], F_OK)) && access(info->args[1], X_OK))
		print_permission_denied("cd", info->args[0]);
	else if (access(info->args[1], F_OK))
		print_no_such_file_or_dir("cd", info->args[1]);
	return (0);
}
