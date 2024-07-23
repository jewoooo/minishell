/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:59:58 by minhulee          #+#    #+#             */
/*   Updated: 2024/07/23 11:05:42 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	sfree(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

char	*super_join(char *src1, char *src2)
{
	char	*dst;

	dst = ft_strjoin(src1, src2);
	sfree(src1);
	sfree(src2);
	return (dst);
}
