/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:55:23 by myeow             #+#    #+#             */
/*   Updated: 2024/03/22 22:10:44 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

#include <stddef.h>

typedef enum s_error
{
	OK = 0,
	MALLOC_ERROR = -1337,
	NULL_ERROR = -10,
	LOGIC_ERROR = -42,
}	t_error;

typedef struct s_node
{
	int				val;
	struct s_node	*next;
}	t_node;

/*
 * @vars
 * head: The top of the stack
 * second: The node below the head
 * tail: The last node of the stack
 * n: The number of nodes in the stack
 */
typedef struct s_stack
{
	t_node	*head;
	t_node	*second;
	t_node	*tail;
	size_t			n;
}	t_stack;

void	ft_bzero(void *s, size_t n);
t_node	*ft_newnode(int val);
int		ft_servenode(t_stack *stk, t_node *newnode);
int		ft_printstack(t_stack *stk);
int		push_swap(void);

#endif
