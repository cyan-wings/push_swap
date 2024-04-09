/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:47:53 by myeow             #+#    #+#             */
/*   Updated: 2024/03/29 20:51:11 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lst.h"

int	ft_lstmax(t_list *lst)
{
	int	*i;

	i = (int *) lst->content;
	while (lst)
	{
		if (*((int *)lst->content) > *i)
			i = lst->content;
		lst = lst->next;
	}
	return (*i);
}
