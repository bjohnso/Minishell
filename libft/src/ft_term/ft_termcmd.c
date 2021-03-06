/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:55 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:45:56 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <term.h>
#include <stddef.h>
#include <unistd.h>

void	ft_termcmd(char *str)
{
	if (!str || !*str)
		return ;
	ft_putstr_fd(tgetstr(str, NULL), STDERR_FILENO);
}
