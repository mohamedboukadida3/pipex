/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:53:15 by mboukadi          #+#    #+#             */
/*   Updated: 2023/06/26 16:04:59 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_putnbr_hexa(unsigned int nbr, char *base);
int		ft_putnbr_ptr(unsigned long nbr, char *base);
int		ft_putnbr(int nbr);
int		ft_putunbr(unsigned int n);
int		ft_printf(const char *s, ...);
int		ft_putstr(char *str);

#endif