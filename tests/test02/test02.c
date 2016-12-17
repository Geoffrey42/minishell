/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 12:02:42 by ggane             #+#    #+#             */
/*   Updated: 2016/12/17 12:41:48 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h> //to_delete
#define SIZE 5

void	test_each_str(char **tests)
{
	char	*epur;
	int		i;
	int		test_nb;

	i = 0;
	while (*tests[i])
	{
		epur = epur_str(*tests[i]);
		if (!(ft_strcmp(epur, *tests[i + 1])))
			printf("test %d ok\n", test_nb);
		else
		{
			printf("test %d failed\n", test_nb);
			printf("resultat epur_str [%s] different de [%s] attendu\n", epur, *tests[i + 1]);
		}
		i += 2;
		test_nb++;
	}
}

void	fill_with_tests(char ***tests)
{
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

	*tests[0] = ft_strdup(s1);
	*tests[1] = ft_strdup(s2);
	*tests[2] = ft_strdup(s3);
	*tests[3] = ft_strdup(s4);
	*tests[4] = ft_strdup(s5);
	*tests[5] = ft_strdup(s6);
	*tests[6] = ft_strdup(s7);
	*tests[7] = ft_strdup(s8);
	*tests[8] = ft_strdup(s9);
	*tests[9] = ft_strdup(s10);
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

	test = allocate_memory();
	fill_with_tests(&tests);
	test_each_str(tests);
	return (0);
}
