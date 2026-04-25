# CONSTRUCTOR
- It is a special function invoked automatically at the time of object creation

-Name of constructor should be same as that off class

-It does not have any return value

-It is used to initialize the value

This pointer
It helps differentiate class data members from local variables with the same name.

-default constructor is used to initialize pointer 
Without this, the pointer would hold a garbage value, which can lead to undefined behavior if you accidentally dereference it.

// ============================================================
//  C++ Constructors - Notes & Examples
// ============================================================
 
// A constructor is a special member function that:
//  - Has the same name as the class
//  - Has no return type
//  - Is called automatically when an object is created
//  - Can be overloaded
 
// ============================================================
//  1. Default Constructor
// ============================================================
//  - Takes no parameters
//  - Initializes members with default values
//  - Compiler provides one automatically if no constructor is defined
//  - Once you define ANY constructor, compiler stops auto-generating this
 
#include <iostream>
#include <string>
using namespace std;
 
class Dog {
public:
    string name;
    int age;
 
    // Default constructor
    Dog() {
        name = "Unknown";
        age = 0;
    }
 
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
 
// Usage:
//   Dog d;        -> calls default constructor
//   d.display();  -> Name: Unknown, Age: 0
 
 
// ============================================================
//  2. Parameterized Constructor
// ============================================================
//  - Takes one or more arguments
//  - Lets you set specific values at the time of object creation
//  - Multiple parameterized constructors can coexist (overloading)
 
class Cat {
public:
    string name;
    int age;
 
    // Parameterized constructor
    Cat(string n, int a) {
        name = n;
        age = a;
    }
 
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
 
// Usage:
//   Cat c("Whiskers", 3);  -> calls parameterized constructor
//   c.display();           -> Name: Whiskers, Age: 3
 
 
// ============================================================
//  3. Copy Constructor
// ============================================================
//  - Creates a new object as a copy of an existing object
//  - Takes a const reference to an object of the same class
//  - Compiler provides a default one (shallow copy)
//  - Define your own when you have dynamic memory (deep copy needed)
 
class Bird {
public:
    string name;
    int age;
 
    // Parameterized constructor
    Bird(string n, int a) {
        name = n;
        age = a;
    }
 
    // Copy constructor
    Bird(const Bird& obj) {
        name = obj.name;
        age = obj.age;
    }
 
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
 
// Usage:
//   Bird b1("Parrot", 5);  -> parameterized constructor
//   Bird b2(b1);           -> copy constructor
//   b2.display();          -> Name: Parrot, Age: 5
 
 
// ============================================================
//  main() - Running all examples
// ============================================================
 
int main() {
 
    // 1. Default Constructor
    cout << "-- Default Constructor --" << endl;
    Dog d;
    d.display();
 
    // 2. Parameterized Constructor
    cout << "\n-- Parameterized Constructor --" << endl;
    Cat c("Whiskers", 3);
    c.display();
 
    // 3. Copy Constructor
    cout << "\n-- Copy Constructor --" << endl;
    Bird b1("Parrot", 5);
    Bird b2(b1);
    b1.display();
    b2.display();
 
    return 0;
}
 