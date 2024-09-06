#ifndef COMMENT_H
#define COMMENT_H
#include <stdio.h>
#include <string.h>
#include <QString>

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

struct song//存放歌曲信息
{
    char name[128];
    char artists[128];
    char album[128];
    int id;
    int song_time;
    char picId[128];
};

#endif // COMMENT_H
