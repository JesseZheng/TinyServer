//
// Created by Jesse on 2018/10/5.
//

#ifndef TINYSERVER_VARIABLE_H
#define TINYSERVER_VARIABLE_H

#include <stdbool.h>

#define BUFSIZE 1024
#define HEADERSIZE 255
#define ROOTDIR "../www"
#define SERVER_STRING "Server: TinyServer\r\n"
#define DEFAULT_PORT 8080
#define CONCURRENT "fork"

struct configItem
{
    char key[20];
    char value[50];
};

extern char* root_dir;
extern bool running;
extern char* dispatch_method;

#endif //TINYSERVER_VARIABLE_H
