/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:51:38 by myeow             #+#    #+#             */
/*   Updated: 2024/03/22 22:26:24 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_stack.h"
#include <unistd.h>
#include <limits.h>

static void	ft_putchar(int c)
{
	write(1, &c, 1);
}

static void	ft_putnbr_aux(int n)
{
	if (n > 10)
		ft_putnbr_aux(n / 10);
	ft_putchar(n % 10 + 48);
}

static void	ft_putnbr(int n)
{
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		return (ft_putnbr_aux(-n));
	}
	return (ft_putnbr_aux(n));
}

int	ft_printstack(t_stack *stk)
{
	unsigned int	n;
	t_node			*curr;

	n = stk->n;
	curr = stk->head;
	while (n--)
	{
		ft_putnbr(curr->val);
		curr = curr->next;
		if (curr)
			ft_putchar(',');
		else
			ft_putchar('\n');
	}
	if (curr)
		return (LOGIC_ERROR);
	return (OK);
}
