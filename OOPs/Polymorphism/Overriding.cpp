#include<iostream>
#include<vector>
using namespace std;

class Animal{
    public:
    virtual void speak(){
        cout<<"Animal is speaking"<<endl;
    }
};

class Dog:public Animal{
    public:
    void speak(){
        cout<<"Dog is barking"<<endl;
    }

};


int main(){
    Animal *p;
    vector<Animal*> animals;
    animals.push_back(new Dog());
    animals.push_back(new Animal());
    animals.push_back(new Animal());
    animals.push_back(new Dog());

    for(int i=0;i<animals.size();i++){
        p=animals[i];
        p->speak();
    }
}

// why virtual function is even needed
