#include "./Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(int size){
    this->max_size = size;
    this->s = new int[max_size];
}

int Stack::isEmpty(){
    if (this->cursor == -1){
        return 1;
    }
    else{
        return 0;
    }
};

int Stack::isFull(){
    if (this->cursor == this->max_size -1){
        return 1;
    }
    else{
        return 0;
    }
};

void Stack::push(int val){
    if(this->isFull()){
        cout <<"Stack is full"<<endl;
        return;
    }

    this->cursor ++;
    *(this->s + this->cursor) = val;
};

int Stack::pop(){
    if(this->isEmpty()){
        cout << "Stack is empty now" << endl;
        return this->max_size;
    }

    int temp;
    temp = *(this->s + this->cursor);
    this->cursor--;
    return temp;
}

int Stack::top(){
    if(this->isEmpty()){
        cout << "Stack is empty now" << endl;
        return this->max_size;
    }

    return *(this->s + this->cursor);
}
