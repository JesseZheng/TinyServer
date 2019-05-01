//
// Created by Jesse on 2019/5/1.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <strings.h>

#include "thread.h"
#include "http_request.h"
#include "variable.h"
#include "unix_wrap.h"

void dispatch_connection(int cli_fd, struct sockaddr_in cli_addr){

    struct handle_connection_params* params = malloc(sizeof(struct handle_connection_params));
    params->cli_fd = cli_fd;
    params->cli_addr = cli_addr;

    if (!strcasecmp(dispatch_method, "fork"))
        fork_connection_handler(params);
    else if (!strcasecmp(dispatch_method, "thread"))
        thread_connection_handler(params);
    else {
        printf("Fatal: Unknown dispatch method!\n");
        exit(-1);
    }
}

void fork_connection_handler(struct handle_connection_params* params){
    pid_t pid = Fork();
    if (pid == 0){
        // Child
        handle_http_request(params);
        running = false;
    }
    else {
        // Parent
        close(params->cli_fd);
        free(params);
    }
}

void thread_connection_handler(struct handle_connection_params* params){
    pthread_t child_thread;

    // create thread
    if(pthread_create(&child_thread, NULL, (void*)handle_http_request, (void*)params)) {
        fprintf(stderr, "Error creating thread\n");
        exit(-1);
    }
    pthread_detach(child_thread);
}