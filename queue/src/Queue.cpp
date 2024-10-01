#include "Queue.h"
#include <string>
#include <sstream>

Queue::Queue(int size){
    this->max_size = size;
    this->q = new int[max_size];
    this->current_size = 0;
    this->front = 0;
    this->back = 0;
}

void Queue::enqueue(int val){
    *(this->q + this->back) = val;
    this->back ++;
    this->current_size ++;
}

int Queue::dequeue(){
    int temp;
    temp = *(this->q + this->front);
    this->front++;
    this->current_size --;
    return temp;
}

int Queue::isEmpty(){
    if (this->back == this->front){
        return 1;
    }
    else{
        return 0;
    }
}

int Queue::isFull(){
    if ((this->back%this->max_size)==(this->front%this->max_size) and this->front != this->back){
        return 1;
    }
    else{
        return 0;
    }
}

string Queue::itinerate(){
    stringstream result;
    int ibuf;
    for(int i=0; i<current_size; i++){
        ibuf = *(this->q + this->front + i);
        result << to_string(ibuf) << " ";
    }
    return result.str();
    
}

