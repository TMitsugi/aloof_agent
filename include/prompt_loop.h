#ifndef PROMPT_LOOP_H
#define PROMPT_LOOP_H

#include <stdio.h>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>
#include <poll.h>

#define MAX_USER_PROMPT 8192

int identify_command(const char* command);
int prompt_loop();

#endif