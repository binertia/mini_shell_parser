#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
	}
	else if (signal == SIGQUIT)
	{
		return ;
	}
}

void	init_sig_handle()
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}

int	main(void)
{
	init_sig_handle();
	while (1)
	{
	}
}
