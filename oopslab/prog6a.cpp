#include <iostream>

// 1. BASE CLASSES

class A {
public:
    void displayA() {
        std::cout << "Class A method" << std::endl;
    }
};

class B {
public:
    void displayB() {
        std::cout << "Class B method" << std::endl;
    }
};


// 2. SINGLE INHERITANCE
// B inherits from A

class SingleDerived : public A {
public:
    void displaySingle() {
        std::cout << "Single Inheritance (Derived from A)" << std::endl;
    }
};

// 3. MULTILEVEL INHERITANCE
// C inherits from B, which inherits from A
class MultilevelBase : public A {};
class MultilevelMiddle : public MultilevelBase {};
class MultilevelDerived : public MultilevelMiddle {
public:
    void displayMultilevel() {
        std::cout << "Multilevel Inheritance (A -> B -> C structure)" << std::endl;
    }
};

// 4. HIERARCHICAL INHERITANCE
// B and C both inherit from A

class HierarchicalDerived1 : public A {};
class HierarchicalDerived2 : public A {};


// 5. MULTIPLE INHERITANCE
// C inherits from both A and B

class MultipleDerived : public A, public B {
public:
    void displayMultiple() {
        std::cout << "Multiple Inheritance (Derived from A and B)" << std::endl;
    }
};


// 6. HYBRID INHERITANCE
// Class C inherits from A and B, where A is a base class

class HybridDerived : public SingleDerived, public B {
public:
    void displayHybrid() {
        std::cout << "Hybrid Inheritance (Combines Single and Multiple)" << std::endl;
    }
};


// MAIN FUNCTION

int main() {
    std::cout << "--- 1. Single Inheritance ---" << std::endl;
    SingleDerived obj1;
    obj1.displayA();      // From Class A
    obj1.displaySingle();

    std::cout << "\n--- 2. Multilevel Inheritance ---" << std::endl;
    MultilevelDerived obj2;
    obj2.displayA();      // From Grandparent A
    obj2.displayMultilevel();

    std::cout << "\n--- 3. Hierarchical Inheritance ---" << std::endl;
    HierarchicalDerived1 obj3a;
    HierarchicalDerived2 obj3b;
    obj3a.displayA();     // First child from A
    obj3b.displayA();     // Second child from A

    std::cout << "\n--- 4. Multiple Inheritance ---" << std::endl;
    MultipleDerived obj4;
    obj4.displayA();      // From Class A
    obj4.displayB();      // From Class B
    obj4.displayMultiple();

    std::cout << "\n--- 5. Hybrid Inheritance ---" << std::endl;
    HybridDerived obj5;
    obj5.displayA();      // From A (via SingleDerived)
    obj5.displayB();      // From Class B
    obj5.displayHybrid();

    return 0;
}