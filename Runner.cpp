
#include <iostream>
#include <fstream>

#include "OrganizedData.h"
#include "CreateCommandMap.h"

using namespace std;

class Runner{
public:
    void runProject(string fileName) {
        CreateCommandMap *mapOfComaand = new CreateCommandMap();
        map<string,Expression*> commands;
        commands = mapOfComaand->getMapCommand();
        OrganizedData *organizedData = new OrganizedData(commands);
        ifstream file;
        file.open(fileName,ifstream::in| ifstream::app);
        if(!file){
            throw "Failed opening file";
        }
        string buffer;
        while(getline(file,buffer)){
            organizedData->lexer(buffer);
        }
        organizedData->parser();
    }
};
