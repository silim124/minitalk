/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 18:00:15 by silim             #+#    #+#             */
/*   Updated: 2021/08/23 19:41:39 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handler(int sig, siginfo_t *siginfo, void *unused)
{
	static unsigned char	msg = 0;
	static int				msg_len = 0;
	static int				catch_sig = 0;

	(void)siginfo;
	(void)unused;
	if (sig == SIGUSR1)
		msg += 1 << (7 - msg_len);
	if (++msg_len == 8)
	{
		write(STDOUT_FILENO, &msg, 1);
		if (!msg)
		{
			kill(siginfo->si_pid, SIGUSR1);
			put_str(GREEN"\n\n✧*.◟(ˊᗨˋ)◞.*✧\n");
			put_str("\nreceived an message successfully\n"RESET);
		}
		msg = 0;
		msg_len = 0;
	}
}

void	init_sigaction(struct sigaction *sigaction)
{
	sigaction->sa_flags = 0;
	sigaction->sa_sigaction = signal_handler;
	sigemptyset(&sigaction->sa_mask);
}

int	main(int argc, char **argv)
{
	struct sigaction	sact;

	(void)argv;
	if (argc == 1)
	{
		put_str("Server PID: ");
		ft_putnbr(getpid());
		put_str("\n");
		init_sigaction(&sact);
		if (((sigaction(SIGUSR1, &sact, 0)) == -1)
			|| ((sigaction(SIGUSR2, &sact, 0)) == -1))
			put_error(RED"Error! could not catch SIGUSR1 or SIGUSR2\n"RESET);
		while (1)
			pause();
	}
	else
		put_error(RED"Error! usage: ./server\n"RESET);
}
