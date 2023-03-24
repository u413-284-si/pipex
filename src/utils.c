/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:02:39 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/24 15:08:43 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../inc/utils.h"

/* This function searches for the PATH in the environment and returns
it. */

char	*get_path(char **envp)
{
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	return (*envp + 5);
}

/* This function verifies if the first argument is 'here_doc' and sets the
corresponding bool accordingly and returns the expected minimal number of
arguments to the program (including the program name itself). */

int	input_check(char *s, t_meta *meta)
{
	int	len;

	len = ft_strlen(s);
	if (len == 8 && ft_strncmp(s, "here_doc", len) == 0)
	{
		meta->here_doc = 1;
		return (6);
	}
	else
	{
		meta->here_doc = 0;
		return (5);
	}
}
