Inheritance lets a class (child/derived) acquire properties and methods from another class (parent/base). It models "is-a" relationships — e.g., a Dog is an Animal.
Key concepts:

public inheritance — the most common; public members stay public
protected members — accessible in the class and its children, but not outside
private members — not directly accessible in derived classes
override keyword — explicitly marks that a virtual function is being overridden
virtual + override — enables polymorphism (calling the right method at runtime)