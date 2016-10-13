/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 22:35:07 by ggane             #+#    #+#             */
/*   Updated: 2016/10/13 13:50:01 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		change_directory(char *dir, t_shell *info)
{
	char	cwd[1024];
	char	*var;

	getcwd(cwd, sizeof(cwd));
	var = (char *)cwd;
	var = ft_strjoin("OLDPWD=", cwd);
	setenv_func(var, &info->env);
	free(var);
	chdir(dir);
	return (0);
}

int		check_cd_access(t_shell *info, char *dir)
{
	if (!(access(dir, F_OK)) && !(access(dir, X_OK)))
		change_directory(dir, info);
	else if (!(access(dir, F_OK)) && access(dir, X_OK))
		print_permission_denied("cd", dir);
	else if (access(dir, F_OK))
		print_no_such_file_or_dir("cd", dir);
	return (0);
}

char	*go_to_previous_dir(t_shell *info)
{
	char	*old_pwd;

	old_pwd = copy_str_from_array(info->env, "OLDPWD");
	if (!old_pwd)
		print_oldpwd_not_set();
	else
		ft_putendl(old_pwd);
	return (old_pwd);
}

int		ft_cd(t_shell *info)
{
	char	*dir;

	if (nb_args(info->args) == 1)
	{
		check_cd_access(info, copy_str_from_array(info->env, "HOME"));
		return (0);
	}
	if (!ft_strcmp(info->args[1], "-"))
		dir = go_to_previous_dir(info);
	else if (!ft_strcmp(info->args[1], "~"))
		dir = copy_str_from_array(info->env, "HOME");
	else
		dir = ft_strdup(info->args[1]);
	check_cd_access(info, dir);
	return (0);
}
