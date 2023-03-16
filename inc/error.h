/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:13:43 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/16 17:33:58 by sqiu             ###   ########.fr       */
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

/* ====== FUNCTIONS ====== */

void	terminate(char *s);
int		input_check(char *s, t_meta *meta);

#endif