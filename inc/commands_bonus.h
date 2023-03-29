/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:38:22 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/29 18:45:07 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_BONUS_H
# define COMMANDS_BONUS_H

/* ====== FUNCTIONS ====== */

void	execute_commands(t_meta *meta, char **argv, char **envp);
void	create_child(t_meta *meta, char **envp);
void	raise_first(t_meta *meta, char **envp);
void	raise_middle(t_meta *meta, char **envp);
void	raise_last(t_meta *meta, char **envp);

#endif