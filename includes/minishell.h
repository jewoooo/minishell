/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 23:57:09 by jewlee            #+#    #+#             */
/*   Updated: 2024/06/19 13:20:12 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

typedef enum	s_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef enum	s_status
{
	SUCCESS,
	FAIL,
}	t_status;

# include "../libft/libft.h"
# include "./tokenizing.h"

t_status	er_printf(char *s);

#endif