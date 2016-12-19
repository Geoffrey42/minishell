/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:39:38 by ggane             #+#    #+#             */
/*   Updated: 2016/12/19 09:59:48 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	epur_raw(char **epur, char *raw)
{
	char		*tmp;
	size_t		words_nb;
	int			i;
	int			j;

	tmp = *epur;
	words_nb = get_words_nb(raw);
	i = 0;
	j = 0;
	while (raw[i] || tmp[j])
	{
		if (!(space_tab(raw[i])) && (i > 0 && space_tab(raw[i - 1])))
			words_nb--;
		if (!(space_tab(raw[i])))
			tmp[j++] = raw[i];
		if (!(space_tab(raw[i])) && space_tab(raw[i + 1]) && words_nb != 0)
			tmp[j++] = ' ';
		i++;
	}
}

size_t	get_cumulative_words_length(char *raw)
{
	size_t		len;
	int			i;

	len = 0;
	i = 0;
	while (raw[i])
	{
		if (!(space_tab(raw[i])))
			len++;
		i++;
	}
	return (len);
}

size_t	get_spaces_nb(char *raw)
{
	size_t		words_nb;
	size_t		required_spaces;

	words_nb = get_words_nb(raw);
	if (words_nb != 0)
		required_spaces = words_nb + 1;
	else
		required_spaces = words_nb;
	return (required_spaces);
}

size_t	get_epur_size(char *raw)
{
	size_t		required_spaces;
	size_t		cumulative_words_length;

	required_spaces = get_spaces_nb(raw);
	cumulative_words_length = get_cumulative_words_length(raw);
	return (cumulative_words_length + required_spaces);
}

char	*epur_str(char *raw)
{
	char		*epur;
	size_t		size;

	if (!(raw))
		return (NULL);
	size = get_epur_size(raw);
	if (!(epur = ft_memalloc(size + 1)))
		return (NULL);
	epur_raw(&epur, raw);
	return (epur);
}
