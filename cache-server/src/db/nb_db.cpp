#include "nb_db.h"
#include <unistd.h>
#include <cstring>
//#include <sys/epoll.h>

NbDB::NbDB(){
}

// doesn't actually do anything with these inputs atm lmao
NbDB::NbDB(string user, string pass, string database, string ip = "localhost"){
    this->user = user;
    this->pass = pass;
    this->ip = ip;
    this->database = database;
    struct PQNB_pool *pool;
    pool = PQNB_pool_init("postgresql://test:Password22!@localhost/workoutdev?sslmode=disable", 32);
    assert(NULL != pool);
    const union PQNB_pool_info *info;
    int epoll_fd;
    //struct epoll_event ev, evs[1];
    info = PQNB_pool_get_info(pool, PQNB_INFO_EPOLL_FD);
    assert(NULL != info);
    assert(info->epoll_fd != -1);
    epoll_fd = epoll_create1(EPOLL_CLOEXEC);
    assert(epoll_fd != -1);
    this->pool = pool;
    this->info = info;
    this->epoll_fd = epoll_fd;
    struct epoll_event ev, evs[1];
    ev.events = EPOLLIN;
    ev.data.ptr = NULL;
    int res = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, info->epoll_fd, &ev);
    assert(-1 != res);
    this->ev = ev;
    //this->evs = evs;
    this->ctl_res = res;
}

//vector<vector<DBValue>> convertResult(PGresult *res){
//    int cols = PQnfields(res);
//    int rows = PQntuples(res);
//    vector<vector<DBValue>> values;
//    int types[cols];
//    for(int i = 0; i < cols; i++){
//        types[i] = (int)PQftype(res,i);
//    }
//    //cout << "starting" << endl;
//    for(int i = 0; i < rows; i++){
//        vector<DBValue> currRow;
//        for(int j = 0; j < cols; j++){
//            switch(types[j]){
//                case 23:
//                {
//                    currRow.push_back(DBValue{'i', atoi(PQgetvalue(res, i, j)), ""});
//                    break;
//                }
//                case 19:
//                    {
//                        currRow.push_back(DBValue{'i', atoi(PQgetvalue(res, i, j)), ""});
//                        break;
//                    }
//                case 1043:
//                    {
//                        DBValue temp = DBValue{'s', 0, PQgetvalue(res, i, j)};
//                        currRow.push_back(temp);
//                        break;
//                    }
//                case 25:
//                    {
//                        currRow.push_back(DBValue{'s', 0, PQgetvalue(res, i, j)});
//                        break;
//                    }
//                default:
//                    cout << "failed, type unknown for row: " << j << " column: " << i << endl;
//                    //break;
//            }
//        }
//        values.push_back(currRow);
//    }
//    //PQclear(res);
//    //cout << "done converting" << endl;
//    //for(int i = 0; i < rows; i++){
//    //    for(int j = 0; j < cols-1; j++){
//    //        cout << values[i][j].stringValue << " | ";
//    //    }
//    //    cout << values[i][cols-1].stringValue << endl;
//    //}
//    return values;
//}
//
//void convertResult(PGresult *res, vector<vector<DBValue>> &values){
//    int cols = PQnfields(res);
//    int rows = PQntuples(res);
//    //cout << cols << endl;
//    //cout << rows << endl;
//    //DBValue values[rows][cols];
//    //vector<vector<DBValue>> values;
//    int types[cols];
//    for(int i = 0; i < cols; i++){
//        types[i] = (int)PQftype(res,i);
//        //cout << "Column oid: " << types[i] << endl;
//    }
//    //cout << "starting" << endl;
//    for(int i = 0; i < rows; i++){
//        //cout << "looping row" << endl;
//        //vector<DBValue> currRow;
//        for(int j = 0; j < cols; j++){
//            //cout << "looping cols" << endl;
//            //cout << types[j] << endl;
//            switch(types[j]){
//                case 23:
//                {
//                    //cout << "integer" << endl;
//                    //cout << atoi(PQgetvalue(res, i, j)) << endl;
//                    //struct DBValue intTemp = DBValue{'i', 0, ""};
//                    //intTemp.intValue = atoi(PQgetvalue(res, i, j));
//                    //cout << intTemp.intValue << endl;
//                    values[i][j] = DBValue{'i', atoi(PQgetvalue(res, i, j)), ""};
//                    //cout << "pushed" << endl;
//                    break;
//                }
//                case 19:
//                    {
//                        values[i][j] = DBValue{'i', atoi(PQgetvalue(res, i, j)), ""};
//                        break;
//                    }
//                case 1043:
//                    {
//                        //currRow.push_back(new StringValue{PQgetvalue(res, i, j)});
//                        DBValue temp = DBValue{'s', 0, PQgetvalue(res, i, j)};
//
//                        //cout << temp.stringValue << endl;
//                        values[i][j] = temp;
//                        //cout << tempVal.value << endl;
//                        //currVal = StringValue{PQgetvalue(res,j ,i)};
//                        //currVal = tempVal;
//                        //cout << PQgetvalue(res,j ,i) << endl;
//                        //cout << currVal.value << endl;
//                        break;
//                    }
//                case 25:
//                    {
//                        //currRow.push_back(new StringValue{PQgetvalue(res, i, j)});
//                        values[i][j] = DBValue{'s', 0, PQgetvalue(res, i, j)};
//                        //cout << tempVal.value << endl;
//                        //currVal = StringValue{PQgetvalue(res,j ,i)};
//                        //currVal = tempVal;
//                        //cout << PQgetvalue(res,j ,i) << endl;
//                        //cout << currVal.value << endl;
//                        break;
//                    }
//                default:
//                    cout << "failed, type unknown for row: " << j << " column: " << i << endl;
//                    //break;
//            }
//            // I forget if this calls a copy constructor or it is a reference.
//            //values.at(j).at(i) = currVal;
//        }
//        //values.push_back(currRow);
//    }
//    values.resize(rows);
//    //PQclear(res);
//    //cout << "done converting" << endl;
//    //for(int i = 0; i < rows; i++){
//    //    for(int j = 0; j < cols-1; j++){
//    //        cout << values[i][j].stringValue << " | ";
//    //    }
//    //    cout << values[i][cols-1].stringValue << endl;
//    //}
//    //return values;
//}

// converts the results of a database query into a 2D vector of DBValues for easier use.
void convertResult(PGresult *res, vector<vector<DBValue>> &values){
    int cols = PQnfields(res);
    int rows = PQntuples(res);
    //cout << cols << endl;
    //cout << rows << endl;
    int types[cols];
    for(int i = 0; i < cols; i++){
        types[i] = (int)PQftype(res,i);
        //cout << "Column oid: " << types[i] << endl;
    }
    //cout << "starting" << endl;
    for(int i = 0; i < rows; i++){
        //cout << "looping row" << endl;
        vector<DBValue> currRow;
        for(int j = 0; j < cols; j++){
            //cout << "looping cols" << endl;
            //cout << types[j] << endl;
            switch(types[j]){
                case 23:
                {
                    currRow.push_back(DBValue{'i', atoi(PQgetvalue(res, i, j)), ""});
                    break;
                }
                case 19:
                    {
                        currRow.push_back(DBValue{'i', atoi(PQgetvalue(res, i, j)), ""});
                        break;
                    }
                case 1043:
                    {
                        DBValue temp = DBValue{'s', 0, PQgetvalue(res, i, j)};
                        currRow.push_back(temp);
                        break;
                    }
                case 25:
                    {
                        currRow.push_back(DBValue{'s', 0, PQgetvalue(res, i, j)});
                        break;
                    }
                default:
                    cout << "failed, type unknown for row: " << j << " column: " << i << endl;
            }
        }
        values.push_back(currRow);
    }
    //PQclear(res);
    //cout << "done converting" << endl;
    //for(int i = 0; i < rows; i++){
    //    for(int j = 0; j < cols-1; j++){
    //        cout << values[i][j].stringValue << " | ";
    //    }
    //    cout << values[i][cols-1].stringValue << endl;
    //}
    //return values;
}

// depricated.
void NbDB::printResult(PGresult *res){
    int colNum = PQnfields(res);
    for(int i = 0; i < PQntuples(res); i++){
        for(int j = 0; j < colNum-1; j++){
            cout << PQgetvalue(res, i, j) << "|";
        }
        cout << PQgetvalue(res,i,colNum-1) << endl;
    }
}
// neatly print out the results of a database query.
void printRes(PGresult *res){
    int colNum = PQnfields(res);
    for(int i = 0; i < PQntuples(res); i++){
        for(int j = 0; j < colNum-1; j++){
            cout << PQgetvalue(res, i, j) << "|";
        }
        cout << PQgetvalue(res,i,colNum-1) << endl;
    }
}

// struct for query callback.
struct query_info { PGresult *resRet; bool flag;};

// callback of a database query.
void query_cb(PGresult *res, void *user_data, char *error_msg, bool timeout){
  struct query_info * querys_info;
  /*
   * ignoring compiler warnings
   */
  //cout << "error msg: " << error_msg << endl;
  //(void) res;
  if (timeout){
      printf("timeout\n");
      return;
  }
  if (NULL != error_msg){
      printf("%s", error_msg);
      return;
  }
  if (PGRES_TUPLES_OK == PQresultStatus(res)){
      assert(NULL != user_data);
      //querys_info = (query_info*)user_data;
      querys_info = reinterpret_cast<query_info*>(user_data);
      querys_info->resRet = PQcopyResult(res, PG_COPYRES_TUPLES);
      querys_info->flag = true;
  }
  else if(PGRES_EMPTY_QUERY == PQresultStatus(res)){
    printf("empty string sent\n");
  }
  else if(PGRES_COPY_OUT == PQresultStatus(res)){
    printf("copy out data transfer started\n");
  }
  else if(PGRES_COPY_IN == PQresultStatus(res)){
    printf("copy in data transfer started\n");
  }
  else if(PGRES_BAD_RESPONSE == PQresultStatus(res)){
    printf("server reponse not understood\n");
  }
  else if(PGRES_NONFATAL_ERROR == PQresultStatus(res)){
    printf("a nonfatal error (notice or warning) occured\n");
  }
  else if(PGRES_FATAL_ERROR == PQresultStatus(res)){
    printf("a fatal error occured\n");
    cout << PQresultErrorMessage(res) << endl;
    //cout << PQresultErrorField(res, PG_DIAG_MESSAGE_PRIMARY) << endl;
    //cout << PQresultErrorField(res, PG_DIAG_MESSAGE_HINT) << endl;
    //cout << PQresultErrorField(res, PG_DIAG_CONTEXT) << endl;
    //cout << PQresultErrorField(res, PG_DIAG_MESSAGE_DETAIL) << endl;
    //cout << PQresultErrorField(res, PG_DIAG_SEVERITY) << endl;
  }
  else{
    printf("query failed\n");
    return;
  }
}

// Non-blocking query request.
PGresult * queryNB(PQNB_pool *pool, const union PQNB_pool_info *info, int epoll_fd, string stmt){
    struct epoll_event evs[1];
    struct query_info qInfo;
    qInfo.resRet = nullptr;
    qInfo.flag = false;
    //ev.events = EPOLLIN;
    //ev.data.ptr = NULL;
    //int res = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, info->epoll_fd, &ev);
    //assert(-1 != res);
    //cout << "queryNB started" << endl;
    // filling query buffer
    //while(-1 != PQNB_pool_query(pool, stmt.c_str(), query_cb, &qInfo));
    if(-1 == PQNB_pool_query(pool, stmt.c_str(), query_cb, &qInfo)){
        cout << "pool query failed" << endl;
        exit(1);
    }
    //cout << "query pooled" << endl;
    while(qInfo.resRet == nullptr){
        //cout << "begin epoll" << endl;
        int res = epoll_wait(epoll_fd, evs, 1, 1000);
        //cout << "epoll finished" << endl;
        if (res == -1){
            cout << "res is -1" << endl;
            break;
        }
        //cout << "running pool" << endl;
        if (PQNB_pool_run(pool) == -1){
            cout << "poll run is -1" << endl;
            break;
        }
        //cout << "pool ran" << endl;
        //cout << "waited" << endl;
    }
    //cout << "db call finished" << endl;
    return qInfo.resRet;
}

void NbDB::insert(string stmt){
    PGresult *res = queryNB(pool, info, epoll_fd, stmt);
    //convertResult(res);
    //PQclear(res);
}

void NbDB::basicQuery(string table, int size, vector<vector<DBValue>> &addInfo){
    string stmt = "SELECT * FROM " + table + " ORDER BY id DESC LIMIT " + to_string(size) + ";";
    //cout << stmt << endl;
    PGresult* res = queryNB(pool, info, epoll_fd, stmt);
    //cout << "converting" << endl;
    convertResult(res, addInfo);
    //cout << "about to return" << endl;
    //return converted;
}

//////hardcoded for security reasons
//////add salting coloum query later
void NbDB::userQuery(string username, vector<vector<DBValue>> &addInfo){
    string stmt = "SELECT hash, salt FROM users WHERE username = '" + username +"';";
    convertResult(queryNB(pool, info, epoll_fd, stmt), addInfo);
}

void NbDB::userFollowingQuery(string username, vector<vector<DBValue>> &addInfo){
    string stmt = "SELECT following FROM userdata WHERE username = '" + username +"';";
    convertResult(queryNB(pool, info, epoll_fd, stmt), addInfo);
}

void NbDB::userSavedQuery(string username, vector<vector<DBValue>> &addInfo){
    string stmt = "SELECT saved FROM userdata WHERE username = '" + username +"';";
    convertResult(queryNB(pool, info, epoll_fd, stmt), addInfo);
}

void NbDB::userPostQuery(string usernames, vector<vector<DBValue>> &addInfo){
    string stmt = "SELECT posts FROM userdata WHERE username IN (" + usernames +");";
    convertResult(queryNB(pool, info, epoll_fd, stmt), addInfo);
}

void NbDB::queryPostSet(string ids, vector<vector<DBValue>> &addInfo){
    string stmt = "SELECT * FROM post WHERE id IN (" + ids +");";
    convertResult(queryNB(pool, info, epoll_fd, stmt), addInfo);
}

//////may not want to query every column
void NbDB::queryProfile(string username, vector<vector<DBValue>> &addInfo){
    string stmt = "SELECT * FROM userdata WHERE username = '" + username +"';";
    convertResult(queryNB(pool, info, epoll_fd, stmt), addInfo);
}

//may not want o query every column
void NbDB::queryProfiles(string usernames, vector<vector<DBValue>> &addInfo){
    string stmt = "SELECT username, first, last, picture FROM userdata WHERE username IN (" + usernames + ");";
    PGresult* res = queryNB(pool, info, epoll_fd, stmt);
    convertResult(res, addInfo);
}

void NbDB::savedUpdate(string username, string savedIds){
    string stmt = "UPDATE userdata SET saved = '" + savedIds + "' WHERE username = '" + username + "';";
    queryNB(pool, info, epoll_fd, stmt);
}

void NbDB::updateCreds(string username, string hash, string salt){
    string stmt = "UPDATE users SET hash = '" + hash + "', salt = '" + salt + "' WHERE username = '" + username + "';";
    queryNB(pool, info, epoll_fd, stmt);
}

void NbDB::queryGroupNames(string groupIds, vector<vector<DBValue>> &addInfo){
    string stmt = "SELECT id, name, picture FROM groups WHERE id IN (" + groupIds + ");";
    PGresult* res = queryNB(pool, info, epoll_fd, stmt);
    convertResult(res, addInfo);
}

void NbDB::queryMessages(string groupIds, vector<vector<DBValue>> &addInfo){
    string stmt = "SELECT sendor, groupid, data FROM message WHERE groupid IN (" + groupIds + ");";
    PGresult* res = queryNB(pool, info, epoll_fd, stmt);
    convertResult(res, addInfo);
}
