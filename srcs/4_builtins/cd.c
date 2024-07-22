/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:39:49 by jewlee            #+#    #+#             */
/*   Updated: 2024/07/22 19:43:53 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*load_home_dir(t_info *info, t_command *cmd, char *line)
{
	char	*home;

	if (!cmd->args[1])
	{
		home = getenv("HOME");
		if (!home)
		{
			write(STDERR_FILENO, "cd : HOME not set\n", 21);
			return (NULL);
		}
		return (home);
	}
	return (ft_strjoin(info->home_dir, line));
}

void	chagne_oldpwd(t_info *info, char *newpwd)
{
	char	*oldpwd;

	oldpwd = ft_strjoin("OLDPWD=", info->pwd);
	change_env(oldpwd, info->env_lst, oldpwd + 6);
	info->dup_envp = unset_dup_envp(info->env_lst);
	free(info->pwd);
	info->pwd = newpwd;
}

t_bool	ft_chdir(t_info *info, char *dir)
{
	char	cwd[PATH_MAX];
	char	*newpwd;

	if (chdir(dir) != 0)
	{
		ft_fprintf(STDERR_FILENO, "minishell: cd: %s: ", dir);
		return (FALSE);
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		if (info->pwd[ft_strlen(info->pwd) - 1] != '/')
			info->pwd = super_join(info->pwd, ft_strdup("/"));
		newpwd = ft_strjoin(info->pwd, dir);
	}
	else
		newpwd = ft_strdup(cwd);
	chagne_oldpwd(info, newpwd);
	chdir(newpwd);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		ft_fprintf(STDERR_FILENO, "cd: error retrieving current directory: ");
		ft_fprintf(STDERR_FILENO, "getcwd:cannot access parent directories: ");
		return (FALSE);
	}
	return (TRUE);
}

void	builtins_cd(t_info *info, t_command *cmd)
{
	char	*dir;

	if (!cmd->args[1])
		dir = load_home_dir(info, cmd, NULL);
	else if (cmd->args[1][0] == '~')
		dir = load_home_dir(info, cmd, cmd->args[1] + 1);
	else
		dir = cmd->args[1];
	if (!ft_chdir(info, dir))
		ft_fprintf(STDERR_FILENO, "No such file or directory\n");
}
