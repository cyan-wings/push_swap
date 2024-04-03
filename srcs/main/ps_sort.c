/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:35:18 by myeow             #+#    #+#             */
/*   Updated: 2024/04/04 02:34:11 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_to_b_helper(t_list **a, t_list **b)
{
	t_list	*temp;
	t_data	lc;
	int		i;

	calc_lowest_push(*a, *b, &lc);
	temp = *a;
	i = -1;
	while (++i < lc.idx)
		temp = temp->next;
	lc.n = *(int *) temp->content;
	lc.ab = "ab";
	ps_perform_rotation(a, b, lc);
	ps_lstperform_operation(PUSH, 'b', a, b);
}


static void	push_to_b(t_list **a, t_list **b)
{
	while (!ft_lstissorted(*a) && ft_lstsize(*a) > 3)
	{
	   if (ft_lstsize(*b) < 2)
		   ps_lstperform_operation(PUSH, 'b', a, b);
	   else
		   push_to_b_helper(a, b);
	}
	if (!ft_lstissorted(*a))
		ps_sort_three(a);
}

/*
 * Precondition: List not sorted.
 */
void	ps_sort(t_list **a, t_list **b)
{
	//int		i;

	if (ft_lstsize(*a) == 2)
		return (ps_lstperform_operation(SWAP, 'a', a, 0));
	if (ft_lstsize(*a) == 3)
		return (ps_sort_three(a));
	push_to_b(a, b);
	ps_lstprint(*a, *b);
	/*
	a = push_back_a(a, &b);
	i = ft_lstfind_index(a, ft_min(*a));
	if (i < ft_lstsize(*a) - i)
		while (*((int *) a->content) != ft_min(*a))
			ps_lstperform_operation(1, 'a', a, 0);
	else
		while (*((int *) a->content) != ft_min(*a))
			ps_lstperform_operation(2, 'a', a, 0);
	*/
}
