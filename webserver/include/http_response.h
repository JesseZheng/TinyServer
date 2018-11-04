//
// Created by Jesse on 2018/10/2.
//

#ifndef TINYSERVER_HTTP_RESPONSE_H
#define TINYSERVER_HTTP_RESPONSE_H

void response_400(int);
void response_403(int);
void response_404(int);
void response_500(int);
void response_501(int);

void set_header(int, int, const char *);
void serve_file(int, const char *);
void getDate(char *);
void getPropertyOfFile(const char *, char *, char *);


#endif //TINYSERVER_HTTP_RESPONSE_H
