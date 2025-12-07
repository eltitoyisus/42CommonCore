/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:56:33 by marvin            #+#    #+#             */
/*   Updated: 2024/12/03 15:58:16 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_list *stack_a)
{
	t_list	*current;
	t_list	*compare;
	int		current_num;
	int		compare_num;

	current = stack_a;
	while (current != NULL && current->next != NULL)
	{
		compare = current->next;
		current_num = *((int *)current->content);
		while (compare != NULL)
		{
			compare_num = *((int *)compare->content);
			if (current_num == compare_num)
				print_error(&stack_a);
			compare = compare->next;
		}
		current = current->next;
	}
}

int	check_len(char *nums)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (nums[i] == '+' || nums[i] == '-')
		i++;
	while (nums[i] == '0')
		i++;
	while (nums[i])
	{
		i++;
		count++;
	}
	if (count >= 11)
		return (1);
	return (0);
}

int	check_overflow(char *nums)
{
	if (check_len(nums))
		return (1);
	else if (ft_atoi(nums) != ft_atoll(nums))
		return (1);
	return (0);
}

void	print_error(t_list **stack_a)
{
	if (stack_a != NULL)
		ft_lstclear(stack_a, free);
	write(2, "Error\n", 6);
	exit(1);
}

void	*free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}
