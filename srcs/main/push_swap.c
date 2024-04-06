/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:52:21 by myeow             #+#    #+#             */
/*   Updated: 2024/04/06 18:50:15 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
 * Checks:
 * (1) Argument must be > 1
 * (2) ps_parselst checks for duplicates in the lst
 * (3) If already sorted
 */
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_error	parse_status;	

	if (argc == 1)
		return (1);
	a = 0;
	parse_status = ps_parselst(&a, argc, argv);
	if (parse_status)
	{
		ft_error(parse_status);
		return (1);
	}
	b = 0;
	if (!ft_lstissorted(a))
		ps_sort(&a, &b);
	ft_lstclear(&a, ft_memclear);
	return (0);
}
