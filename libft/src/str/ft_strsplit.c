/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:50:22 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:50:23 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stdlib.h>

static	int		ft_wordlen(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s == c && *s)
		s++;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	return (len);
}

static	void	ft_wordcpy(char *str, char const *s, char c, int *i)
{
	while (*s == c && *s)
	{
		s++;
		(*i)++;
	}
	while (*s != c && *s)
	{
		*str++ = *s++;
		(*i)++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char			**str;
	unsigned int	words;
	int				index;
	int				i;

	i = 0;
	index = 0;
	if (!s)
		return (0);
	words = ft_countwords(s, c);
	if ((str = (char **)malloc(sizeof(char *) * (words + 1))) == 0)
		return (0);
	while (s[index])
	{
		if ((str[i] = ft_strnew(ft_wordlen(s + index, c))) == 0)
		{
			ft_free_sstr(str);
			return (0);
		}
		ft_wordcpy(str[i], s + index, c, &index);
		i++;
	}
	str[words] = 0;
	return (str);
}
