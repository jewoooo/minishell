/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:19:18 by jewlee            #+#    #+#             */
/*   Updated: 2024/07/22 18:14:56 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (TRUE);
	return (FALSE);
}

t_bool	ft_isquote(char c)
{
	if (c == '\'' || c == '\"')
		return (TRUE);
	return (FALSE);
}

t_bool	ft_isoperator(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (TRUE);
	return (FALSE);
}

t_status	skip_quotes(char *line, int *i)
{
	char	quote;

	quote = line[*i];
	if (ft_strchr(line + (*i + 1), quote) != NULL)
	{
		(*i)++;
		while (line[*i] != quote)
			(*i)++;
		(*i)++;
		return (SUCCESS);
	}
	return (FAIL);
}