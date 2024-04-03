/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_push_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 23:42:28 by myeow             #+#    #+#             */
/*   Updated: 2024/04/04 01:54:51 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lstpush_swap.h"

/*
 * Returns the index number of the node that contains n,
 * when it is pushed to lst.
 *
 * 1st case when the pushed node should be on top.
 * 2nd case when the pushed node is near max or min
 * 		(doesn't matter since max and min are neighbors)
 * 3rd case when the pushed node is somewhere else
 * 		(definitely not the 1st so i = 1)
 * 		: lst is node before the insert node index
 * 		: temp is node after the insert node index
 */
int	calc_push_index(t_list *lst, int n)
{
	int		i;
	t_list	*temp;

	if (n > (*((int *) lst->content) && \
				n < *((int *) ft_lstlast(lst)->content)))
		return (0);
	if (n > ft_lstmax(lst) || n < ft_lstmin(lst))
		return (ft_lstfind_index(lst, ft_lstmax(lst)));
	i = 1;
	temp = lst->next;
	while (*((int *) lst->content) < n || *((int *) temp->content) > n)
	{
		lst = lst->next;
		temp = lst->next;
		++i;
	}
	return (i);
}
