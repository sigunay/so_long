/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigunay <sigunay@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:50:05 by sigunay           #+#    #+#             */
/*   Updated: 2024/05/03 15:50:07 by sigunay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr( int n);
int		ft_hex(unsigned int n, char c);
int		ft_pointer(unsigned long int num, int check);
int		ft_unsign(unsigned int num);
char	*ft_itoa(int n);

#endif
