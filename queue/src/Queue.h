#ifndef SRC_QUEUE_h_
#define SRC_QUEUE_h_
#include <string>


using namespace std;

class Queue{
    public:
        Queue(int);
        void enqueue(int);
        int dequeue();
        int isEmpty();
        int isFull();
        string itinerate();




    private:
        int*q;
        
        int max_size;
        int front;
        int back;
        int current_size;





};





#endif