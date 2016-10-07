/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 12:19:02 by ggane             #+#    #+#             */
/*   Updated: 2016/10/07 14:26:07 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

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
		printf("It parent process ID is : %d\n", getppid()); //retourne tjrs 1 si wait non utilise
		printf("fork() return value is : %d\n", child);
		execvp(program, args);
		printf("-------------THIS-WILL-NEVER-HAPPEN--------\n");
		abort();
	}
	return (0);
}

int		main(void)
{
	char	*args[] = {"ls", "-l", "/", NULL};
	int		status;
	pid_t

	spawn("ls", args);
	wait(&status);
	if (WIFEXITED(status))
		printf("Child process has terminated normally, it's exit code is : %d\n", WEXITSTATUS(status));
	else
		printf("Child process has not terminated normally\n");
	return (0);
}
