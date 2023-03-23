/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:22:11 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/23 15:43:39 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHILDREN_H
# define CHILDREN_H

/* ====== FUNCTIONS ====== */

void	firstborn(t_meta *meta, char **envp);
void	lastborn(t_meta *meta, char **envp);
void	middle_child(t_meta *meta, char **envp);

#endif