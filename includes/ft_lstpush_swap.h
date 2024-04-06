/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_swap.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:37:55 by myeow             #+#    #+#             */
/*   Updated: 2024/04/06 18:40:34 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LSTPUSH_SWAP_H
# define FT_LSTPUSH_SWAP_H

# include "../libft/includes/ft_lst.h"
# include "../libft/includes/ft_error.h"

typedef enum s_is
{
	YES = 1,
	NO = 0,
}	t_is;

int		ft_lstissorted(t_list *lst);		
t_error	ps_parselst(t_list **a, int argc, char **argv);
void	ps_lstprint(t_list *a, t_list *b);

#endif
