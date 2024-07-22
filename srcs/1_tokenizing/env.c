/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:15:39 by jewlee            #+#    #+#             */
/*   Updated: 2024/07/22 18:17:12 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*is_exist_env(char *line, int *ptr)
{
	char	*name;
	char	*res;
	int		i;

	res = NULL;
	i = 1;
	while (!(line[*ptr + i] == '\'' || line[*ptr + i] == '\"'
			|| line[*ptr + i] == '$' || line[*ptr + i] == ' ')
		&& line[*ptr + i])
		i++;
	name = ft_substr(line, *ptr + 1, i - 1);
	*ptr += i;
	res = getenv(name);
	free(name);
	if (!res)
		return (ft_strdup(""));
	return (res);
}

static void	to_single_quote(char *line, int *ptr, char **res, int *start)
{
	while (line[++(*ptr)] != '\'')
		;
	*res = super_join(*res, ft_substr(line, *start, ++(*ptr)));
	start = ptr;
}

static void	env_to_value(char *line, int *ptr, int *start, char **res)
{
	char	*env;

	env = super_join(ft_substr(line, *start, ptr - start),
			is_exist_env(line, ptr));
	*res = super_join(*res, env);
	start = ptr;
}

char	*substitute_env(char *line, int exit_status)
{
	char	*res;
	int		start;
	int		ptr;
	t_bool	flag;

	(void)exit_status;
	start = 0;
	ptr = 0;
	flag = FALSE;
	res = NULL;
	while (line[ptr])
	{
		if (line[ptr] == '\'' && !flag)
			to_single_quote(line, &ptr, &res, &start);
		else if (line[ptr] == '\"')
			flag = !flag;
		else if (line[ptr] == '$' && !ft_isoperator(line[ptr + 1])
			&& line[ptr + 1] != ' ' && line[ptr + 1] != '\0')
		{
			env_to_value(line, &ptr, &start, &res);
			continue ;
		}
		ptr++;
	}
	return (super_join(res, ft_substr(line, start, ptr - start)));
}
