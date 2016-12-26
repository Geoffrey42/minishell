/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_char_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:56:00 by ggane             #+#    #+#             */
/*   Updated: 2016/12/26 23:33:25 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	erase_char_array(char ***array)
{
	char	**tmp;

	ft_putendl("\tstart erase_char_array()");
	tmp = *array;
	ft_putendl("\ttmp = *array ok");
	if (!*array)
	{
		ft_putendl("\tarray est nul");
		return ;
	}
	ft_putendl("\tif ok");
	while (*tmp)
	{
		ft_putendl("\t - tmp n'est pas nul");
		free(*tmp);
		ft_putendl("\t - free(*tmp) ok");
		*tmp = NULL;
		ft_putendl("\t - *tmp = NULL ok");
		tmp++;
		ft_putendl("\t - tmp++ ok");
	}
	ft_putendl("\twhile () ok");
	free(*array);
	ft_putendl("\tfree(*array) ok");
	*array = NULL;
	ft_putendl("\t*array = NULL ok");
	ft_putendl("\tend erase_char_array()");
}
