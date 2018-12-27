//
// Created by yaara on 12/16/18.
//

#ifndef SIMULATORFLIGHT_MYSOCKET_H
#define SIMULATORFLIGHT_MYSOCKET_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string>

#include <sys/socket.h>
#include <map>
#include <netinet/in.h>
#include <vector>
#include "list"
#include <iostream>

using namespace std;


//bool inConnection = false;


struct exmp {
    int numID;
    string stringPort;
    map<string, float> *myMap;
};

class MySocket {

    bool isExit = false;
    map<string, string> varPlaces;
    map<string, float> dataFromSimolator;
    map<string, float> please;
    int simulatorId;
    int connectionId;


public:
    MySocket() {
        this->initializeTheMap();

    }

    static void *openFlightSocket(void *s);

    static void *getFlightSocket(int id, map<string, float> *data);

    static int DataReader(int serverId);

    static vector<float> split(string buffer);

    static void updateTheDateMap(string buffer, map<string, float> *data);

    map<string, float> *getDAtaFromServer();

    void conectToSimolator(vector<string> data);

    bool isVar(string s);

    float getValueOfVar(string s);

    void initializeTheMap();

    void addBind(string varName, string path);

    void addVar(string varNme, float value);

    void Write(const char *buffer);

    void print(string var);

    void setSimulatorID(int id);

    void exitSockets();

    ~MySocket();

};


#endif //SIMULATORFLIGHT_MYSOCKET_H