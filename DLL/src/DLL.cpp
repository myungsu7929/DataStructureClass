#include <iostream>
// #include <sstream>
#include <fstream>
#include <sstream>
#include <string>
#include "DLL.h"

using namespace std;


DLLNode::DLLNode(int val, bool is_head, bool is_tail){
    this->val = val;
    this->is_head = is_head;
    this->is_tail = is_tail;
}

DLLNode::DLLNode(int val){
    this->val = val;
}

void DLLNode::setNext(DLLNode* next){
    this->next = next;
}

void DLLNode::setPrev(DLLNode* prev){
    this->prev = prev;
}

DLLNode* DLLNode::getNext(void){
    return this->next;

}

DLLNode* DLLNode::getPrev(void){
    return this->prev;

}

int DLLNode::getval(void){
    return this->val;
}


void combineDLLNodes(DLLNode* node1p, DLLNode* node2p){
    node1p->setNext(node2p);
    node2p->setPrev(node1p);
}



DLL::DLL(){
    this->head_nodep = new DLLNode(0,true,false);
    this->tail_nodep = new DLLNode(0,false,true);
    
    this->head_nodep->setNext(this->tail_nodep);
    this->head_nodep->setPrev(nullptr);
    this->tail_nodep->setPrev(this->head_nodep);
    this->tail_nodep->setNext(nullptr);
    
    this->curp = this->head_nodep;
}

void DLL::toNext(void){
    if (this->curp != this->tail_nodep){
        this->curp = this->curp->getNext();
        
    }
}
void DLL::toPrev(void){
    if (this->curp != this->head_nodep){
        this->curp = this->curp->getPrev();
    }
}

int DLL::insert(int val){
    DLLNode* newnode = new DLLNode(val);
    DLLNode* tempnode = this->head_nodep->getNext(); //기존 헤드 노드 다음노드를 찾아서 잠시 저장
    combineDLLNodes(this->head_nodep, newnode);
    combineDLLNodes(newnode, tempnode);
    this->len++;
    return 0;
}

void DLL::initcursor(void){
    this->curp = this->head_nodep;
}

std::string DLL::str(void){
    std ::stringstream ss;
    this->initcursor();
    for(int i=0; i<this->len; i++){
        this->toNext();
        ss<< (this->curp->getval());
        if(i!=this->len -1){
            ss<< " <-> ";
        }
        
    }
    std::cout<<ss.str()<<std::endl;
    return ss.str();

}

int DLL::find(int search_val){

    int cnt = -1;
    this->initcursor();
    while(this->curp != this->tail_nodep){
        cnt ++;
        this->toNext();
        if (this->curp == this->tail_nodep){
            return -1;
        }
        else if(this->curp->getval()==search_val){
            return cnt;
        }
    }

    return -1; //실패시 -1을 반환
}

int DLL::remove(int target_idx){
    if (this->len == 0){
        return -1;
    }


    this->initcursor();
    for(int i=-1; i<target_idx; i++){
        cout << i << endl;
        this->toNext();
    }
    DLLNode* temp = this->curp;
    DLLNode* front = temp->getPrev();
    DLLNode* back = temp->getNext();

    combineDLLNodes(front ,back);
    this->len --;
    return 0;
}




int DLL::getlen(void){
    return this->len;
}

void DLL::traverse(void){
    this->initcursor();
  
    for(int i=0; i<this->len; i++){
        this->toNext();
        std::cout <<this->curp->getval() << std::endl;
    }
}


