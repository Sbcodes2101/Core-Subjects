#include<iostream>
#include<string>
using namespace std;
class Student
{
    public:
    // Attributes
    int id;
    int age;
    string name;
    int nos;
    int *cgpa;
    // Default Constructor
    Student()
    {
        cout<<"Student Default constructor called"<<endl;
    }
    // Parameterized Constructor
    Student(int id,int age,string name,int nos,float cgpa){
        cout<<"Student Parameterised constructor is called"<<endl;
        this->id = id;
        this->age = age;
        this->name = name;
        this->nos = nos;
        this->cgpa = new int(cgpa);
    }

    // Copy constructor
    Student(const Student &srcobj){ //srcobj->A
        cout<<"Student Parameterised copy constructor is called"<<endl;
        this->id = srcobj.id;
        this->age = srcobj.age;
        this->name = srcobj.name;
        this->nos = srcobj.nos;
    }

    // Behavior/Methods/Functions
    void study()
    {
        cout<<"studying"<<endl;
    }

    void bunk(){
        cout<<"Bunking"<<endl;
    }

    void sleep()
    {
        cout<<"sleeping"<<endl;
    }

    ~Student(){
        cout<<"Student destructor called"<<endl;
    }
};

int main(){
    // Student A(1,15,"Sarthak",6);
    // Student C = A;

    // cout<<C.name<<" "<<A.name << endl;

    // Dynamic allocation
    Student *A = new Student(1,14,"Babban",7,9.8);

    return 0;
}