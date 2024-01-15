/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:25:19 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/24 15:35:29 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	a;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	signe = 1;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			signe *= -1;
		i++;
	}
	a = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + str[i] - '0';
		i++;
	}
	return (signe * a);
}
