/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_perform_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:36:41 by myeow             #+#    #+#             */
/*   Updated: 2024/04/04 02:27:37 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
 * ps_perform_operation needs to accept only 1 lst for single operation
 */
void	ps_perform_rotation(t_list **lst1, t_list **lst2, t_data lc)
{
	int	n;

	n = lc.n;
	while (*((int *) (*lst1)->content) != n && calc_push_index(*lst2, n) > 0)
		ps_lstperform_operation(ROTT, 'r', lst1, lst2);
	while (*((int *) (*lst1)->content) != n)
		ps_lstperform_operation(lc.f1, lc.ab[0], lst1, 0);
	while (calc_push_index(*lst2, n) > 0)
		ps_lstperform_operation(lc.f2, lc.ab[1], lst2, 0);
}
