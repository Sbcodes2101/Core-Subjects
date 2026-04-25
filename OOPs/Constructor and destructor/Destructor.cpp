#include<iostream>
using namespace std;

class Customer{
    string name;
    int *data;

    public:
    Customer(){
        name = "4";
    }
    Customer(string name){
        this->name = name;
        cout<<"Constructor of "<<name<<endl;
    }

    ~Customer(){
        cout<<"Destructor of "<<name<<" is called"<<endl;
    }
};

int main(){
    Customer A1("1"),A2("2"),A3("3");
    Customer *A4 = new Customer;
    delete A4;
}