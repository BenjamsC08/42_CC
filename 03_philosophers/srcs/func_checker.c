/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:02:23 by benjamsc          #+#    #+#             */
/*   Updated: 2025/07/12 17:02:23 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*ptr;

	ptr = (char *)s;
	i = -1;
	while (++i < n)
		ptr[i] = 0;
	return ;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

int	ft_atoi(char *nptr)
{
	int		nb;
	int		n_n;
	char	*s;

	nb = 0;
	n_n = 1;
	s = (char *)nptr;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			n_n *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		nb *= 10;
		nb += (*(s++) - '0');
	}
	return (nb * n_n);
}

long	ft_atol(char *nptr)
{
	long	nb;
	int		n_n;
	char	*s;

	nb = 0;
	n_n = 1;
	s = (char *)nptr;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			n_n *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		nb *= 10;
		nb += (*(s++) - '0');
	}
	return (nb * n_n);
}
