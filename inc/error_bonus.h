/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:13:43 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/29 18:43:51 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_BONUS_H
# define ERROR_BONUS_H

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
# define ERR_HEREDOC "Failed to create heredoc.  [つ﹏⊂]"
# define ERR_GNL "Get_next_line f** up.  ┐(´⌒｀)┌"
# define ERR_CLOSE "Could not close file.  (￣▽￣)"
# define ERR_DUP "Duplication of fd failed. Fanculo. (꘠_꘠)"
# define ERR_WAIT "While waiting for my child sth went wrong. ◎(╥ꞈ╥)◎"
# define ERR_LAST "Execution of lastborn failed. (*︵*)"
# define ERR_FIRST "Execution of firstborn failed. (◞╭╮◟)"
# define ERR_MID "Execution of midchild failed. 凸(◡ﮧ◡)凸"
# define ERR_FD "File descriptor invalid. (ง◎‸◎)ง"

/* ====== FUNCTIONS ====== */

void	terminate(char *s);
void	abort_mission(t_meta *meta, char *s);
void	no_senor(t_meta *meta, char *s);
void	mamma_mia(t_meta *meta, char *s);

#endif