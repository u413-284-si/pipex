/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:17:29 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/17 14:11:10 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* ====== LIBRARIES ====== */

# include <fcntl.h>			        /* required for opening files */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <signal.h>				/* required to kill processes*/
# include <sys/wait.h>				/* required for wait calls */
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/gnl/get_next_line_bonus.h"

/* ====== DEFINITIONS ====== */

/* ====== STRUCTS ====== */

typedef struct s_cmd
{
	char	*cmd;
	char	**arg;
	int		fd[2];
}	t_cmd;

typedef struct s_meta
{
	char	*infile;
	char	*outfile;
	int		fd_in;
	int		fd_out;
	bool	here_doc;
	int		cmd_num;
	char	*the_path;
	char	**cmd_paths;
	t_cmd	*cmds;
	int		i;
	pid_t	pid;
}	t_meta;

#endif