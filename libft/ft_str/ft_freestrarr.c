/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 09:59:52 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/15 10:01:46 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_freestrarr(char **arr)
{
	VAR(int, i, -1);
	while(arr[++i])
	{	
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
}