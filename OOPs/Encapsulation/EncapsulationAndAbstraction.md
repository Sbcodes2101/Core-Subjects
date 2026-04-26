Encapsulation
Encapsulation is one of the four core principles of Object-Oriented Programming (OOP). It means bundling data (variables) and methods (functions) that operate on that data into a single unit (class), and restricting direct access to some of the object's components.

Core Idea

"Hide the internal details, expose only what's necessary."

Think of a capsule (medicine) — you use it without knowing what's inside. Similarly, a class hides its internal workings and exposes only a clean interface.

Key Concepts
1. Access Modifiers control visibility of class members:
ModifierAccessible FrompublicEverywhereprivateWithin the same class onlyprotectedSame class + subclassesdefaultSame package (Java)
2. Getters & Setters — the standard way to access/modify private data:

3. Data Hiding — internal state can't be changed directly from outside:
javas.age = -5;       // ❌ Not allowed (private)
s.setAge(-5);     // ✅ Allowed — but you can add validation inside setter

Why Use Encapsulation?

Security — prevents unauthorized access/modification of data
Control — you can validate data before setting it (e.g., reject negative age)
Flexibility — internal implementation can change without breaking outside code
Maintainability — easier to debug and modify
Reusability — well-encapsulated classes are plug-and-play


Real-World Analogy
Real WorldOOPATM machineClassYour PIN & balancePrivate dataWithdraw/Deposit buttonsPublic methodsInternal bank processingHidden implementation
You interact with the ATM through buttons — you never touch the internal wiring.


Quick Summary
PointDetailDefinitionBinding data + methods + restricting accessAchieved viaAccess modifiers + getters/settersMain benefitData protection & controlled accessOpposite ofExposing everything as public


# Static Data Member
Static Data Members
📌 Definition

A static data member is shared among all objects of a class.

✅ Key Points
Only one copy exists (not per object).
Stored in global/static memory, not inside objects.
Must be defined outside the class.

# Static Member Function

Definition

A static function belongs to the class, not objects.

✅ Key Points
Can be called using class name
Cannot access non-static members directly
Does NOT use this pointer

# Const Variables
Value cannot be changed after initialization

const int x = 10;
x = 20; // ❌ ERROR

# Const with Pointers

const int* p = &x;
*p = 20; // ❌ cannot change value
p = &y;  // ✅ can change pointer

# Abstraction

Display only essential information and hiding the details



