#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>

#include "DLL.h"

// #include <string>

using namespace std;

int main(){
    ifstream inputfilestream ("./input_DLL.txt");
    ofstream outpufilestream("./output_DLL_MS.txt");
    
    stringstream ss;
    stringstream result;

    
    string line;
    string action;
    int value;
    int function_result;

    string message;
    
    string ment;

    DLL dll = DLL();
    
    if(inputfilestream.is_open()){
        while(getline(inputfilestream, line)){
            ss.clear();
            result.clear();
            ss << line;
            ss >> action >> value;
        
         
            if(action=="INSERT"){
                if (dll.find(value)==-1){
                    dll.insert(value);
                    message = dll.str();
                }
                else{
                    message = "Duplicate Key";
                }
                
            }
            if(action=="FIND"){
                int find_result = dll.find(value);
                if(find_result==-1){
                    continue;
                } 
                else{
                    message = "Success";
                }
 
            }
            if(action=="REMOVE"){
                
                int find_result = dll.find(value);
                if(find_result!=-1){
                    dll.remove(find_result);
                    message = dll.str();
                }
                else{
                    message = "No Entry Found";
                }
                
            }

            outpufilestream <<action<<'('<<value<<"): " << message << endl;
        }
    }

  
    inputfilestream.close();
    outpufilestream.close();

    cout << dll.str() << endl;





    return 0;
}





