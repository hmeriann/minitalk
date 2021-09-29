/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:06:36 by zu                #+#    #+#             */
/*   Updated: 2021/09/28 13:48:47 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendmessage(int pid, char *message)
{
	int		shiftscount;
	size_t	i;
	size_t	msglen;

	i = 0;
	msglen = ft_strlen(message);
	while (i <= msglen)
	{
		shiftscount = 0;
		while (shiftscount < 7)
		{
			if ((message[i] >> shiftscount) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			shiftscount++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	pid = 0;
	if (argc != 3)
	{
		ft_printf("Correct format is <PID> <\"message\">\n");
		exit(1);
	}
	pid = ft_atoi1(argv[1]);
	if (pid <= 0)
	{
		ft_printf("PID should be numeric\n");
		exit(1);
	}
	ft_sendmessage(pid, argv[2]);
	return (0);
}
