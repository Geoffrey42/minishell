/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 09:54:36 by ggane             #+#    #+#             */
/*   Updated: 2016/12/15 21:13:31 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		change_directory(char *dir, t_data *data)
{
	char	*oldpwd;
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	oldpwd = ft_strjoin("OLDPWD=", cwd);
	add_var_directly(&data, oldpwd);
	ft_strdel(&oldpwd);
	chdir(dir);
	return (0);
}

int		check_cd_access(t_data *data, char *dir)
{
	if (!(access(dir, F_OK)) && !(access(dir, X_OK)))
		change_directory(dir, data);
	else if (!(access(dir, F_OK)) && access(dir, X_OK))
		print_permission_denied("cd", dir);
	else if (access(dir, F_OK))
		print_no_such_file_or_dir("cd", dir);
	return (0);
}

char	*go_to_previous_dir(t_data *data)
{
	char	*old_pwd;

	old_pwd = search_var(data, "OLDPWD");
	if (!old_pwd)
		print_oldpwd_not_set();
	else
		ft_putendl(old_pwd);
	return (old_pwd);
}

char	*search_var(t_data *data, char *to_search)
{
	char	*found;

	found = NULL;
	while (data)
	{
		if (!ft_strcmp(data->var_name, to_search))
			found = data->var_content;
		data = data->next;
	}
	return (found);
}

int		ft_cd(t_data *data)
{
	char	*dir;

	dir = NULL;
	if (data->ac == 1 || !ft_strcmp(data->args[1], "~"))
	{
		check_cd_access(data, search_var(data, "HOME"));
		return (0);
	}
	if (!ft_strcmp(data->args[1], "-"))
		dir = go_to_previous_dir(data);
	else
		dir = data->args[1];
	check_cd_access(data, dir);
	return (0);
}
