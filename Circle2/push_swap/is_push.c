/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:36:54 by marvin            #+#    #+#             */
/*   Updated: 2024/12/03 15:54:21 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **frm, t_list **dst)
{
	t_list	*tmp;

	if (*frm != NULL)
	{
		tmp = *frm;
		*frm = (*frm)->next;
		tmp->next = *dst;
		*dst = tmp;
	}
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
