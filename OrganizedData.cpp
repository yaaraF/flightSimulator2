
#include <iostream>
#include "OrganizedData.h"


void OrganizedData::lexer(string s) {
    vector<string> splitS;
    string temp;
    int counterfloatComma = 0;
    for (int i = 0; i < s.length(); i++) {
        if (this->counterInCondition > 0) {
            if (s.find("{") != string::npos) {
                this->counterInCondition++;
            }
            if (s.find("}") != string::npos) {
                this->counterInCondition--;
            }
            splitS.push_back(s);

            this->info[this->info.size() - 1].insert(this->info[this->info.size() - 1].end(), splitS.begin(),
                                                     splitS.end());
            return;
        }
        if (s[i] == '"') {
            if (counterfloatComma == 0) {
                counterfloatComma++;
            } else {
                counterfloatComma--;
            }
        }
        if ((s[i] == '{' && this->counterInCondition == 0) || (s[i] == '}' && this->counterInCondition == 1)) {
            if (temp != "") {
                splitS.push_back(temp);
            }
            string v = "";
            v += s[i];
            splitS.push_back(v);
            temp = "";
            if (s[i] == '{') {
                this->counterInCondition++;
            }
            if (s[i] == '}') {
                this->counterInCondition--;
            }
            continue;
        }
        if (s[i] == '{') {
            this->counterInCondition++;
        }
        if (s[i] == '}') {
            this->counterInCondition--;
        }
        if ((s[i] == '+' || s[i] == '-' || s[i] == '=' || s[i] == '/' || s[i] == '*'
             || s[i] == '<' || s[i] == '>' || s[i] == '!') && (counterfloatComma != 1)) {
            if (temp != "") {
                splitS.push_back(temp);
            }
            string v = "";
            v += s[i];
            // check if its =< / >= / ==
            if (i < s.length() - 1 && s[i] == '>') {
                if (s[i + 1] == '=') {
                    i++;
                    v += s[i];
                }
            }
            if (i < s.length() - 1 && s[i] == '<') {
                if (s[i + 1] == '=') {
                    i++;
                    v += s[i];
                }
            }
            if (i < s.length() - 1 && s[i] == '=') {
                if (s[i + 1] == '=') {
                    i++;
                    v += s[i];
                }
            }
            if (i < s.length() - 1 && s[i] == '!') {
                if (s[i + 1] == '=') {
                    i++;
                    v += s[i];
                }
            }
            splitS.push_back(v);
            temp = "";
            continue;

        }
        if (s[i] != ' ' && s[i] != ',' && i < s.length() - 1 && s[i] != '(' && s[i] != ')') {
            temp += s[i];
            continue;

        }
        if (s[i] == ' ' || s[i] == ',' || i == s.length() - 1 || s[i] == '(' || s[i] == ')') {
            if (i == s.length() - 1 && s[i] != ' ' && s[i] != ',' && s[i] != '(' && s[i] != ')') {
                temp += s[i];
            }
            //if(s[i]==')')
            if (temp == "") {
                continue;
            }
            splitS.push_back(temp);
            temp = "";
        }


    }
    splitS = findParameters(splitS);
    this->info.push_back(splitS);
}


bool OrganizedData::isOperator(char s) {
    if ((s == '+') || (s == '-') || (s == '/') || (s == '*')) {
        return true;
    }
    return false;
}

/*
 * add a parameter to the list of parameters from string line from index j to index i
 */
void OrganizedData::addParameter(int j, int i, vector<string> &params, vector<string> line) {
    string s = "";
    if (line[j] == "-") {
        s += "0";
    }

    for (j; j <= i; j++) {
        s += line[j];
    }
    params.push_back(s);
}

vector<string> OrganizedData::findParameters(vector<string> line) {
    int i = 0;
    int startIndexParameter = 0;
    int bracketsCounter = 0;
    bool previousIsNumber = false;
    bool previousIsCloseingBrackets = false;
    vector<string> params;

    while (i < line.size()) {
        if (line[i] == "(") {
            bracketsCounter++;
            previousIsNumber = false;
            previousIsCloseingBrackets = false;
        } else if (line[i] == ")") {
            bracketsCounter--;
            previousIsCloseingBrackets = true;
            previousIsNumber = false;
        } else if (line[i] == ",") {
            // i - 1: for ignore the comma
            addParameter(startIndexParameter, i - 1, params, line);
            startIndexParameter = i + 1;
            previousIsNumber = false;
            previousIsCloseingBrackets = false;
        } else if (line[i] == "=") {
            addParameter(startIndexParameter, i - 1, params, line);
            //enter = as parameter
            addParameter(i, i, params, line);
            startIndexParameter = i + 1;
            previousIsNumber = false;
            previousIsCloseingBrackets = false;
        } else {
            //check if the string is operator or num
            if ((previousIsNumber && !isOperator(line[i][0]))
                || (previousIsCloseingBrackets && !isOperator(line[i][0]) && bracketsCounter == 0)) {
                if (startIndexParameter == i) {
                    addParameter(startIndexParameter, i, params, line);
                } else {
                    addParameter(startIndexParameter, i - 1, params, line);
                }

                startIndexParameter = i;
            }
            previousIsCloseingBrackets = false;
            previousIsNumber = true;
            if (isOperator(line[i][0])) {
                previousIsNumber = false;
            }
        }
        i++;

    }
    addParameter(startIndexParameter, line.size() - 1, params, line);
    return params;
}

void OrganizedData::parser() {
    int i = 0;
    vector<string> parm;
    while (i < this->info.size()) {
        for (int j = 1; j < this->info[i].size(); j++) {
            parm.push_back(this->info[i][j]);
        }
        if (this->commands.find(this->info[i][0]) == this->commands.end()) {
            this->commands["var"]->setParm(this->info[i]);
            this->commands["var"]->calculate();
        }
        if (this->commands.find(this->info[i][0]) != this->commands.end()) {
            this->commands[this->info[i][0]]->setParm(parm);
            this->commands[this->info[i][0]]->calculate();

        }
        while (!parm.empty()) {
            parm.pop_back();
        }
        i++;
    }
}

OrganizedData::OrganizedData(const map<string, Expression *> &commands) : commands(commands) {}

void OrganizedData::pop() {
    this->info.pop_back();
}

void OrganizedData::add(string s, Expression *exe) {
    this->commands[s] = exe;
}

map<string, Expression *> OrganizedData::getMap() {
    return this->commands;
}