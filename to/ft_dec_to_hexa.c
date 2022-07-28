/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angelo <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 14:10:49 by aprosper          #+#    #+#             */
/*   Updated: 2022/07/27 20:52:30 by angelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	zero_case(unsigned int nb, char *res)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		free(res);
		return (1);
	}
	return (0);
}

char	*lazyness_min(int i)
{
	char	*res;

	res = malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	return (res);
}

int	ft_dec_to_hexa(unsigned int nb)
{	
	int		nb_div;
	int		nb_mod;
	char	*res;
	char	c;
	int		i;

	i = ft_nbrlen_hexa(nb);
	res = lazyness_min(i);
	if (zero_case(nb, res) == 1)
		return (1);
	while (nb > 0)
	{
		nb_mod = nb % 16;
		if (nb_mod >= 0 && nb_mod <= 9)
			c = ft_itoa_char_hexa(nb_mod);
		else if (nb_mod >= 10 && nb_mod <= 15)
			c = 87 + nb_mod;
		nb_div = nb / 16;
		nb = nb_div;
		res[--i] = c;
	}
	ft_putstr(res);
	i = ft_strlen(res);
	free(res);
	return (i);
}
