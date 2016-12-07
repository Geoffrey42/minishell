/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_errors_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 22:24:05 by ggane             #+#    #+#             */
/*   Updated: 2016/12/07 22:36:41 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_illegal_option(char *builtin, char option)
{
	ft_putstr_fd(builtin, 2);
	ft_putstr_fd(": illegal option -- ", 2);
	ft_putchar_fd(option, 2);
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(builtin, 2);
	ft_putendl_fd(" [name=value ...] [utility [argument ...]]", 2);
}
