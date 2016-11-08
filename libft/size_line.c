/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:49:53 by ggane             #+#    #+#             */
/*   Updated: 2016/11/08 11:50:04 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	size_line(char *str)
{
	size_t		size;

	size = 0;
	while (str[size] != '\n' && str[size] != '\0')
		size++;
	return (size);
}
