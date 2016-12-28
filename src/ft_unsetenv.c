/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:16 by ggane             #+#    #+#             */
/*   Updated: 2016/12/28 09:48:57 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_var(t_data **data, t_data *modif)
{
	t_data	*tmp;

	tmp = *data;
	while (tmp)
	{
		if (!ft_strcmp(tmp->var_name, modif->var_name) &&
			!ft_strlen(modif->var_content))
		{
			delete_this_cell(&tmp);
			break ;
		}
		if (tmp)
			tmp = tmp->next;
	}
	*data = tmp;
}

void	search_var_to_delete(t_data **data, t_data *modifications)
{
	while (modifications)
	{
		delete_var(data, modifications);
		modifications = modifications->next;
	}
}

int		ft_unsetenv(t_data **data)
{
	t_data	*modifications;
	int		(*not_check)(char *);

	not_check = &no_check;
	modifications = get_modifications((*data)->args + 1, not_check);
	search_var_to_delete(data, modifications);
	delete_list(&modifications);
	return (0);
}
