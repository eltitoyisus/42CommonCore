/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:35:52 by marvin            #+#    #+#             */
/*   Updated: 2025/01/12 16:35:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_nums(t_list **stack_a, int frs, int sec, int thrd)
{
	if ((thrd > sec) && (thrd > frs))
		sa(stack_a);
	if ((sec > thrd) && (sec > frs))
	{
		if (frs > thrd)
			rra(stack_a);
		else
		{
			rra(stack_a);
			sa(stack_a);
		}
	}
	if ((frs > sec) && (frs > thrd))
	{
		if (sec > thrd)
		{
			ra(stack_a);
			sa(stack_a);
		}
		else
			ra(stack_a);
	}
}

void	sort_three(t_list **stack_a)
{
	t_list	*head;
	int		frs;
	int		sec;
	int		thrd;

	head = *stack_a;
	frs = *(int *)head->content;
	sec = *(int *)head->next->content;
	thrd = *(int *)head->next->next->content;
	order_nums(stack_a, frs, sec, thrd);
}

void	sort_four(t_list **stack_a, t_list **stack_b, int digits)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index != 0)
		{
			if (count_index_pos(stack_a, 0) <= (digits / 2))
				ra(stack_a);
			else
				rra(stack_a);
		}
		if ((*stack_a)->index == 0)
			pb(stack_a, stack_b);
	}
	if (!nums_ordered(stack_a))
		sort_three(stack_a);
	pa(stack_b, stack_a);
}

void	sort_five(t_list **stack_a, t_list **stack_b, int digits)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index != 0 && (*stack_a)->index != 1)
		{
			if ((count_index_pos(stack_a, 0) <= (digits / 2))
				|| (count_index_pos(stack_a, 1) <= (digits / 2)))
				ra(stack_a);
			else
				rra(stack_a);
		}
		if (((*stack_a)->index == 0) || ((*stack_a)->index == 1))
			pb(stack_a, stack_b);
	}
	if (!nums_ordered(stack_a))
		sort_three(stack_a);
	if (nums_ordered(stack_b))
		sb(stack_b);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
