/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 09:19:29 by ggane             #+#    #+#             */
/*   Updated: 2016/10/07 09:31:47 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int		main(void)
{
	pid_t	current;
	pid_t	father;

	current = getpid();
	father = getppid();
	printf("Process ID is : %d\n", current);
	printf("Parent Process ID is : %d\n", father);
	return (0);
}
