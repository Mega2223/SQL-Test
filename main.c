
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

typedef struct user {
    int id;
    char* username;
    char* visname;
} user;

typedef struct msg {
    int msgid;
    char* msgcontent;
    int usrid;
} msg;

int addUser(sqlite3* db, user* usr){
    const char* cmd_template = "INSERT INTO users (username,name) VALUES ('%s','%s');";
    char buff[128];
    sprintf(buff, cmd_template, usr->username, usr->visname);
    return sqlite3_exec(db, buff, NULL, NULL, NULL);
}

int addMsg(sqlite3* db, msg* msgg){
    const char* cmd_template = "INSERT INTO messages (content, userid) VALUES ('%s',%d);";
    char buff[128];
    sprintf(buff, cmd_template, msgg->msgcontent, msgg->usrid);
    return sqlite3_exec(db, buff, NULL, NULL, NULL);
}

void getUsers(sqlite3* db, char* where, user** usr, int* usrcount){
    
}

int main(){ 
    char cmd[32];
    int count, n;

    sqlite3* db;
    sqlite3_open("data.db", &db);

    printf("Olá mundo :)\n");

    while ((n = scanf("%s",cmd)) && strcmp(cmd, "exit") != 0){
        if(strcmp(cmd,"addusr") == 0){
            char username[64];
            char visname[64];
            user usr;
            usr.username = username;
            usr.visname = visname;
            scanf("%s", username);
            scanf("%s", visname);
            addUser(db, &usr);
        }
        if(strcmp(cmd,"addmsg") == 0){
            int userid;
            char content[128];
            int n2;
            
            printf("Insira uma mensagem no formato <id>:<msg>\n");
            n2 = scanf("%d:%s", &userid, content);
            if(n2 < 2){
                printf("Nuh uh\n");
                continue;
            }
            printf("Adicionando mensagem \"%s\" do usuário %d\n",content,userid);
            msg message;
            message.msgcontent = content;
            message.usrid = userid;

            addMsg(db, &message);
        }
    }

}
