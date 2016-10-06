/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:26:57 by ggane             #+#    #+#             */
/*   Updated: 2016/10/06 20:31:51 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	pid_t	father;
	pid_t	son;
	int		status;

	father = fork();
	if (father == -1)
	{
		printf("fork() failed\n");
		exit(EXIT_FAILURE);
	}
	else if (father == 0)
	{
		sleep(5);
		printf("we're on the son process now\n");
		printf("--------SON------------\n");
		printf("father = %d\n", father);
		printf("son = %d\n", son);
		printf("status = %d\n", status);
		printf("-----------------------\n");
		//exit(EXIT_SUCCESS);
	}
	else if (father > 0)
	{
		printf("we're on the father process now\n");
		printf("---------FATHER--------\n");
		printf("father = %d\n", father);
		printf("son = %d\n", son);
		printf("status = %d\n", status);
		printf("-----------------------\n");
		//exit(EXIT_SUCCESS);
	}
	son = wait(&status);
	printf("------AFTER WAIT-------\n");
	printf("father = %d\n", father);
	printf("son = %d\n", son);
	printf("status = %d\n", status);
	printf("-----------------------\n");
	return (0);
}
