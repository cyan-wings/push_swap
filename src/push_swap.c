/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:22:57 by myeow             #+#    #+#             */
/*   Updated: 2024/03/22 22:26:33 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int	push_swap(void)
{
	t_stack	*a;

	a = (t_stack *) malloc(sizeof(t_stack));
	if (!a)
		return (MALLOC_ERROR);
	ft_bzero(a, sizeof(t_stack));
	ft_servenode(a, ft_newnode(30));
	ft_servenode(a, ft_newnode(40));
	ft_servenode(a, ft_newnode(50));
	printf("%d", ft_printstack(a));

	return (OK);
}
