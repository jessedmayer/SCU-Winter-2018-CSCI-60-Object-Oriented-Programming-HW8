#include <iostream>
#include <cmath>
using namespace std;

int power(int a, int b)
{
    int c=a;
    for (int n=b; n>1; n--) c*=a;
    return c;
}

class Polynomial{
public:
    Polynomial(){}
    Polynomial(Polynomial* &P);
    Polynomial(int con) : coeff(con), pow(1){}
    Polynomial(int value, int exp) : coeff(value), pow(exp){}
    Polynomial* getLink(){return link;}
    int getCoefficient(){return coeff;}
    int getExponential(){ return pow;}
    void setData(int value, int exp){coeff=value, pow=exp;}
    void setLink(Polynomial* pointer){link = pointer;}
    void outputPoly(Polynomial* &P);
    Polynomial* inputPoly(Polynomial* &P);
    int evaluate(int x);
    ~Polynomial();
    Polynomial *link;
    int coeff;
    int pow;

};
typedef Polynomial* PolyPtr;

void Polynomial::outputPoly(Polynomial* &P) {
    PolyPtr temp = P;
    while (temp != NULL){
        if(temp->getCoefficient()!=0) {
            cout << temp->getCoefficient() << "X^" << temp->getExponential() << " + ";
        }
        temp = temp->link;
        //outputPoly(temp->getLink());
    }
}

Polynomial* Polynomial::inputPoly(Polynomial* &P) {
    int a,e;
    PolyPtr temp = P;
    cout << "Enter Polynomial" <<endl;
    cin >> a;
    cin >> e;
    if(e>1) {
        temp->coeff = a;
        temp->pow = e;
        temp->link = inputPoly(P->link);
    }
    else if(e==1){
        temp->coeff = a;
        temp->pow = e;
        temp->link = NULL;
    }
    if(e==1){
        return NULL;
    }
    return temp;
}

Polynomial::Polynomial(Polynomial* &B) {
    PolyPtr temp1 = link;
    PolyPtr temp2 = &*B;
    coeff = B->coeff;
    pow = B->pow;
    while(temp1 != NULL){
        temp1->coeff = temp2->coeff;
        temp1->pow = temp2->pow;
        temp1= temp1->link;
        temp2 = temp2->link;

    }
}

Polynomial::~Polynomial() {
    PolyPtr current = link;
    while (current != NULL) {
        PolyPtr next = current->link;
        delete current;
        current = next;
    }
}

Polynomial* operator + (Polynomial &A, Polynomial &B) {
    PolyPtr P = &A;
    PolyPtr temp = P;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = &B;
    return P;
}

Polynomial* operator - (Polynomial &A, Polynomial &B) {
    PolyPtr P = &A;
    PolyPtr temp = P;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = &B;
    while(temp->link !=NULL){
        temp->coeff = -(temp->coeff);
        temp = temp->link;
    }
    return P;
}

Polynomial* operator *(Polynomial &A, Polynomial &B) {
    PolyPtr temp1 = &A;
    PolyPtr temp2 = &B;
    while (temp1->link != NULL){
        while (temp2->link != NULL){
            if(temp1->pow == temp2->pow){
                temp1->coeff = (temp1->coeff) * (temp2->coeff);
            }
            temp2 = temp2->link;
        }
        temp1 = temp1->link;
    }
    return temp1;
}

int Polynomial::evaluate(int x) {
    int sum = power(coeff, pow);
    PolyPtr temp = link;
    while (temp != NULL){
        sum += power(temp->coeff, temp->pow);
        temp = temp->link;
    }
    return sum;
}

int main(){

    Polynomial p;
    PolyPtr ptr = &p;

    ptr = p.inputPoly(ptr);
    cout << ptr->coeff <<endl;
    cout << ptr->pow <<endl;
    cout << (ptr->link)->coeff <<endl;
    cout << (ptr->link)->pow <<endl;
    p.outputPoly(ptr);
    cout << p.evaluate(2) <<endl;


    //cout << power (2,3) <<endl;               //test of exponential function power


    return 0;
}
