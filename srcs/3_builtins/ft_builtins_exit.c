/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:03:05 by jewlee            #+#    #+#             */
/*   Updated: 2024/07/07 22:45:24 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// exit 3 | echo hello -> 다중 커맨드는 exit 이 안됨.
// exit 1 2 -> args[2] != NULL too many arguments.
void	builtins_exit(t_command *cmd)
{
	int	exit_value;

	printf("exit\n");
	if (cmd->args[2] != NULL)
	{
		write(STDERR_FILENO, "minishell: exit: too many arguments\n", 37);
		return ;
	}
	check_isnum(cmd->args[1]);
	exit(SUCCESS);
}
