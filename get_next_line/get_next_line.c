/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigunay <sigunay@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:50:41 by sigunay           #+#    #+#             */
/*   Updated: 2024/05/03 15:50:43 by sigunay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_copy_stack(char *stack, char *buffer)
{
	char	*newstack;

	if (!stack && buffer)
	{
		newstack = ft_strdup(buffer);
		if (!newstack)
			return (NULL);
		return (newstack);
	}
	newstack = ft_strjoin(stack, buffer);
	ft_free_stack(&stack, 0);
	return (newstack);
}

int	newline_check(char *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack[i])
	{
		if (stack[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*gets_line(char *stack)
{
	int		i;
	int		j;
	char	*newline;

	i = 0;
	j = 0;
	if (!stack)
		return (NULL);
	while (stack[i] != '\n')
		i++;
	newline = (char *)malloc(sizeof(char) * (i + 2));
	if (!newline)
		return (NULL);
	while (j < (i + 1))
	{
		newline[j] = stack[j];
		j++;
	}
	newline[j] = '\0';
	return (newline);
}

char	*new_line(char *stack)
{
	int		i;
	char	*newstack;

	i = 0;
	if (!stack)
		return (NULL);
	while (stack[i] != '\n')
		i++;
	if (stack[i + 1] == '\0')
		return (ft_free_stack(&stack, 0));
	newstack = ft_substr(stack, i + 1, ft_strlen(stack));
	if (!newstack)
	{
		ft_free_stack(&stack, 0);
		return (NULL);
	}
	ft_free_stack(&stack, 0);
	return (newstack);
}

char	*get_next_line(int fd)
{
	long		read_bytes;
	char		*line;
	static char	*stack = NULL;
	char		buffer[BUFFER_SIZE + 1];

	line = 0;
	read_bytes = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_stack(&stack, 0));
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if ((read_bytes <= 0 && !stack) || read_bytes == -1)
			return (ft_free_stack(&stack, 0));
		buffer[read_bytes] = '\0';
		stack = ft_copy_stack(stack, buffer);
		if (newline_check(stack))
		{
			line = gets_line(stack);
			if (!line)
				return (ft_free_stack(&stack, 0));
			return (stack = new_line(stack), line);
		}
	}
	return (ft_free_stack(&stack, 1));
}
