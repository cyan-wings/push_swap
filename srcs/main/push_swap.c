/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:52:21 by myeow             #+#    #+#             */
/*   Updated: 2024/04/04 02:31:09 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/push_swap.h"
#include <stdio.h>

static void	ft_clear(void *content)
{
	free(content);
	return ;
}

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

	if (argc == 1)
		return (1);
	a = ps_parselst(argc, argv);
	if (!a)
	{
		ft_error(PARSE_ERROR);
		exit(1);
	}
	ft_lstprint(a, '\n');
	b = 0;
	if (!ft_lstissorted(a))
		ps_sort(&a, &b);
	ft_lstprint(a, '\n');
	ft_lstclear(&a, ft_clear);
	return (0);
}
