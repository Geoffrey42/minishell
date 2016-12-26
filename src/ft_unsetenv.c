/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:16 by ggane             #+#    #+#             */
/*   Updated: 2016/12/26 23:52:47 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_var(t_data **data, t_data *modif)
{
	t_data	*tmp;

	ft_putendl("\t\tstart delete_var()");
	tmp = *data;
	ft_putendl("modif :");
	print_list(modif);
	while (tmp)
	{
		ft_putendl("\t\t - tmp non nulle");
		if (!ft_strcmp(tmp->var_name, modif->var_name) &&
			!ft_strlen(modif->var_content))
		{
			ft_putendl("\t\t - Match !!!");
			delete_this_cell(&tmp);
			ft_putendl("\t\t - delete_this_cell() ok");
			ft_putendl("tmp :");
			print_list(tmp);
			break ;
		}
		if (tmp)
		{
			tmp = tmp->next;
			ft_putendl("\t\t - >>>");
		}
	}
	*data = tmp;
	ft_putendl("\t\tend delete_var()");
}

void	search_var_to_delete(t_data **data, t_data *modifications)
{
	ft_putendl("\tstart search_var_to_delete()");
	while (modifications)
	{
		ft_putendl("\t - modifications n'est pas nulle");
		delete_var(data, modifications);
		ft_putendl("\t - delete_var() ok");
		modifications = modifications->next;
		ft_putendl("\t - >>>");
	}
	ft_putendl("\tend search_var_to_delete()");
}

int		ft_unsetenv(t_data **data)
{
	t_data	*modifications;
	int		(*not_check)(char *);

	not_check = &no_check;
	ft_putendl("start ft_unsetenv()");
	modifications = get_modifications((*data)->args + 1, not_check);
	ft_putendl("get_modification() ok");
	search_var_to_delete(data, modifications);
	ft_putendl("search_var_to_delete() ok");
	delete_list(&modifications);
	ft_putendl("delete_list() ok");
	ft_putendl("end ft_unsetenv()");
	return (0);
}
