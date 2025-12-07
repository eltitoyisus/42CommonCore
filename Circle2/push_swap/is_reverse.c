/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reversereverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:38:36 by marvin            #+#    #+#             */
/*   Updated: 2024/12/03 15:54:38 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rvs_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		first = *stack;
		while (first->next->next != NULL)
			first = first->next;
		last = first->next;
		first->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	rra(t_list **stack_a)
{
	rvs_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	rvs_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rvs_rotate(stack_a);
	rvs_rotate(stack_b);
	write(1, "rrr\n", 4);
}
