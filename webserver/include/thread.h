//
// Created by Jesse on 2019/5/1.
//

#ifndef TINYSERVER_THREAD_H
#define TINYSERVER_THREAD_H

#include "http_request.h"


void dispatch_connection(int cli_fd, struct sockaddr_in cli_addr);

void fork_connection_handler(struct handle_connection_params* params);
void thread_connection_handler(struct handle_connection_params* params);

#endif //TINYSERVER_THREAD_H
