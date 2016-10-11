/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_str_from_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 07:50:15 by ggane             #+#    #+#             */
/*   Updated: 2016/10/11 08:17:58 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

char	*copy_str_from_array(char **origin, char *target)
{
	int		i;

	i = 0;
	if (!origin || !target)
		return (NULL);
	target = ft_strjoin(target, "=");
	while (origin[i])
	{
		if (ft_strstr(origin[i], target))
			return (ft_strdup(origin[i] + ft_strlen(target)));
		i++;
	}
	return (NULL);
}

int		main(int ac, char **av, char **env)
{
	char	*var;

	ac = 0;
	av = NULL;
	var = copy_str_from_array(env, "HOME");
	printf("var(HOME) : [%s]\n", var);
	var = copy_str_from_array(env, "PWD");
	printf("var(PWD) : [%s]\n", var);
	return (0);
}
