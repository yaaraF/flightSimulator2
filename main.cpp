#include "Runner.cpp"

int main(int argc, char* argv[]) {

    Runner* runner=new Runner();
    runner->runProject(argv[1]);

    return 0;
}