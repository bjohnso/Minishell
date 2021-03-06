/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:38:31 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:38:32 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NBR_H
# define NBR_H

# include <stdint.h>

int			ft_atoi(const char *str);
int			ft_atoi_base(char *str, int base);
char		*ft_imaxtoa(intmax_t value);
int			ft_is_sort(int *array, int length, int (*f)(int, int));
char		*ft_itoa_base(int value, int base);
char		*ft_itoa(int n);
long long	ft_nblen(long long nb);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr(int n);
int			*ft_range(int min, int max);
char		*ft_uimaxtoa_base(uintmax_t value, int8_t base, const char *str);
double		ft_pow(double x, int y);
float		ft_sqrtf(float x);

#endif
