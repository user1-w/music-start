#ifndef COMMENT_H
#define COMMENT_H
#include <stdio.h>
#include <string.h>
#include <QMessageBox>

#define LOGIN 1;
#define REGISTER 2;

struct QMSG
{
    char buf[1022];
    short int type;
};

struct registered_msg
{
    registered_msg(const char *name,const char *passwd){
        strcpy(this->name,name); strcpy(this->passwd,passwd);
    }
    char name[128];
    char passwd[128];
};


#endif // COMMENT_H
