/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigunay <sigunay@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:50:21 by sigunay           #+#    #+#             */
/*   Updated: 2024/05/03 15:50:23 by sigunay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_digit(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			digit;
	char		*string;
	long		num;

	num = (long)n;
	digit = find_digit(num);
	if (num < 0)
	{
		num *= -1;
		digit += 1;
	}
	string = (char *)malloc(sizeof(char) * digit + 1);
	if (!string)
		return (NULL);
	string[digit] = '\0';
	while (digit > 0)
	{
		string[--digit] = (num % 10) + 48;
		num /= 10;
	}
	if (n < 0)
		string[0] = '-';
	return (string);
}
