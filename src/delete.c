/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:03:26 by ggane             #+#    #+#             */
/*   Updated: 2016/10/16 23:04:37 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		erase_info(t_shell **info)
{
	char	**tmp_env;
	char	**tmp_args;

	tmp_env = (char **)(*info)->env;
	tmp_args = (char **)(*info)->args;
	erase_char_array(&tmp_env);
	erase_char_array(&tmp_args);
}

void		erase_char_array(char ***array)
{
	char	**tmp;

	tmp = *array;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(*array);
	*array = NULL;
}

void	erase_variables(char **words, char *line)
{
	free(words);
	free(line);
}
