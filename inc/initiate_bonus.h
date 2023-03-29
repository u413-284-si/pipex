/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:42:13 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/29 19:02:13 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIATE_BONUS_H
# define INITIATE_BONUS_H

/* ====== FUNCTIONS ====== */

void	initiate(t_meta *meta, char **argv, int argc, char **envp);
void	init_var(t_meta *meta);
void	open_infile(t_meta *meta, char **argv);
void	open_outfile(t_meta *meta, char *s);
void	here_doc(t_meta *meta, char *s);

#endif