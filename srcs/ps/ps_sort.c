/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:35:18 by myeow             #+#    #+#             */
/*   Updated: 2024/04/04 23:26:03 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_to_ab_helper(t_list **a, t_list **b, char *order)
{
	t_data	lc;
	t_list	*temp;
	int		i;

	ft_bzero(&lc, sizeof(t_data));
	lc.ab = order;
	calc_lowest_push(*a, *b, &lc);
	temp = *a;
	i = -1;
	while (++i < lc.idx)
		temp = temp->next;
	lc.n = *(int *) temp->content;
	ps_perform_rotation(a, b, lc);
}

static void	push_to_b(t_list **a, t_list **b)
{
	while (!ft_lstissorted(*a) && ft_lstsize(*a) > 3)
	{
		if (ft_lstsize(*b) < 2)
			ps_lstperform_operation(PUSH, 'b', a, b);
		else
		{
			push_to_ab_helper(a, b, "ab");
			ps_lstperform_operation(PUSH, 'b', a, b);
		}
	}
	if (!ft_lstissorted(*a))
		ps_sort_three(a);
}

static void	push_backto_a(t_list **a, t_list **b)
{
	while (*b)
	{
		push_to_ab_helper(b, a, "ba");
		ps_lstperform_operation(PUSH, 'a', a, b);
	}
}

static void	ps_reorder(t_list **lst)
{
	int	idx;
	int	min_idx;

	min_idx = ft_lstmin(*lst);
	idx = ft_lstfind_index(*lst, min_idx);
	if (idx < ft_lstsize(*lst) - idx)
		while (*((int *)(*lst)->content) != min_idx)
			ps_lstperform_operation(ROTT, 'a', lst, 0);
	else
		while (*((int *)(*lst)->content) != min_idx)
			ps_lstperform_operation(RERT, 'a', lst, 0);
}

/*
 * Precondition: List not sorted.
 */
void	ps_sort(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		return (ps_lstperform_operation(SWAP, 'a', a, 0));
	if (ft_lstsize(*a) == 3)
		return (ps_sort_three(a));
	push_to_b(a, b);
	push_backto_a(a, b);
	ps_reorder(a);
}
