/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_echo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:41:02 by jewlee            #+#    #+#             */
/*   Updated: 2024/07/06 20:59:58 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// echo -nnnnnn hello 처리 필요함.
// echo -n -n -n -n hello 처리 필요함.
void	builtins_echo(t_command *cmd)
{
	int	i;

	if (cmd->args[1] == NULL)
	{
		printf("\n");
		return ;
	}
	if (ft_strncmp(cmd->args[1], "-n", 3) == 0)
	{
		i = 1;
		while (cmd->args[++i] != NULL)
			printf("%s", cmd->args[i]);
	}
	else
	{
		i = 0;
		while (cmd->args[++i] != NULL)
			printf("%s ", cmd->args[i]);
		printf("\n");
	}
}
