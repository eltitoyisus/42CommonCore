/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:39:13 by marvin            #+#    #+#             */
/*   Updated: 2024/11/21 11:39:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	int				index;
	struct s_list	*next;

}	t_list;

// MAIN
int			main(int argc, char **argv);
void		init_push_swap(t_list **stack_a, t_list **stack_b);
int			nums_ordered(t_list **stack);
void		get_index(t_list **stack);
int			count_index_pos(t_list **stack, int index);

// PARSE
void		parse_init(char **argv, t_list **stack_a);
void		check_letrs(char **argv, t_list **stack_a);
void		check_digits(char **argv, t_list **stack_a);
void		print_error(t_list **stack_a);
int			nums_are_ok(char **nums);
int			check_overflow(char *nums);
int			check_len(char *nums);
void		parse_split(char **argv, t_list **stack_a);
void		*free_array(char **array);
void		insert_nums(char **nums, t_list **stack_a);
void		check_duplicates(t_list *stack_a);

// SWAP
void		swap(t_list **stack);
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);

// PUSH
void		push(t_list **frm, t_list **dst);
void		pa(t_list **stack_b, t_list **stack_a);
void		pb(t_list **stack_a, t_list **stack_b);

// ROTATE
void		rotate(t_list **stack);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);

// REVERSE
void		rvs_rotate(t_list **stack);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);

// LIBFT
int			ft_isdigit(int c);
long long	ft_atoll(const char *str);
int			ft_atoi(const char *str);
long long	ft_atoll(const char *str);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstclear(t_list **lst, void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
int			ft_sqrt(int number);

static int	ft_counter(const char *s, char c);
static void	ft_free(char **a);
static char	*ft_read_word(char *s, char c, int *index);
static char	**ft_split_word(char *s, char c);
char		**ft_split(char const *s, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

// SORT
void		order_nums(t_list **stack_a, int frs, int sec, int thrd);
void		sort_three(t_list **stack_a);
void		sort_four(t_list **stack_a, t_list **stack_b, int digits);
void		sort_five(t_list **stack_a, t_list **stack_b, int digits);
void		const_sort_to_b(t_list **stack_a, t_list **stack_b, int digits);
int			count_max_rotations(t_list *stack, int max_index);
void		k_sort(t_list **stack_a, t_list **stack_b, int n_nums);

#endif
