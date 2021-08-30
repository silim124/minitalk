/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 18:01:13 by silim             #+#    #+#             */
/*   Updated: 2021/08/23 18:36:54 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <sys/time.h>

# define INVALID_PID 0
# define VALID_PID   1
# define GREEN "\e[1;92m"
# define RED "\e[1;91m"
# define YELLOW "\e[1;93m"
# define RESET "\033[0m"

int		ft_atoi(const char *str);
void	ft_putnbr(int num);
int		ft_strlen(const char *s);
void	put_error(char *str);
void	put_str(char *str);

#endif
