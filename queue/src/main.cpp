#include <iostream>
#include <Queue.h>
#include <sstream>
#include <fstream>
#include <string>





int main(){
    ifstream ifstrm("./input_Queue.txt");
    ofstream ofstrm("./output_Queue_MS.txt");

    string isbuf;
    string osbuf;

    stringstream iss;
    stringstream oss;

    string action;
    int val;

    Queue q(10000);

    if (ifstrm.is_open()){
        while(getline(ifstrm, isbuf)){
            
            iss.clear();
            iss.str("");
            oss.clear();
            oss.str("");
           
            iss << isbuf;
            iss >> action >> val;
            cout << iss.str()  << endl;
            

            if (action == "ENQUEUE"){
                if (!q.isFull()){
                    q.enqueue(val);
                    oss << action <<"("<<val<<"): " <<q.itinerate();
                }else if(q.isFull()){
                    oss << action <<"("<<val<<"): " << "Queue Full";
                }
            }

            else if (action == "DEQUEUE"){
               
                if (q.isEmpty()){
                    oss << action <<": " <<"Queue EMPTY";
                }else{
                    q.dequeue();
                    oss << action <<": " << q.itinerate();
                }
            }
            osbuf = oss.str();
            ofstrm << osbuf << "\n";
            isbuf.clear();

        }
    }

    ifstrm.close();
    ofstrm.close();





    return 0;
}