/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:48:32 by jewlee            #+#    #+#             */
/*   Updated: 2024/06/20 13:28:28 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

typedef enum	e_token_type
{
	IDENTIFIER,
	INPUT_REDIRECT,
	OUTPUT_REDIRECT,
	APPEND_O_REDIRECT,
	HEREDOC,
	PIPE,
}	t_token_type;

#endif