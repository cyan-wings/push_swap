/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:20:45 by myeow             #+#    #+#             */
/*   Updated: 2024/04/03 17:27:09 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ps_lstprint(t_list *a, t_list *b)
{
	ft_putstr_fd("a |\t", 1);
	ft_lstprint(a, ' ');
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("b |\t", 1);
	ft_lstprint(b, ' ');
	ft_putchar_fd('\n', 1);
}
