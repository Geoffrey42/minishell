/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:07:50 by ggane             #+#    #+#             */
/*   Updated: 2016/12/17 16:15:40 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		space_tab(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

size_t	get_words_nb(char *raw)
{
	size_t		words_nb;
	int			i;

	words_nb = 0;
	i = 0;
	while (raw[i])
	{
		if (!(space_tab(raw[i])) && (space_tab(raw[i - 1]) || i == 0))
			words_nb++;
		i++;
	}
	return (words_nb);
}
