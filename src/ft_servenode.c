/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_servenode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:31:40 by myeow             #+#    #+#             */
/*   Updated: 2024/03/22 22:19:06 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_stack.h"

int	ft_servenode(t_stack *stk, t_node *newnode)
{
	if (!newnode || !stk)
		return (NULL_ERROR);
	if (!stk->n)
		stk->head = newnode;
	else if (stk->n == 1)
	{
		stk->tail = stk->head;
		newnode->next = stk->head;
		stk->head = newnode;
	}
	else
	{
		stk->second = stk->head;
		newnode->next = stk->head;
		stk->head = newnode;
	}
	++stk->n;
	return (OK);
}
