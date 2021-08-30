/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 18:00:57 by silim             #+#    #+#             */
/*   Updated: 2021/08/30 15:41:20 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_valid_pid(const char *pid, int pid_n)
{
	int	i;

	i = -1;
	if (!pid)
		return (INVALID);
	if (pid_n < 100 || 99998 < pid_n)
		return (INVALID);
	while (pid[++i])
		if (pid[i] < '0' || pid[i] > '9')
			return (INVALID);
	return (VALID);
}

static void	send_message(int pid, const char *message, int msg_len)
{
	unsigned char	bit;
	int				i;

	i = -1;
	put_str(GREEN"sending the message to the server...\n"RESET);
	while (++i <= msg_len)
	{
		bit = 1 << 7;
		while (bit)
		{
			if (((message[i] & bit) && kill(pid, SIGUSR1) == -1)
				|| (!(message[i] & bit) && kill(pid, SIGUSR2) == -1))
				put_error(YELLOW"Error! no server with this PID\n"RESET);
			bit >>= 1;
			usleep(100);
		}
	}
}

static void	handle_sig(int sig_num)
{
	put_str(GREEN"\n\n✧*.◟(ˊᗨˋ)◞.*✧\n");
	put_str("sent successfully!\n"RESET);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		put_error(YELLOW"Error! usage: ./client <server PID> <string>\n"RESET);
	else if (is_valid_pid(argv[1], ft_atoi(argv[1])))
	{
		signal(SIGUSR1, handle_sig);
		send_message(ft_atoi(argv[1]), argv[2], ft_strlen(argv[2]));
	}
	else
		put_error(YELLOW"Error! the pid is out of valid range\n"RESET);
}
