/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:50:20 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:50:20 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = 0;
	while (little[size] != '\0')
		size++;
	if (size == 0)
		return ((char *)big);
	while (big[i] != '\0')
	{
		while (big[i + j] == little[j])
		{
			if (j == size - 1)
				return ((char *)(big + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
