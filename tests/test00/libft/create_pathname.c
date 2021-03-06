/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pathname.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 09:43:01 by ggane             #+#    #+#             */
/*   Updated: 2016/10/06 10:16:42 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*create_pathname(char *daddy, char *son)
{
	daddy = ft_strjoin(daddy, "/");
	son = ft_strjoin(daddy, son);
	return (son);
}
