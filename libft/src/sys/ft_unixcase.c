/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unixcase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:50:06 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:50:07 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chr.h"
#include <stddef.h>

int	ft_unixcase(const char *str)
{
	size_t i;

	if (!str || !str[0] || (!ft_isalpha(str[0]) && str[0] != '_' &&
																str[0] != '/'))
		return (0);
	i = 1;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_' && str[i] != '/')
			return (0);
		i++;
	}
	return (1);
}
