/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:23:43 by marvin            #+#    #+#             */
/*   Updated: 2024/11/21 18:23:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push_swap(t_list **stack_a, t_list **stack_b)
{
	int	n_nums;

	n_nums = ft_lstsize(*stack_a);
	get_index(stack_a);
	if (!nums_ordered(stack_a))
	{
		if (n_nums == 2)
			sa(stack_a);
		else if (n_nums == 3)
			sort_three(stack_a);
		else if (n_nums == 4)
			sort_four(stack_a, stack_b, n_nums);
		else if (n_nums == 5)
			sort_five(stack_a, stack_b, n_nums);
		else
			k_sort(stack_a, stack_b, n_nums);
	}
}

int	nums_ordered(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current && current->next)
	{
		if (*((int *)current->content) > *((int *)current->next->content))
			return (0);
		current = current->next;
	}
	return (1);
}

void	get_index(t_list **stack)
{
	t_list	*current;
	t_list	*temp;
	ssize_t	count;

	current = *stack;
	while (current != NULL)
	{
		count = 0;
		temp = *stack;
		while (temp != NULL)
		{
			if (*(int *)current->content > *(int *)temp->content)
				count++;
			temp = temp->next;
		}
		current->index = count;
		current = current->next;
	}
}

int	count_index_pos(t_list **stack, int index)
{
	int		counter;
	t_list	*head;

	counter = 1;
	head = *stack;
	while (head != NULL && head->index != index)
	{
		counter++;
		head = head->next;
	}
	return (counter);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
		parse_init(argv, &stack_a);
	else
		return (0);
	init_push_swap(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	return (0);
}
