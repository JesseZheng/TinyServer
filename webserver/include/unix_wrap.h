//
// Created by Jesse on 2018/10/2.
//

#ifndef TINYSERVER_UNIX_WRAP_H
#define TINYSERVER_UNIX_WRAP_H

pid_t Fork(void);
int Open(const char *pathname, int flags, mode_t mode);
FILE * Fopen(const char * path, const char * mode);
void init_daemon(const char *cmd);

#endif //TINYSERVER_UNIX_WRAP_H

