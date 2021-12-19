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
    int intValue;
    string stringValue;
    DBValue(): type('N'), intValue(-1), stringValue(""){}
    DBValue(char type, int intValue, string stringValue): type(type), intValue(intValue), stringValue(stringValue){}
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
    void insert(string stmt);
    /**
     * Basic query to a give table in the database, with a max desired amount of results.
     * @param table to query.
     * @param size of the query (max number of results).
     * @param[out] addInfo the results of the query converted into a 2D vector of DBValues.
     */
    void basicQuery(string table, int size, vector<vector<DBValue>> &addInfo);
    // Depricated, only really left in for testing.
    void printResult(PGresult *res);
    /**
     * Queries the users table and returns the specified user if they exist.
     * @param username of account.
     * @param[out] addInfo the results of the query converted into a 2D vector of DBValues.
     */
    void userQuery(string username, vector<vector<DBValue>> &addInfo);
    // in the future we may want to have these userdata functions
    // be just one method, but idk if that will entail security risks.
    /**
     * Returns the usernames of the accounts a given user is following.
     * @param username of the account getting their following queried.
     * @param[out] addInfo the results of the query converted into a 2D vector of DBValues.
     */
    void userFollowingQuery(string username, vector<vector<DBValue>> &addInfo);
    /**
     * Returns the ids of the posts a given user has saved.
     * @param username of the account getting their saved posts queried.
     * @param[out] addInfo the results of the query converted into a 2D vector of DBValues.
     */
    void userSavedQuery(string username, vector<vector<DBValue>> &addInfo);
    /**
     * Returns the post ids of a given set of usernames.
     * @param usernames of the accounts whose posts are getting queired.
     * @param[out] addInfo the results of the query converted into a 2D vector of DBValues.
     */
    void userPostQuery(string usernames, vector<vector<DBValue>> &addInfo);
    /**
     * Returns the post data of a given set of post ids.
     * @param ids of the posts being queired.
     * @param[out] addInfo the results of the query converted into a 2D vector of DBValues.
     */
    void queryPostSet(string ids, vector<vector<DBValue>> &addInfo);
    /**
     * Returns the profile data of a given account.
     * @param username of account getting their profile queried.
     * @param[out] addInfo the results of the query converted into a 2D vector of DBValues.
     */
    void queryProfile(string username, vector<vector<DBValue>> &addInfo);
    /**
     * Retruns the profile data of a give set of account usernames.
     * @param usernames of accounts getting their profile queried.
     * @param[out] addInfo the results of the query converted into a 2D vector of DBValues.
     */
    void queryProfiles(string usernames, vector<vector<DBValue>> &addInfo);
    /**
     * Updates the set of saved post ids of a give account.
     * @param username of account getting their saved post list updated.
     * @param savedIds new set of saved post ids.
     */
    void savedUpdate(string username, string savedIds);
    /**
     * Not currently implemented properly.
     */
    void updateCreds(string username, string hash, string salt);

    void queryGroupNames(string groupIds, vector<vector<DBValue>> &addInfo);
    
    void queryMessages(string groupIds, vector<vector<DBValue>> &addInfo);

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
