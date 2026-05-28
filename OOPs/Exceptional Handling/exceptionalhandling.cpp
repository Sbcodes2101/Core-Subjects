#include<iostream>
using namespace std;

class Customer
{
    string name;
    int balance, account_number;

    public:

    Customer(string name, int balance, int account_number){
        this->name = name;
        this->balance = balance;
        this->account_number = account_number;
    };

    // deposit
    void deposit(int amount){
        if(amount>0){
            balance += amount;
            cout<<amount<<"Amount is credited successfully\n";
        }
        else{
            throw "amount should be greater than or equal to 0";
        }
    }

    // withdraw

    void withdraw(int amount){
        if(amount>0 && amount<=balance){
            balance -= amount;
            cout<<amount<<"This amount is debited successfully";
        }
        else if(amount<0)
        {
            throw "amount should be greater than 0\n";
        }
        else{
            throw "Not enough balance";
        }
    }
};

int main(){
    Customer C1("Sarthak",5000, 10);
    try{
    C1.deposit(100);
    C1.withdraw(6000);
    }
    catch(const char *e){
        cout<<"Exception Occured: "<<e<<endl;
    }
}