/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_lowest_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:29:37 by myeow             #+#    #+#             */
/*   Updated: 2024/04/04 02:21:10 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	calc_rotate(t_list *lst1, t_list *lst2, int f, int *n)
{
	static int	(*calc_rotate_f[])(t_list *, t_list *, int) = {
		calc_rotate_r1r2,
		calc_rotate_rr1rr2,
		calc_rotate_r1rr2,
		calc_rotate_rr1r2
	};

	return (calc_rotate_f[f](lst1, lst2, *n));
}

static void	update_lowest_cost(t_data *lc, int i, int f)
{
	const int	rotation_option [4][2] = {
	{ROTT, ROTT},
	{RERT, RERT},
	{ROTT, RERT},
	{RERT, ROTT}
	};

	lc->idx = i;
	lc->f1 = rotation_option[f][0];
	lc->f2 = rotation_option[f][1];
}

/*
 * Calculates all nodes with the cheapest push. 
 * Initialisation happens first, then actual calculation happens.
 * Updates the lowest cost everytime a cheaper push is found.
 */
void	calc_lowest_push(t_list *lst1, t_list *lst2, t_data *lc)
{
	t_list	*curr;
	int		cost;
	int		i;
	int		f;

	curr = lst1;
	cost = calc_rotate(lst1, lst2, 0, (int *) lst1->content);
	update_lowest_cost(lc, 0, 0);
	i = 0;
	while (curr)
	{
		f = -1;
		while (++f < 4)
		{
			if (cost > calc_rotate(lst1, lst2, f, (int *) curr->content))
			{
				cost = calc_rotate(lst1, lst2, f, (int *) curr->content);
				update_lowest_cost(lc, i, f);
			}
		}
		curr = curr->next;
		++i;
	}
}
