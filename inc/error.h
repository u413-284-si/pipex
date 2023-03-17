/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:13:43 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/17 18:40:51 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/* ====== LIBRARIES ====== */

# include <errno.h>

/* ====== DEFINITIONS ====== */

# define ERR_MEM "Memory allocation failed. :/"
# define ERR_OPEN "File failed to open. (⌣̩̩́_⌣̩̩̀)"
# define ERR_ARGC "Insufficient arguments. You disappoint me. (~_~;)"
# define ERR_PATH "Retrieval of cmd paths failed. (._.)"
# define ERR_PIPE "No pipe layed for you. (⌣́_⌣̀)\('́⌣'̀ )"
# define ERR_FORK "No forking for you. ( '́з'̀)"
# define ERR_CMD "Command retrieval failed. ¯\(°_o)/¯"
# define ERR_CMDEX "Command not executable, so sad.  ( T▾T)"

/* ====== FUNCTIONS ====== */

void	terminate(char *s);
int		input_check(char *s, t_meta *meta);
void	abort_mission(t_meta *meta, char *s);
void	no_senor(t_meta *meta, char *s);
void	mamma_mia(t_meta *meta, char *s);

#endif