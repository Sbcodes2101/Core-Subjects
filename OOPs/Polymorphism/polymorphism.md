Polymorphism – Key Notes
Definition
Polymorphism means "many forms" — the ability of one entity (function, method, object) to behave differently based on context.

Types of Polymorphism
1. Compile-time (Static) Polymorphism

Resolved at compile time
Achieved via function overloading and operator overloading
Example: same function name with different parameters

2. Runtime (Dynamic) Polymorphism

Resolved at runtime
Achieved via method overriding (inheritance + virtual functions)
Uses base class pointer/reference to call derived class methods


Key Concepts

Overloading – same name, different signature (compile-time)
Overriding – child class redefines parent's method (runtime)
Virtual functions (C++) / @Override (Java) enable dynamic dispatch
Abstract classes & interfaces define a common contract for subclasses


Real-world Analogy
A person can be a student, employee, and son at the same time — behaving differently in each role. That's polymorphism.

Benefits

Code reusability
Flexibility & extensibility
Cleaner, more maintainable code
Supports the Open/Closed Principle (open for extension, closed for modification)

Remember
FeatureOverloadingOverridingWhen resolvedCompile-timeRuntimeInheritance neededNoYesSignatureDifferentSame

