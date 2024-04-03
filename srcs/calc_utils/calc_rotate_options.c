/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rotate_options.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:45:54 by myeow             #+#    #+#             */
/*   Updated: 2024/04/04 00:28:05 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// This function calculates how many times
// we should rotate the stacks together.
// Because after a certain amoun of rotate, we will
// proceed only with one stack rotation.
int	calc_rotate_r1r2(t_list *lst1, t_list *lst2, int n)
{
	int	i;

	i = calc_push_index(lst2, n);
	if (i < ft_lstfind_index(lst1, n))
		i = ft_lstfind_index(lst1, n);
	return (i);
}

// This function calculates how many times we should rotate the stacks together.
// Because after a certain amoun of rotate, we will proceed only with one stack
// rotation. Since here we have reverse rotate,rather than index number,
// we check reverse index number which is
// calculated by list_size - index_number.
int	calc_rotate_rr1rr2(t_list *lst1, t_list *lst2, int n)
{
	int	i;

	i = 0;
	if (calc_push_index(lst2, n))
		i = ft_lstsize(lst2) - calc_push_index(lst2, n);
	if ((i < (ft_lstsize(lst1) - ft_lstfind_index(lst1, n))) && \
			ft_lstfind_index(lst1, n))
		i = ft_lstsize(lst1) - ft_lstfind_index(lst1, n);
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for ra+rrb case.
int	calc_rotate_r1rr2(t_list *lst1, t_list *lst2, int n)
{
	int	i;

	i = 0;
	if (calc_push_index(lst2, n))
		i = ft_lstsize(lst2) - calc_push_index(lst2, n);
	i = ft_lstfind_index(lst1, n) + i;
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for rra+rb case.
int	calc_rotate_rr1r2(t_list *lst1, t_list *lst2, int n)
{
	int	i;

	i = 0;
	if (ft_lstfind_index(lst1, n))
		i = ft_lstsize(lst1) - ft_lstfind_index(lst1, n);
	i = calc_push_index(lst2, n) + i;
	return (i);
}
