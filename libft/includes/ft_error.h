/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:46:02 by myeow             #+#    #+#             */
/*   Updated: 2024/03/31 18:04:33 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

typedef enum s_error
{
	OK = 0,
	MALLOC_ERROR = -1337,
	NULL_ERROR = -10,
	SEG_FAULT = -42,
	UNDEFINED = -50,
	PARSE_ERROR = -48,
	SIZE_ERROR = -88,
}	t_error;

int	ft_error(t_error err_no);

#endif
