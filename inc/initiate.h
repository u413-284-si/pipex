/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:42:13 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/17 12:11:29 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIATE_H
# define INITIATE_H

/* ====== FUNCTIONS ====== */

void	initiate(t_meta *meta, char **argv, int argc, char **envp);
void	open_infile(t_meta *meta, char **argv);
void	open_outfile(t_meta *meta, char *s);
char	*get_path(char **envp);

#endif