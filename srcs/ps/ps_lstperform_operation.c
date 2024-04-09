/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstperform_operation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:35:46 by myeow             #+#    #+#             */
/*   Updated: 2024/04/04 02:23:29 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
 * This is the helper function to print the operation.
 * This function was implemented for abstraction of a or b.
 * @param func: The operation performed (i.e., swap, rotate, revrotate)
 * @param lst: The list which the operation will be performed on (i.e. a, b)
 */
static void	stdout_op(const char *op, char l)
{
	ft_putstr_fd((char *) op, 1);
	ft_putchar_fd(l, 1);
	ft_putchar_fd('\n', 1);
}

static void	push_op(char l, t_list **a, t_list **b)
{
	if (l == 'a')
		ft_lstpush(b, a);
	else if (l == 'b')
		ft_lstpush(a, b);
	else
		ft_error(PARSE_ERROR);
}

static void	perform_op(void (*f) (t_list **), char l,
		t_list **lst1, t_list **lst2)
{
	if (l == 'a' || l == 'b')
		f(lst1);
	else if (l == 'r' || l == 's')
	{
		f(lst1);
		f(lst2);
	}
	else
		ft_error(PARSE_ERROR);
}

/*
 * o = 0: Swap
 * o = 1: Rotate
 * o = 2: Reverse Rotate
 * o = 3: Push
 */
void	ps_lstperform_operation(t_operation o, char l,
		t_list **lst1, t_list **lst2)
{
	static void	(*f[])(t_list **) = {
		ft_lstswap, ft_lstrotate, ft_lstrevrotate};
	const char	*operations[] = {"s", "r", "rr"};

	if (o >= 0 && o <= 2)
	{
		perform_op(f[o], l, lst1, lst2);
		stdout_op(operations[o], l);
	}
	else if (o == 3)
	{
		push_op(l, lst1, lst2);
		stdout_op("p", l);
	}
	else
		ft_error(PARSE_ERROR);
}
