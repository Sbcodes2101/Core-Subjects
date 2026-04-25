#include<iostream>
#include<string>

using namespace std;

class Customer{
    string name;
    int account_number;
    int balance;
    int *roi;
    public:
    // Default Constructor
    Customer(){
        cout<<"Hello constructor"<<endl;
        name="Sarthak";
        account_number = 123;
        balance = 42;
        roi = new int(100);
    }

    // Parameterized Constuctor
    // Customer(string name,int account_number,int balance){
    //     this->name = name;
    //     this->account_number=account_number;
    //     this->balance=balance;
    // }
    Customer(string name,int account_number){
        this->name = name;
        this->account_number=account_number;
    }

    // Inline Constructor
    inline Customer(string a,int b,int c): name(a),account_number(b),balance(c){}
    void display(){
        cout<<name<<" "<<account_number<<" "<<balance<<endl;
    }

    // Copy Constructor
    Customer(Customer &B)
    {
        name = B.name;
        account_number = B.account_number;
        balance = B.balance;
    }
};

int main(){
    Customer A1;
    Customer A2("Sarthak",143,42); //file open
    Customer A3("Samay",143);
    A1.display();
    A2.display();
    A3.display();
    Customer A4(A3);
    Customer A5;
    A5 = A3;
    A5.display();
}