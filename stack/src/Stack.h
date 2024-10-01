#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <string>

using namespace std;
class Stack{
    public:
        Stack(int);
        void push(int);
        int pop();
        int top();
        int isEmpty();
        int isFull();
        string itinerate();
    
    private:
        int max_size;
        int* s;
        int cursor = -1;
};

#endif