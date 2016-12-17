/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:08:06 by ggane             #+#    #+#             */
/*   Updated: 2016/12/16 16:34:01 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*static size_t	is_graph(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= ' ' || str[i] == 127)
			return (0);
		i++;
	}
	return (1);
}*/

static void		copy_each_real_str(char **origin, char **trim, size_t size)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = trim;
	while (origin[i] || j < (int)size)
	{
		if (ft_strlen(origin[i]))
		{
			tmp[j] = ft_strdup(origin[i]);
			if (j < (int)size)
				j++;
		}
		i++;
	}
	tmp[j] = NULL;
}

static size_t	get_origin_size(char **origin)
{
	size_t	size;
	int		i;

	size = 0;
	i = 0;
	while (origin[i])
	{
		//if (is_graph(origin[i]))
		if (ft_strlen(origin[i]))
			size++;
		i++;
	}
	ft_putstr("size : ");
	ft_putnbrdl((int)size);
	return (size);
}

void			trim_each_arg(char ***origin)
{
	char	**tmp;
	char	*del;
	int		i;

	i = 0;
	del = NULL;
	tmp = *origin;
	while (tmp[i])
	{
		del = tmp[i];
		tmp[i] = ft_strtrim(tmp[i]);
		ft_strdel(&del);
		i++;
	}
}

char			**trim_args(char **origin)
{
	char	**trim;
	size_t	size;
	int		i;

	i = 0;
	if (!origin)
		return (NULL);
	ft_putendl("origin (in trim_args())");
	print_char_array(origin);
	trim_each_arg(&origin);
	print_char_array(origin);
	size = get_origin_size(origin);
	trim = ft_memalloc(size + 1);
	copy_each_real_str(origin, trim, size);
	ft_putendl("trim (final)");
	print_char_array(trim);
	return (trim);
}
