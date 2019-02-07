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

IntNodePtr mergeLists(IntNodePtr head1, IntNodePtr head2){
    if(head1==NULL){
        return head2;
    }
    else if(head2==NULL){
        return head1;
    }

    else if(head1->getData()<=head2->getData()){
        //head1->link=merge(head1->link, head2);
        head1->setLink(mergeLists(head1->getLink(), head2));
        return head2;
        //head1->setLink(head2);
        //mergeLists(head2,(head2->getLink()));
    }

    else{
        //head2->link=merge(head1,head2->link);
        head2->setLink(mergeLists(head1, head2->getLink()));
        return head2;
        //head2->setLink(head1);
        //mergeLists(head1, head1->getLink());
    }
}

int main() {
    IntNodePtr head1;
    headInsert(head1, 5);
    insert(head1, 7);
    insert(head1->getLink(), 9);

    cout << head1->getData() << endl;
    cout << (head1->getLink())->getData() << endl;
    cout << ((head1->getLink())->getLink())->getData() << endl;
    cout << endl;

    IntNodePtr head2;
    headInsert(head2, 3);
    insert(head2,6);

    cout << head2->getData() << endl;
    cout << (head2->getLink())->getData() << endl;
    cout << endl;

    IntNodePtr merged=mergeLists(head1,head2);
    cout << merged->getData() << endl;
    cout << (merged->getLink())->getData() << endl;
    cout << ((merged->getLink())->getLink())->getData() << endl;
    cout << (((merged->getLink())->getLink())->getLink())->getData() <<endl;
    cout << ((((merged->getLink())->getLink())->getLink())->getLink())->getData() <<endl;


    return 0;
}