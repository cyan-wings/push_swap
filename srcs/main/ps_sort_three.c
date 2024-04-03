/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:18:59 by myeow             #+#    #+#             */
/*   Updated: 2024/04/03 23:15:49 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ps_sort_three_case_d_f(t_list **lst)
{
	if (ft_lstmax(*lst) == *((int *) ft_lstlast(*lst)->content))
		ps_lstperform_operation(SWAP, 'a', lst, 0);
	else
		ps_lstperform_operation(RERT, 'a', lst, 0);
}

/*
 * Sorts the list in max. 2 operations when there are 3 items.
 *
 * Preconditions:
 * (1) List is guaranteed to not be sorted.
 * (2) List has no duplicates.
 *
 * Cases:
 * (a)		1 2 3 <Impossible>
 * (b)		1 3 2 -> sa (3 1 2) <case e>	-> ra
 * (c)		2 1 3 -> sa (1 2 3) <done>
 * (d)		2 3 1 -> rra (1 2 3) <done>
 * (e)		3 1 2 -> ra (1 2 3) <done>
 * (f)		3 2 1 -> ra (2 1 3) <case c>	-> sa
 *
 * There will always be only 1 case where 1st item is the lowest.
 * Hence, we work the conditions from there.
 * Case (d) will pass through all test cases except the last, and into else.
 */
void	ps_sort_three(t_list **lst)
{
	if (ft_lstmin(*lst) == *((int *) (*lst)->content))
		ps_lstperform_operation(SWAP, 'a', lst, 0);
	if (ft_lstmax(*lst) == *((int *) (*lst)->content))
		ps_lstperform_operation(ROTT, 'a', lst, 0);
	if (!ft_lstissorted(*lst))
		ps_sort_three_case_d_f(lst);
}
