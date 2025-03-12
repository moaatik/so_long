/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_part_two_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:59:23 by moaatik           #+#    #+#             */
/*   Updated: 2025/03/10 18:01:00 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	long	nbr;

	nbr = n;
	len = count(nbr);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = 0;
	len--;
	while (len >= 0)
	{
		ptr[len] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (ptr);
}

void	ft_error(void)
{
	write(2, "Error\nFailed to load images\n", 28);
	exit(1);
}

void	put_nbr(int nbr)
{
	char	c;

	if (nbr > 9)
	{
		put_nbr(nbr / 10);
		put_nbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
}
