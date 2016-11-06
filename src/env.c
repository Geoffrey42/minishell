/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 22:40:35 by ggane             #+#    #+#             */
/*   Updated: 2016/11/06 12:40:01 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Si env n'a pas d'argument commande, il affiche l'environnement
** (apres un fork) cad que si on lance juste env, il affiche l'env,
** mais si on lance env avec une variable nouvelle, idem il affiche
** l'env mais avec cette variable. Si on relance env apres, la variable
** aura disparu. C'est donc bien apres un fork().
*/

int		ft_env(t_shell *info)
{
	info = NULL;
	return (0);
}
