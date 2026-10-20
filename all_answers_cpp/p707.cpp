class MyLinkedList {
private:
    struct myListNode{
        int val;
        myListNode* next;

        myListNode(int val,myListNode* next):val(val),next(next){}
    };

    myListNode* dummy = new myListNode(0,nullptr);
    int cnt = 0;

public:
    MyLinkedList() {
        dummy->next = dummy;
    }
    
    int get(int index) {
        if(index>=cnt||index<0){
            return -1;
        }
        myListNode* cur = dummy->next;
        for(int i =0;i<index;++i){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(cnt,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index>cnt||index<0){
            return;
        }
        myListNode* cur = dummy;
        for(int i = 0;i<index;++i){
            cur = cur->next;
        }
        cur->next = new myListNode(val,cur->next);
        ++cnt;
    }
    
    void deleteAtIndex(int index) {
        if(index>=cnt||index<0){
            return;
        }
        myListNode* cur = dummy;
        for(int i = 0;i<index;++i){
            cur = cur->next;
        }
        myListNode* new_next = cur->next->next;
        delete cur->next;
        cur -> next = new_next;
        --cnt; 
    }
};
