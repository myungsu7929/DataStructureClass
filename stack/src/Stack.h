#ifndef SRC_STACK_H_
#define SRC_STACK_H_




class Stack{
    public:
        Stack(int);
        void push(int);
        int pop();
        int top();
        int isEmpty();
        int isFull();
    
    private:
        int max_size;
        int* s;
        int cursor = -1;
};

#endif