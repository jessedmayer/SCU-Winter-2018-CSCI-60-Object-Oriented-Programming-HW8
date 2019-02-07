#include <iostream>
using namespace std;

class IntNode{
public:
    IntNode(){}
    IntNode(int theData, IntNode* theLink) : data(theData), link(theLink){}
    IntNode* getLink() const {return link;}
    int getData() const {return data;}
    void setData(int theData){data = theData;}
    void setLink(IntNode* pointer){link = pointer;}

private:
    int data;
    IntNode *link;
};
typedef IntNode* IntNodePtr;

void headInsert(IntNodePtr& head, int theData){
    head = new IntNode(theData, head);
}

void insert(IntNodePtr afterMe, int theData){
    afterMe->setLink(new IntNode(theData, afterMe->getLink()));
}

void ReverseList(IntNodePtr &head){
    IntNodePtr prev = NULL;
    IntNodePtr current = head;
    IntNodePtr next = NULL;
    while (current != NULL){
        next = current->getLink();
        current->setLink(prev);
        prev=current;
        current=next;
    }
    head = prev;
}

int main() {
    IntNodePtr head;
    headInsert(head, 5);
    insert(head, 7);
    insert(head->getLink(),9);

    cout << head->getData() <<endl;
    cout << (head->getLink())->getData() <<endl;
    cout << ((head->getLink())->getLink())->getData() <<endl;

    ReverseList(head);
    cout << head->getData() <<endl;
    cout << (head->getLink())->getData() <<endl;
    cout << ((head->getLink())->getLink())->getData() <<endl;




    return 0;
}