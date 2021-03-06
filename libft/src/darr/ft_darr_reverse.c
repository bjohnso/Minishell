/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:42:52 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:42:53 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darr.h"
#include "libft.h"
#include <stddef.h>

void		ft_darr_reverse(t_darr *array)
{
	int len;
	int i;

	if (array == NULL || array->len == 0)
		return ;
	i = 0;
	len = FT_DARR_COUNT(array) - 1;
	while (i < len)
	{
		ft_swap(array->content[i], array->content[len], array->content_size);
		++i;
		--len;
	}
}
