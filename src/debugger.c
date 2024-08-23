#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <execinfo.h>
#include <string.h>
#include "debugger.h"
#include "io.h"

#define BACKTRACE_MAX_SZ 100

static const int subscribed_signals[] = { SIGSEGV, SIGILL, SIGFPE };

struct sigaction siga;

static void signal_handler(int sig)
{
	printf(RED "Caught exception! - %s\n\n" RESET, strsignal(sig));

	void *buffer[BACKTRACE_MAX_SZ];
	int nptrs = backtrace(buffer, BACKTRACE_MAX_SZ);
	char** strings = backtrace_symbols(buffer, nptrs);
	if (strings == NULL) {
		perror("backtrace_symbols");
		exit(EXIT_FAILURE);
	}

	printf("Backtrace (%d):\n", nptrs);
	printf("-------------------------------------------------------\n");
	for (int j = 0; j < nptrs; j++)
		printf(BLU "|-%s\n" RESET, strings[j]);
	printf("\n\n");
        free(strings); 
	abort();
}

void setup_signals()
{
	siga.sa_handler = signal_handler;
	for(int i = 0; i < sizeof(subscribed_signals) / sizeof(int); i++)
	{
		sigaction(subscribed_signals[i], &siga, NULL);
	}
}
