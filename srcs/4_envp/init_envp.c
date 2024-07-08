/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:07:36 by jewlee            #+#    #+#             */
/*   Updated: 2024/07/08 13:34:56 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	count_str(char **s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt] != NULL) // NULL 포인터 포함 x
		cnt++;
	return (cnt);
}

static char	**init_dup_envp(char **envp)
{
	int		size;
	int		i;
	char	**dup_envp;

	size = count_str(envp);
	dup_envp = ft_calloc(size + 1, sizeof(char *));
	if (dup_envp == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		dup_envp[i] = ft_strdup(envp[i]);
		if (dup_envp[i] == NULL)
		{
			while (--i >= 0)
				free(dup_envp[i]);
			free(dup_envp);
			return (NULL);
		}
	}
	dup_envp[i] = NULL;
	return (dup_envp);
}

t_status	init_envp(t_info *info, char **envp)
{
	info->og_envp = envp;
	info->dup_envp = init_dup_envp(envp);
	if (info->dup_envp == NULL)
		return (FAIL);
	return (SUCCESS);
}
