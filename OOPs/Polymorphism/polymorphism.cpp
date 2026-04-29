#include<iostream>
using namespace std;

// Function overloading
class Area
{
    public:
    double calculateArea(int r){
        return 3.14*r*r;
    }

    int calculateArea(int l,int b){
        return l*b;
    }
};

// operator overloading

class Complex{
    int real,img;
    public:
    Complex(int real,int img){
        this->real = real;
        this->img = img;
    }
    Complex(){}

    void display(){
        cout<<real<<"+i"<<img;
    }

    Complex operator +(Complex &C){
        Complex ans;
        ans.real = real+C.real;
        ans.img = img+C.img;
        return ans;
    }

};

class Box {
public:
    int length, width, height;

    Box(int l, int w, int h) : length(l), width(w), height(h) {}

    // Overload +
    Box operator+(const Box& other) {
        return Box(length + other.length,
                   width + other.width,
                   height + other.height);
    }

    // Overload ==
    bool operator==(const Box& other) {
        return length == other.length &&
               width  == other.width  &&
               height == other.height;
    }

    void display() {
        cout << "Box(" << length << ", " << width << ", " << height << ")\n";
    }
};

int main()
{
    Area A1,A2;
    cout<<A1.calculateArea(4)<<endl;
    cout<<A2.calculateArea(3,4)<<endl;

    Complex C1(3,2);
    Complex C2(4,6);

    Complex C3 = C1+C2; //C1.fun(C2)
    C3.display();

    Box b1(1, 2, 3);
    Box b2(4, 5, 6);
    Box b3 = b1 + b2;
}