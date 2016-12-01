/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:05:33 by ggane             #+#    #+#             */
/*   Updated: 2016/12/01 11:33:35 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_data(t_data **del)
{
	ft_strdel(&(*del)->var_name);
	ft_strdel(&(*del)->var_content);
	if ((*del)->args)
		erase_char_array(&(*del)->args);
}
