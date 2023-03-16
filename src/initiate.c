/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:42:02 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/16 17:26:06 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/initiate.h"
#include "../inc/pipex.h"
#include "../inc/error.h"

void	initiate(t_meta *meta, char **argv, int argc, char **envp)
{
	open_infile(meta, argv);
	open_outfile(meta, argv[argc - 1]);
	meta->cmd_num = argc - 3 - meta->here_doc;
	meta->cmds = ft_calloc(meta->cmd_num, sizeof(t_cmd));
	if (!meta->cmds)
		terminate(ERR_MEM);
	meta->the_path = get_path(envp);
	meta->cmd_paths = ft_split(meta->the_path, ':');
	if (!meta->cmd_paths)
		abort_mission(meta);
}

void	open_infile(t_meta *meta, char **argv)
{
	if (meta->here_doc == 0)
	{
		meta->infile = argv[1];
		meta->fd_in = open(meta->infile, O_RDONLY);
		if (meta->fd_in < 3)
			terminate(ERR_OPEN);
	}
}

void	open_outfile(t_meta *meta, char *s)
{
	meta->outfile = s;
	if (meta->here_doc)
		meta->fd_out = open(meta->outfile, O_WRONLY | O_APPEND \
			| O_CREAT, 0644);
	else
		meta->fd_out = open(meta->outfile, O_RDWR | O_TRUNC \
			| O_CREAT, 0644);
	if (meta->fd_out < 3)
		terminate(ERR_OPEN);
}

char	*get_path(char **envp)
{
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	return (*envp + 5);
}
