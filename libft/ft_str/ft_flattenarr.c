/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flattenarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:20:34 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/15 11:25:23 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char    *ft_flattenarr(char **arr)
{
	VAR(char *, ret, NULL);
	VAR(int, spaces, 0);
	VAR(int, i, -1);
	VAR(int, mall_sz, 0);
	if (!arr || !*arr)
		return (NULL);
	spaces = ft_arrlen(arr);
	while(++i < spaces)
		mall_sz += ft_strlen(arr[i]);
	if(!(ret = ft_strnew(mall_sz + spaces)))
		return (NULL);
	i = -1;
	while(++i < spaces)
	{
		ft_strcat(ret, arr[i]);
		if (i < spaces - 1)
			ft_strcat(ret, " ");
	}
	return(ret);
}