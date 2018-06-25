/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:11:38 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/02 15:32:39 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	int				len;
	char			*ret;
	unsigned char	needle;

	ret = NULL;
	len = ft_strlen(str);
	i = -1;
	needle = (unsigned char)c;
	if (needle == '\0' && str[len] == '\0')
		return ((char*)&str[len]);
	while (str[++i])
		if (str[i] == needle)
			ret = (char *)&str[i];
	return (ret);
}
