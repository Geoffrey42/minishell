/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 14:04:44 by ggane             #+#    #+#             */
/*   Updated: 2016/12/07 14:33:52 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*merge_lists(t_data *a, t_data *b)
{
	t_data	*merged_list;

	merged_list = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->var_name, b->var_name) <= 0)
	{
		merged_list = a;
		merged_list->next = merge_lists(a->next, b);
	}
	else
	{
		merged_list = b;
		merged_list->next = merge_lists(a, b->next);
	}
	return (merged_list);
}

void	partition(t_data *head, t_data **front, t_data **back)
{
	t_data	*fast;
	t_data	*slow;

	if (head == NULL || head->next == NULL)
	{
		*front = head;
		*back = NULL;
	}
	else
	{
		slow = head;
		fast = head->next;
		while (fast)
		{
			fast = fast->next;
			if (fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = head;
		*back = slow->next;
		slow->next = NULL;
	}
}

void	merge_sort(t_data **source)
{
	t_data	*head;
	t_data	*a;
	t_data	*b;

	head = *source;
	a = NULL;
	b = NULL;
	if (head == NULL || head->next == NULL)
		return ;
	partition(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*source = merge_lists(a, b);
}
