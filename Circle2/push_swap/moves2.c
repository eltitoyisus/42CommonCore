/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:53:50 by marvin            #+#    #+#             */
/*   Updated: 2025/01/22 09:53:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	const_sort_to_b(t_list **stack_a, t_list **stack_b, int n_nums)
{
	int	i;
	int	constant_range;

	i = 0;
	constant_range = ft_sqrt(n_nums) * 7 / 5;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			if (ft_lstsize(*stack_b) > 1)
				rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + constant_range)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

int	count_max_rotations(t_list *stack, int max_index)
{
	int	counter;

	counter = 0;
	while (stack != NULL && stack->index != max_index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void	k_sort(t_list **stack_a, t_list **stack_b, int n_nums)
{
	int	rb_count;
	int	rrb_count;

	const_sort_to_b(stack_a, stack_b, n_nums);
	while ((n_nums - 1) >= 0)
	{
		rb_count = count_max_rotations((*stack_b), (n_nums - 1));
		rrb_count = n_nums - rb_count;
		if (rb_count <= rrb_count)
		{
			while ((*stack_b)->index != (n_nums - 1))
				rb(stack_b);
			pa(stack_b, stack_a);
			n_nums--;
		}
		else
		{
			while ((*stack_b)->index != (n_nums - 1))
				rrb(stack_b);
			pa(stack_b, stack_a);
			n_nums--;
		}
	}
}

void	parse_init(char **argv, t_list **stack_a)
{
	check_letrs(argv, stack_a);
	check_digits(argv, stack_a);
	parse_split(argv, stack_a);
	check_duplicates(*stack_a);
}
