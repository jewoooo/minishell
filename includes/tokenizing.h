/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 02:40:32 by jewlee            #+#    #+#             */
/*   Updated: 2024/06/17 02:51:13 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZING_H
# define TOKENIZING_H

typedef enum s_tokentype
{
	INPUT_REDIRECT,
	OUTPUT_REDIRECT,
	APPEND_O_REDIRECT,
	HEREDOC,
	PIPE,
}	t_tokentype;

typedef struct s_token
{
	t_tokentype		type;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

t_token	*token_lst_new(char *value, t_tokentype type);
void	token_lst_clear(t_token **lst);
void	token_lst_add_back(t_token **lst, t_token *new);

#endif