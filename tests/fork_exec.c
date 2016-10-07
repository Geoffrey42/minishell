/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 10:16:27 by ggane             #+#    #+#             */
/*   Updated: 2016/10/07 11:54:40 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int		spawn(char *program, char **args)
{
	pid_t	child;

	child = fork();
	if (child)
	{
		printf("------------------FATHER-------------------\n");
		printf("We're in parent process, ID : %d\n", getpid());
		printf("It parent process ID is : %d\n", getppid());
		printf("fork() return value is child process ID so it's : %d\n", child);
		printf("-------------------------------------------\n");
		return (child);
	}
	else
	{
		printf("------------------CHILD--------------------\n");
		printf("We're in child process, ID : %d\n", getpid());
		printf("It parent process ID is : %d\n", getppid()); //retourne tjrs 1, pk ?
		printf("fork() return value is : %d\n", child);
		execvp(program, args);
		printf("-------------THIS-WILL-NEVER-HAPPEN--------\n");
	}
	return (0);
}

int		main(void)
{
	char	*args[] = {"ls", "-l", "/", NULL};

	spawn("ls", args);
	return (0);
}
