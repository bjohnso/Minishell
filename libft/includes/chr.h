/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:38:00 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:38:01 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHR_H
# define CHR_H

int	ft_putnchar_fd(int c, int n, int fd);
int	ft_putchar_fd(int c, int fd);
int	ft_putchar(int c);
int	ft_getchar(void);

# define ISALPHA(a) (((unsigned)a | 32) - 97 < 26u)
# define ISASCII(a) ((unsigned)a < 128u)
# define ISDIGIT(a) (((unsigned)a-48) < 10u)
# define ISALNUM(a) (ISALPHA(a) || ISDIGIT(a))
# define ISPRINT(a) (((unsigned)a - 32) < 95u)
# define ISSPACE(a) ((a >= 9 && a <= 13) || (a == 32))
# define ISLOWER(a) (a >= 'a' && a <= 'z')
# define ISUPPER(a) (a >= 'A' && a <= 'Z')
# define TOLOWER(a) (((unsigned)a - 65) < 26u ? a + 32 : a)
# define TOUPPER(a) (((unsigned)a - 97) < 26u ? a - 32 : a)

int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int ft_isspace(int c);
int	ft_islower(int c);
int	ft_isupper(int c);
int	ft_tolower(int c);
int	ft_toupper(int c);

#endif
