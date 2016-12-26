/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:23:18 by ggane             #+#    #+#             */
/*   Updated: 2016/12/26 21:41:22 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	modify_permanent_env(t_data **data)
{
	t_data	*modifications;
	int		(*not_check)(char *);

	not_check = &no_check;
	modifications = get_modifications((*data)->args + 1, not_check);
	modify_specific_variables(data, &modifications);
	if (modifications)
		delete_list(&modifications);
}

int		ft_setenv(t_data **data)
{
	t_data	*ascii_env;
	void	(*display)(t_data *);

	ascii_env = NULL;
	display = &display_setenv_variables;
	if ((*data)->ac == 1)
	{
		ascii_env = copy_env(*data);
		merge_sort(&ascii_env);
		display_env_list(ascii_env, display);
		delete_list(&ascii_env);
	}
	else if ((*data)->ac > 1 && check_setenv_errors(*data))
		modify_permanent_env(data);
	return (0);
}
