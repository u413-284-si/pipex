/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:53:20 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/29 19:14:03 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

/* ====== FUNCTIONS ====== */

void	cleanup(t_meta *meta);
void	do_close(int fd);
void	pipinator(t_meta *meta);
void	plug_pipes(t_meta *meta, int i);

#endif