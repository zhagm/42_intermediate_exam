/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.org>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 10:55:38 by zmagauin          #+#    #+#             */
/*   Updated: 2019/04/11 11:17:41 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		find_pivot(int *arr, int n)
{
	int i;
	int first;
	int sum;

	sum = 0;
	i = 0;
	while (i < n)
		sum += arr[i++];
	i = 1;
	first = 0;
	while (i < n)
	{
		first += arr[i - 1];
		if (first == sum - (first + arr[i]))
			return (i);
		i++;
	}
	return (-1);
}
