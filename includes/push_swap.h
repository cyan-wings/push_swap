/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:44:46 by myeow             #+#    #+#             */
/*   Updated: 2024/04/04 02:24:37 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "ft_lstpush_swap.h"

typedef enum s_operation
{
	SWAP = 0,
	ROTT = 1,
	RERT = 2,
	PUSH = 3,
}	t_operation;
/*
 * Holds the lowest cost node and rotation operations to be performed.
 * This struct was declared to return a tuple.
 * @var idx: The index of the node in the lst where best cost is.
 * @var f: The rotation type.
 */
typedef struct s_data
{
	int		idx;
	int		f1;
	int		f2;
	int		n;
	char	*ab;
}	t_data;

int		calc_push_index(t_list *lst, int n);
int		calc_rotate_r1r2(t_list *lst1, t_list *lst2, int n);
int		calc_rotate_rr1rr2(t_list *lst1, t_list *lst2, int n);
int		calc_rotate_r1rr2(t_list *lst1, t_list *lst2, int n);
int		calc_rotate_rr1r2(t_list *lst1, t_list *lst2, int n);
void	calc_lowest_push(t_list *lst1, t_list *lst2, t_data *lc);
void	ps_perform_rotation(t_list **lst1, t_list **lst2, t_data lc);
void	ps_lstperform_operation(t_operation o, char l, t_list **a, t_list **b);
void	ps_sort_three(t_list **lst);
void	ps_sort(t_list **a, t_list **b);

#endif
