#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "./Stack.h"

using namespace std;
int main(){
    ifstream inputstream("./input_Stack.txt");
    ofstream outputstream("./output_Stack_MS.txt");

    string sibuf;
    string sobuf;
    stringstream iss;
    stringstream oss;


    string command;
    int key_value;

    int isempty;
    int isfull;


    Stack stck(100000);

    if(inputstream.is_open()){
        while(getline(inputstream, sibuf)){
            iss.str("");
            
            
            iss << sibuf;
            
            iss >> command >> key_value;
           
            oss.str("");
            sobuf.clear();
            if (command == "PUSH"){
                stck.push(key_value);
                oss << "PUSH(" << to_string(key_value)<<"): " <<stck.itinerate();
                
            }
            else if (command == "POP"){
                if (stck.isEmpty()){
                    oss << "POP: Stack EMPTY";
                }
                    
                else{stck.pop();
                    oss << "POP: " << stck.itinerate();
                }
            }

            sobuf.clear();
            sobuf = oss.str();
            outputstream << sobuf << endl; 

        
        }
    }
    inputstream.close();
    outputstream.close();

    return 0;
}