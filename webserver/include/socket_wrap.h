//
// Created by Jesse on 2018/10/1.
//

#ifndef TINYSERVER_SOCKET_WRAP_H
#define TINYSERVER_SOCKET_WRAP_H

int Socket(int domain, int type, int protocol);
int Bind(int sockfd, const struct sockaddr *serv_addr, socklen_t serv_addr_len);
int Accept(int sockfd, struct sockaddr *cli_addr, socklen_t *cli_addr_len);
int Listen(int sockfd, int backlog);


#endif //TINYSERVER_SOCKET_WRAP_H
