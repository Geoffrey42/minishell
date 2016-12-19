/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 12:02:42 by ggane             #+#    #+#             */
/*   Updated: 2016/12/19 09:58:14 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h> //to_delete
#define SIZE 12

char	*epur_str(char *raw);

void	test_each_str(char **tests)
{
	char	*epur;
	int		i;
	int		test_nb;

	i = 0;
	test_nb = 0;
	while (tests[i])
	{
		printf("test %d : [%s] ", test_nb, tests[i]);
		epur = epur_str(tests[i]);
		if (!(ft_strcmp(epur, tests[i + 1])))
			printf("ok\n");
		else
			printf("failed\n\nresultat epur_str [%s] de size %zu\ndifferent de [%s] attendu.\n", epur, ft_strlen(epur), tests[i + 1]);
		printf("--------\n");
		ft_strdel(&epur);
		i += 2;
		test_nb++;
	}
}

void	fill_with_tests(char ***tests)
{
	char	**tmp;
	char	s1[] = { 'a', 'b', '\0'};
	char	s2[] = { 'a', 'b', '\0'};
	char	s3[] = { ' ', 'a', 'b', '\0'};
	char	s4[] = { 'a', 'b', '\0'};
	char	s5[] = { ' ', 'a', 'b', ' ', '\0'};
	char	s6[] = { 'a', 'b', '\0'};
	char	s7[] = { ' ', '\t', 'a', '\t', ' ', 'b', '\0'};
	char	s8[] = { 'a', ' ', 'b', '\0'};
	char	s9[] = { ' ', '\t', ' ', '\t', '\t', 'a', '\t', ' ', 'b', '\t', ' ', '\t', '\t', '\0'};
	char	s10[] = { 'a', ' ', 'b', '\0'};
	char	s11[] = { 'a', ' ', 'b', '\t', ' ', 'c', '\t', ' ' ,'\0'};
	char	s12[] = { 'a', ' ', 'b', ' ', 'c', '\0'};

	tmp = *tests;
	tmp[0] = ft_strdup(s1);
	tmp[1] = ft_strdup(s2);
	tmp[2] = ft_strdup(s3);
	tmp[3] = ft_strdup(s4);
	tmp[4] = ft_strdup(s5);
	tmp[5] = ft_strdup(s6);
	tmp[6] = ft_strdup(s7);
	tmp[7] = ft_strdup(s8);
	tmp[8] = ft_strdup(s9);
	tmp[9] = ft_strdup(s10);
	tmp[10] = ft_strdup(s11);
	tmp[11] = ft_strdup(s12);
}

char	**allocate_memory(void)
{
	char	**tests;

	if (!(tests = (char **)malloc(sizeof(char *) * SIZE + 1)))
		return (NULL);
	tests[SIZE] = NULL;
	return (tests);
}

int		main(void)
{
	char	**tests;

	ft_putendl("start test02's unit tests\n");
	tests = allocate_memory();
	fill_with_tests(&tests);
	test_each_str(tests);
	ft_putendl("\nend test02");
	return (0);
}
