/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 23:57:09 by jewlee            #+#    #+#             */
/*   Updated: 2024/07/23 00:25:29 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
# include <sys/wait.h>
# include <dirent.h>

# include "../libft/libft.h"

# include "./struct.h"
# include "./tokenizing.h"
# include "./parsing.h"

# define TEMPFILE "/tmp/heredoc_"
# define NONE -1

typedef struct s_info
{
	int					total_heredoc_cnt;
	int					exit_status;
	char				*line;
	char				**og_envp;
	char				**dup_envp;
	char				*home_dir;
	char				*pwd;
	t_list				*env_lst;
	pid_t				pid;
	t_token				*token;
	t_command			*cmd;
	struct termios		og_term;
	struct termios		ch_term;
}	t_info;

/*	0_init */
t_status	init_info(t_info *info, char **envp);
t_status	init_envp(t_info *info, char **envp);
void		heredoc_sigint(int sig);
void		init_signal(t_info *info);

/* 03_execute */
t_status	ft_execute(t_info *info);

/* heredoc */
void		create_heredoc(t_info *info, t_command *cmd);
void		init_heredoc(t_command *cmd);
void		write_heredoc(char *delimiter, int fd);
int			process_heredoc(t_info *info, t_command *cmd);
void		delete_heredoc(t_command *cmd);

/* set_redirect */
void		set_redirect_fd(t_command *cmd);

/* set_fd */
void		set_file_fd(t_command *cmd);
void		set_fd(t_command *cmd);
void		restore_std_fd(t_command *cmd);

/* path */
void		get_path(char **path, t_command **cmd);
char		*find_path(char **envp);

/* run */
void		run_commands(t_info *info, t_command *cmd, int *cnt);

/* vaild */
void		valid_cmd_path(char *cmd_path);

/* clear */
void		clear_executor(t_info *info);


/* 04_builtins */
void		ft_builtins(t_command *cmd, t_info *info);

void		builtins_cd(t_info *info, t_command *cmd);
void		builtins_env(t_info *info);
void		builtins_pwd(t_info *info);
void		builtins_echo(t_command *cmd, t_info *info);
void		builtins_exit(t_command *cmd, t_info *info);

/* unset */
void		builtins_unset(t_command *cmd, t_info *info);
char		**unset_dup_envp(t_list *env_lst);

/* export */
void		builtins_export(t_command *cmd, t_info *info);
void		print_export(t_info *info);
int			change_env(char *arg, t_list *env_lst, char *ptr);
void		export_fprintf_err(t_command *cmd, char *s, t_info *info);

/* utils */
char		*super_join(char *src1, char *src2);
void		sfree(void *ptr);

#endif