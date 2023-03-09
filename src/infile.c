/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:38:22 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/09 16:42:32 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/infile.h"
#include "../inc/pipex.h"

int	read_infile(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	return (fd);
}
