/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_perform_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:36:41 by myeow             #+#    #+#             */
/*   Updated: 2024/04/04 22:51:24 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
 * ps_perform_operation needs to accept only 1 lst for single operation
 */
void	ps_perform_rotation(t_list **lst1, t_list **lst2, t_data lc)
{
	if (lc.f1 == lc.f2)
	{
		while (*((int *)(*lst1)->content) != lc.n && \
				calc_push_index(*lst2, lc.n, lc.ab[0]) > 0)
			ps_lstperform_operation(lc.f1, 'r', lst1, lst2);
	}
	while (*((int *)(*lst1)->content) != lc.n)
		ps_lstperform_operation(lc.f1, lc.ab[0], lst1, 0);
	while (calc_push_index(*lst2, lc.n, lc.ab[0]) > 0)
		ps_lstperform_operation(lc.f2, lc.ab[1], lst2, 0);
}
