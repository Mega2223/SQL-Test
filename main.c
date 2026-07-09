
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(){
    printf("Olá mundo :)\n");
    
    char name[32], usr[32];
    int count, n;

    sqlite3* db;
    sqlite3_open("data.db", &db);

    while ((count = scanf("%s %s", name, usr))) {
        if (count < 2)
            continue;

        // sprintf(usr, "[usr]:%s %s\n", name, usr);
        char buff[128];
        sprintf(buff ,"INSERT INTO users (username,name) VALUES ('%s','%s');",usr,name);
        
        int status = sqlite3_exec(db,buff, NULL, NULL, NULL);
        printf("status %d\n",status);
    }

}
