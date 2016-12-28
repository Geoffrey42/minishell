/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_char_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:56:00 by ggane             #+#    #+#             */
/*   Updated: 2016/12/27 15:32:58 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../inc/minishell.h"
/*
void	erase_char_array(char ***array)
{
	char	**tmp;
	char	**del;

	tmp = NULL;
	if (!*array)
		return ;
	tmp = *array;
	while (*tmp)
	{
		free(*tmp);
		*tmp = NULL;
		del = tmp;
		ft_strdel(&del);
		tmp++;
	}
	free(*array);
	*array = NULL;
}*/

void	erase_char_array(char **array)
{
	int		i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		ft_strdel(&array[i]);
		i++;
	}
	ft_memdel((void **)array);
}
