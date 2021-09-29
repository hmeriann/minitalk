/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 08:53:24 by zu                #+#    #+#             */
/*   Updated: 2021/09/28 13:42:43 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_message	g_msg;

void	ft_handler(int signl)
{
	g_msg.msg = g_msg.msg + ((signl & 1) << g_msg.msgsize);
	g_msg.msgsize++;
	if (g_msg.msgsize == 7)
	{
		write(1, &g_msg.msg, 1);
		if (!g_msg.msg)
			write(1, "\n", 1);
		g_msg.msg = 0;
		g_msg.msgsize = 0;
	}
}

int	main(void)
{
	g_msg.msg = 0;
	g_msg.msgsize = 0;
	ft_printf("server PID = %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}
