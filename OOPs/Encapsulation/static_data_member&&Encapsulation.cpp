// They are attributes of classes or class member

#include<iostream>
using namespace std;

class Customer
{
    string name;
    int account_number, balance;
    static int total_Customer;
    static int total_balance;
    int age;
    // this total customer is private and now i want to access it in th main function directly

    // therefore we create static member functon to access then diectly but static member function now cannot access other data members

    public:
    
    Customer(string name, int account_number, int balanc,int age){
        this->name = name;
        this->account_number=account_number;
        this->balance=balance;
        total_Customer++;
        total_balance += balance;
        this->age = age;
    }

    void display(){
        cout<<name<<" "<<account_number<<" "<<balance<<" "<<total_Customer<<endl;
    }

    static void accessStatic()
    {
        cout<<"Total number of Customers:"<<total_Customer<<endl;
        cout<<"Total balance:"<<total_balance<<endl;
    }

    void display_total(){
        cout<<total_Customer<<endl;
    }

    void deposit(int amount){
        if(amount>0){
            balance += amount;
            total_balance += amount;
        }
    }

    void withdraw(int amount){
        if(amount<=balance && amount>0){
            balance -= amount;
            total_balance -= amount;
        }
    }

    void updateAge(int age){
        if(age>0 && age<100){
            this->age = age;
        }
    }
};

int Customer::total_Customer = 0;
int Customer::total_balance = 0;

int main()
{
    Customer A1("Rohit",1,1000,25);
    Customer A2("Mohit",2,1800,26);
    Customer A3("Sujal",2,3600,26);
    A1.deposit(800);
    A2.withdraw(500);
    Customer::accessStatic();
}

