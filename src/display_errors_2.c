/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_errors_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 22:24:05 by ggane             #+#    #+#             */
/*   Updated: 2016/12/21 13:56:44 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_numeric_arg_required(char *builtin, char *arg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(builtin, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(": numeric argument required", 2);
}

void	print_too_many_args(char *builtin)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(builtin, 2);
	ft_putendl_fd(": too many arguments", 2);
}

void	print_illegal_option(char *builtin, char option)
{
	ft_putstr_fd(builtin, 2);
	ft_putstr_fd(": illegal option -- ", 2);
	ft_putchar_fd(option, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(builtin, 2);
	ft_putendl_fd(" [-i] [name=value ...] [utility [argument ...]]", 2);
}
