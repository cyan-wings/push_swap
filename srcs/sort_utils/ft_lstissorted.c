/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstissorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:42:14 by myeow             #+#    #+#             */
/*   Updated: 2024/04/03 14:07:51 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lstpush_swap.h"

int	ft_lstissorted(t_list *lst)
{
	int	i;

	if (!lst)
		return (ft_error(NULL_ERROR));
	i = *((int *) lst->content);
	while (lst)
	{
		if (i > *((int *) lst->content))
			return (NO);
		i = *((int *) lst->content);
		lst = lst->next;
	}
	return (YES);
}
