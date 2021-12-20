#ifndef nb_db_H
#define nb_db_H

#include "libpqnb/include/pqnb.h"
#include "libpq-fe.h"
#include <iostream>
#include <string>
#include <string>
#include <iostream>
#include <vector>
#include <sys/epoll.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <assert.h>

using namespace std;

/**
 * Struct to make accessing database results easier.
 */
struct DBValue{
    char type;
    int intVal;
    string strVal;
    DBValue(): type('N'), intVal(-1), strVal(""){}
    DBValue(char type, int intValue, string strValue): type(type), intVal(intValue), strVal(strValue){}
    // other types in the future
};

/**
 * Class that creates the connection pool to the database and handles queries to said pool.
 */
class NbDB {
public:
    NbDB();
    /**
     * Constructor for non-blocking database.
     */
    NbDB(string user, string pass, string database, string ip);
    //look into actually implementing this later
    //~DB();
    // These are all depricated/need to be updated.
    void close(){  };
    bool isConnected(){ return connected; };
    string getDatabase(){ return database; };

    void printResult(PGresult *res);

    void insertUserQuery(string username, string hash, string salt, string email);

    void userCredQuery(string username, vector<vector<DBValue>> &addInfo);

private:
    string user;
    string pass;
    string ip;
    bool connected;
    PQNB_pool *pool;
    const union PQNB_pool_info *info;
    int epoll_fd;
    string database;
    struct epoll_event ev;
    int ctl_res;
};

#endif
