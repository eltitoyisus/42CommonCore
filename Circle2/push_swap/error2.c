/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:58:59 by jramos-a          #+#    #+#             */
/*   Updated: 2024/12/03 16:00:59 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_digits(char **argv, t_list **stack_a)
{
	int	i;
	int	j;
	int	nums;

	i = 1;
	j = 0;
	nums = 0;
	while (argv[i] != NULL)
	{
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]))
				nums++;
			j++;
		}
		if (nums == 0)
			print_error(stack_a);
		j = 0;
		i++;
		nums = 0;
	}
}

void	check_letrs(char **argv, t_list **stack_a)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '\0')
			print_error(stack_a);
		while (argv[i][j] != '\0')
		{
			if (!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
				&& (argv[i][j] != '-') && (argv[i][j] != '+'))
				print_error(stack_a);
			j++;
		}
		j = 0;
		i++;
	}
}

int	nums_are_ok(char **nums)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nums[i] != NULL)
	{
		while (nums[i][j] != '\0')
		{
			if (!(ft_isdigit(nums[i][j + 1])) && (nums[i][j + 1] != '\0'))
				return (1);
			j++;
		}
		j = 0;
		if (check_overflow(nums[i]))
			return (1);
		i++;
	}
	return (0);
}

void	insert_nums(char **nums, t_list **stack_a)
{
	int		i;
	int		*num;
	t_list	*node;

	i = 0;
	while (nums[i] != NULL)
	{
		num = malloc(sizeof(int));
		*num = ft_atoi(nums[i]);
		node = ft_lstnew(num);
		if (!node)
		{
			ft_lstclear(stack_a, free);
			free_array(nums);
			free(nums);
			print_error(stack_a);
		}
		ft_lstadd_back(stack_a, node);
		i++;
	}
}

void	parse_split(char **argv, t_list **stack_a)
{
	int		i;
	char	**nums;

	i = 1;
	nums = NULL;
	while (argv[i] != NULL)
	{
		nums = ft_split(argv[i], ' ');
		if (nums_are_ok(nums))
		{
			free_array(nums);
			print_error(stack_a);
		}
		else
		{
			insert_nums(nums, stack_a);
			free_array(nums);
		}
		i++;
	}
}
