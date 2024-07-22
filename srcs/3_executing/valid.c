/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 00:00:51 by jewlee            #+#    #+#             */
/*   Updated: 2024/07/22 19:06:28 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	valid_cmd_path(char *cmd_path)
{
	DIR	*dir;

	dir = opendir(cmd_path);
	if (dir != NULL)
	{
		ft_fprintf(STDERR_FILENO,
			"minishell: %s: is a directory\n", cmd_path);
		closedir(dir);
		exit(126);
	}
	if (access(cmd_path, F_OK) == -1)
	{
		ft_fprintf(STDERR_FILENO,
			"minishell: %s: No such file or directory\n", cmd_path);
		exit(127);
	}
	if (access(cmd_path, X_OK) == -1)
	{
		ft_fprintf(STDERR_FILENO,
			"minishell: %s: Permission denied\n", cmd_path);
		exit(126);
	}
}