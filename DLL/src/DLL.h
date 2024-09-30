#ifndef SRC_DLL_H_
#define SRC_DLL_H_

#include <string>

class DLLNode{
    public:
        // constructor
        DLLNode(int, bool, bool);
        DLLNode(int);
        
        // setter
        void setNext(DLLNode*);
        void setPrev(DLLNode*);
        
        //getter
        DLLNode* getNext(void);
        DLLNode* getPrev(void);
        int getval(void);

    private:
        int val;
        bool is_head = false;
        bool is_tail = false;
        DLLNode* prev;
        DLLNode* next;

};


void combineDLLNodes(DLLNode*, DLLNode*);

class DLL{
    public:
        DLL();

        int insert(int);

        int find(int);

        int getlen(void);

        void initcursor(void);

        void toNext(void);

        void toPrev(void);

        int remove(int);

        void traverse(void);

        std::string str(void);


    private:
        int len = 0;
        DLLNode* curp;
        DLLNode* head_nodep;
        DLLNode* tail_nodep;

};


#endif