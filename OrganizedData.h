
#ifndef SIMULATORFLIGHT_ORGANIZEDDATA_H
#define SIMULATORFLIGHT_ORGANIZEDDATA_H

#include <list>
#include <vector>
#include <map>
#include "Expression.h"


using namespace std;

class OrganizedData {

    vector<vector<string>> info;
    map<string, Expression *> commands;
    int counterInCondition = 0;

public:
    OrganizedData(const map<string, Expression *> &commands);

    void lexer(string s);

    vector<string> findParameters(vector<string> line);

    bool isOperator(char s);

    void addParameter(int j, int i, vector<string> &params, vector<string> line);

    void parser();

    void pop();

    void add(string s, Expression *exe);

    map<string, Expression *> getMap();

    void setCounterCondition() {
        this->counterInCondition--;
    }
};

#endif //SIMULATORFLIGHT_ORGANIZEDDATA_H