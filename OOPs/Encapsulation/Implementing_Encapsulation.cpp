// Bind Data and methods => class
// Only necessary Information
// Private ,Public ,Protected

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

    private:
    float *cgpa;
    string gf;
    // Default Constructor
    public:
    Student()
    {
        cout<<"Student Default constructor called"<<endl;
        cgpa = nullptr;
    }
    // Parameterized Constructor
    Student(int id,int age,string name,int nos,float cgpa,string gf){
        cout<<"Student Parameterised constructor is called"<<endl;
        this->id = id;
        this->age = age;
        this->name = name;
        this->nos = nos;
        this->cgpa = new float(cgpa);
    }

    // Copy constructor
    Student(const Student &srcobj){ //srcobj->A
        cout<<"Student Parameterised copy constructor is called"<<endl;
        this->id = srcobj.id;
        this->age = srcobj.age;
        this->name = srcobj.name;
        this->nos = srcobj.nos;
        this->cgpa =new float(*(srcobj.cgpa));
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
        delete cgpa;
        cout<<"Student destructor called"<<endl;
    }

    private:
    void gfchatting()
    {
        cout<<this->name<<"chatting with gf"<<endl;
    }
};

int main(){
    // Student *A = new Student(1,14,"Babban",7,9.8);
    // delete A;
    Student A(1, 12, "Sarthak",5 ,7.8, "idk");

    return 0;
}