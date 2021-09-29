/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 08:53:24 by zu                #+#    #+#             */
/*   Updated: 2021/09/28 14:11:13 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_message	g_msg;

void	ft_handler(int signl, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	(void)siginfo;
	g_msg.msg = g_msg.msg + ((signl & 1) << g_msg.msgsize);
	g_msg.msgsize++;
	if (g_msg.msgsize == 8)
	{
		write(1, &g_msg.msg, 1);
		if (!g_msg.msg)
		{
			write(1, "\n", 1);
			if (kill(siginfo->si_pid, SIGUSR2) == -1)
			{
				ft_printf("Error PID\n");
				exit (1);
			}
		}
		g_msg.msg = 0;
		g_msg.msgsize = 0;
	}
}

int	main(void)
{
	struct sigaction	newaction;

	g_msg.msg = 0;
	g_msg.msgsize = 0;
	ft_printf("server_bonus PID = %d\n", getpid());
	newaction.sa_flags = SA_SIGINFO;
	newaction.sa_sigaction = ft_handler;
	if ((sigaction(SIGUSR1, &newaction, NULL)) == -1)
	{
		ft_printf("Bit passing error\n");
		exit(1);
	}
	if ((sigaction(SIGUSR2, &newaction, NULL)) == -1)
	{
		ft_printf("Bit passing error\n");
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
