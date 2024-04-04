/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_push_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 23:42:28 by myeow             #+#    #+#             */
/*   Updated: 2024/04/04 22:54:20 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lstpush_swap.h"

static int	calc_push_index_top(int *cont, int *lstcont, int n, char fromlst)
{
	if (fromlst == 'a')
	{
		if (n > *cont && n < *lstcont)
			return (1);
	}
	else if (fromlst == 'b')
	{
		if (n < *cont && n > *lstcont)
			return (1);
	}
	return (0);
}

static int	calc_push_index_bet(t_list *lst, int n, char fromlst)
{
	int		i;
	t_list	*temp;

	i = 1;
	temp = lst->next;
	if (fromlst == 'a')
	{
		while (*((int *) lst->content) < n || *((int *) temp->content) > n)
		{
			lst = lst->next;
			temp = lst->next;
			++i;
		}
	}
	else if (fromlst == 'b')
	{
		while (*((int *) lst->content) > n || *((int *) temp->content) < n)
		{
			lst = lst->next;
			temp = lst->next;
			++i;
		}
	}
	return (i);
}

/*
 * Returns the index number of the node that contains n,
 * when it is pushed to lst.
 *
 * @param order: ex. 	"ab" is push to b
 * 						"ba" is push back to a
 *
 * 1st case when the pushed node should be on top.
 * 2nd case when the pushed node is near max or min
 * 3rd case when the pushed node is somewhere else
 * 		(definitely not the 1st so i = 1)
 * 		: lst is node before the insert node index
 * 		: temp is node after the insert node index
 */
int	calc_push_index(t_list *lst, int n, char fromlst)
{
	if (calc_push_index_top((int *) lst->content, \
				(int *) ft_lstlast(lst)->content, n, fromlst))
		return (0);
	if (n > ft_lstmax(lst) || n < ft_lstmin(lst))
	{
		if (fromlst == 'a')
			return (ft_lstfind_index(lst, ft_lstmax(lst)));
		else if (fromlst == 'b')
			return (ft_lstfind_index(lst, ft_lstmin(lst)));
		else
			return (ft_error(PARSE_ERROR));
	}
	else
		return (calc_push_index_bet(lst, n, fromlst));
}
