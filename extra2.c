/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-bas <yoel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:20:09 by yoel-bas          #+#    #+#             */
/*   Updated: 2023/06/19 18:03:47 by yoel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
unsigned long get_time()
{
	struct timeval tv;
	
	if(gettimeofday(&tv, NULL))
		return(0);
	return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}