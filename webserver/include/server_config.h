//
// Created by Jesse on 2018/10/12.
//

#ifndef TINYSERVER_SERVER_CONFIG_H
#define TINYSERVER_SERVER_CONFIG_H

int strkv(char *src, char *key, char *value);
void get_config(char *configFilePath, struct configItem * configVar, int configNum);

#endif //TINYSERVER_SERVER_CONFIG_H
