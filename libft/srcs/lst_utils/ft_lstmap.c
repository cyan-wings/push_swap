/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:38:17 by myeow             #+#    #+#             */
/*   Updated: 2024/03/28 20:43:50 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lst.h"

static t_list	*ft_lstadd_next(t_list **head, t_list *current, t_list *node)
{
	if (!*head)
	{
		*head = node;
		current = *head;
	}
	else
	{
		current->next = node;
		current = current->next;
	}
	return (current);
}

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*head;
	t_list	*node;
	t_list	*current;

	head = 0;
	current = 0;
	if (f && del)
	{
		while (lst)
		{
			node = ft_lstnew(f(lst->content));
			if (!node)
			{
				ft_lstclear(&head, del);
				return (0);
			}
			current = ft_lstadd_next(&head, current, node);
			lst = lst->next;
		}
	}
	return (head);
}
