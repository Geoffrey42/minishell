/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 09:34:23 by ggane             #+#    #+#             */
/*   Updated: 2016/10/07 12:07:14 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int		main(void)
{
	pid_t	child;

	printf("Main programm process ID is : %d\n", getpid());
	child = fork();
	if (child)
	{
		printf("---------------FATHER-----------------------\n");
		printf("We're in the parent process, here it's ID : %d\n", getpid());
		printf("It parent process ID is %d\n", getppid()); //return father pid of father process 
		printf("Child process ID is : %d\n", child);
		printf("--------------------------------------------\n");
	}
	else
	{
		printf("---------------CHILD------------------------\n");
		printf("We're in the child process, here it's ID : %d\n", getpid());
		printf("It parent process ID is %d\n", getppid()); //return 1 instead of father pid
		printf("--------------------------------------------\n");
	}
	return (0);
}
