/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:17:29 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/09 16:36:47 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* ====== LIBRARIES ====== */

# include <fcntl.h>			        /* required for opening files */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>				/* required to kill processes*/
# include <sys/wait.h>				/* required for wait calls */
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/gnl/get_next_line_bonus.h"

/* ====== DEFINITIONS ====== */

/* ====== STRUCTS ====== */

typedef struct s_meta
{
	char	*buf;
}	t_meta;

#endif