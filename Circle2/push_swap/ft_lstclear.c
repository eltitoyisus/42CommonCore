/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:15:37 by marvin            #+#    #+#             */
/*   Updated: 2025/01/22 11:15:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*aux;

	head = *lst;
	while (head != NULL)
	{
		aux = head->next;
		if (del != NULL)
			del(head->content);
		free(head);
		head = aux;
	}
	*lst = (NULL);
}
