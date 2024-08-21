## Intro


The purpose of this course is learn how to design algorithms that are capable of handling large amount of data in a reasonable amount of time efficiently.

The selection problem: suppose we have a group of N numbers and you want to find the kth largest number

The word puzzle game is a word puzzle in which a matrix of letters and a list of words are provided and you’re then asked to find where each word begins and where it ends 

Writing a program that works is not enough, yet it’s necessary to optimize the time taken to accomplish a given task

We’ll learn how to estimate the running time of a program for large inputs and how to compare the running time of two programs without actually coding them

* Throughout this course, we will see how to estimate the running time of a program
for large inputs and, more important, how to compare the running times of two programs
without actually coding them.
* We will see techniques for drastically improving the speed of a program and for determining program bottlenecks. These techniques will enable us to **find the section of the code on which to concentrate our optimization efforts**.

## Mathematics Review:

---

### Exponents:

X^a . X^b = X^(a+b)

X^a / X^b = X^(a-b)

(X^a)^b = X^ ab

X^n + X^n = 2X^n ≠ X^2n

2^n + 2^n = 2^n+1

$$
\sqrt {2\pi n} \space . \space  {(\dfrac {n}{e})} ^{n} \space \le n! \space \le \space \sqrt{2\pi n} \space . \space (\dfrac {n}{e})^{n+\dfrac {1}{12n}}
$$

### Logarithms:

In computer science, all logarithms are to the base 2 unless specified otherwise. i.e.           log <=> log2

Definition:

$$
X^A = B      <=>       logx (B) = A
$$

Theorem:

$$
logA (B) = logC(B)/ logC(A)
$$

with A, B, C >0 and A ≠ 1

Theorem:

$$
log AB = log A + logB
$$

Other properties:

$$
log (A/B) = log(A) - log (B)
$$

$$
log(A^B) = B. log(A)
$$

$$
log (X) <X   
$$

- log 1 = 0
- log 2 = 1
- log 1024 = 10

### Series:

Property: this property is true for 0 < A < 1

$$
[A^0 + A^1+...+A^n = (A^n.A -1)/(A-1)] <= 1/(1-A)
$$

And as n tends to ♾️ the sum approaches 1/(1-A)

We can derive the last formula for A^0+ A^1 + … up to infinity for 0 < A < 1. Let S be the sum where S= A^0+ A^1 + … Then

$$
 S= A^0+ A^1 +A^2 … 
$$

⇒

$$
AS= A^1 + A^2 + A^3 … 
$$

If we substract the two equations (which is allowed only for convergent series) then, we obtain

$$
S-AS=1 => S=1/(1-A)
$$

In the same way we can caluclulate  $\displaystyle\sum_{i=1}^n$i/2i

$$
S=\dfrac{1}{2}+\dfrac{2}{2^2}+\dfrac{3}{2^3}+\dfrac{4}{2^4}+...
$$

By multiplying by 2, we obtain:

$$
2S =1+ \dfrac{2}{2}+\dfrac{3}{2^2}+\dfrac{4}{2^3}+\dfrac{5}{2^4}
$$

By performing 2S-S, we obtain:

$S=1+\dfrac{1}{2}+\dfrac{1}{2^2}+\dfrac{1}{2^3}+\dfrac{1}{2^4}+...$

Thus , S=2

Arithmetic series:

$$
\displaystyle\sum_{i=1}^ni = [n(n+1)/2] \approx \dfrac{n^2}{2}
$$

Other formulas:

$$
\displaystyle\sum_{i=1}^ni^2 =  \dfrac{n(n+1)(2n+1)}{6} \approx \dfrac{n^3}{3}
$$

$$
\displaystyle\sum_{i=1}^ni^k \approx \dfrac{n^{k+1}}{|k+1|}
$$

with k ≠ -1

when k=1, the latter is not valid, then we will need the following formula 

The numbers Hn are known as the harmonic numbers and the sum is known as the harmonic sum are defined by :

$$
Hn = \displaystyle\sum_{i=1}^n \dfrac{1}{i} \approx ln n = log e(n)
$$

### Modular arithmetic:

We say that A is congruent to B modulo N, written A ≡ B (mod N), if N divides A - B. This means that the remainder is the same when either A or B is divided by N.

Properties:

$A ≡ B (mod N)  ⇒ A+C ≡ B+C (mod N) for all C\in Z$ 

$A ≡ B (mod N)  ⇒ AD ≡ BD (mod N) for all D\in Z$ 

When N is a prime number, There are three important theorems:

$$
ab ≡ 0 \space(mod\space N) \iff a≡0\space(mod\space N)\space or\space b ≡0\space(mod \space N) 
$$

$$
the \space equation \space ax \space ≡1\space (mod\space N)\space has\space a\space unique \space solution \space (mod \space N )     \space for \space all \space 0<a<N.This \space solution, \space 0<x<N, is \space the \space the \space multiplicative \space inverse
$$

$$
The \space equation \space x² ≡ a \space (mod\space N)\space has \space either \space two \space solutions \space (mod \space N) \space for  \space all \space 0<a<N, or \space it \space has \space no \space solutions
$$

### The P Word:

The two most commonly used ways of proving statements in data-structure analysis are:

- Proof by induction (either regular induction or strong induction)
- Proof by contradiction

The best way of proving that a theorem is false is by exhibiting a counter example 

# A brief introduction to recursion:

---

- A function that is defined in terms of itself is called **recursive**
- C++ allows functions to be recursive but NOT ALL mathematically recursive functions are efficiently (or correctly) implemented by C++ simulation of recursion
- The idea is that the recursive function ought to be expressible in few lines just like any non recursive function
- An example of nonmathematical use of recursion to solve problems is a dictionary where we look up for a word in the dictionary, but we might not always understand the definition so we’ll need to look up for other words in the definition, if the latter is still vague we’ll need to look up for the meaning of the vague words and so on. Since the dictionary is finite, we end up in two different situations: If we understand the meaning of all the words in the definition , we are done, or we figure out that the meaning of a word is not defined or circularly defined in the dictionary
- Recursion is often linked to the proof by induction, for example, you can prove that a recursive program is true for all positive integer n  by induction on N
- An example of this, is a program that prints one digit at a time this program defines a recursive function that prints a number by printing out one digit at a time and makes recursive calls to output the remaining digits of that number, the theorem to prove is that the program is valid for all positive integers of k digits, then we perform the proof by induction on a number of k digits
- The recursive program needs only to combine solutions to smaller problems, which are “magically” obtained by recursion, into a solution for the current problem. The mathematical justification for this is proof by induction.
- One rule of recursion is the design rule in which we assume that all the recursive calls work correctly, meaning that you don’t need to know the details of the bookkeeping arrangements because frequently it is extremely difficult to track down the actual sequence of recursive calls
- The problem with recursion is the hidden bookkeeping costs. Therefore recursion should not be used as a substitute for a simple for loops
- The four basic rules of recursion are:
    - Base cases: can be solved without recursion
    - Making progress: (towards the base case) for the cases that are to be  solved recursively
    - Design rule: assume that all the recursive calls work
    - Compound interest rule: Never duplicate the work to solve similar instances of a problem in separate recursive calls

## C++ Classes:

All data structures that will be studied are objects that store data and will provide functions that manipulate the data. In C++, this is accomplished by using classes

- Default parameters can be used in any function, but they are most commonly used in constructors
- It’s possible to instantiate an object of class test using the following syntax
    
    test obj{4};
    
- Providing one single constructor with default parameter is better than providing two constructors one that accepts no arguments and an other which accepts one argument
- The initialization list must be used prior to the body of the constructor when a data member of the class is an object of an other class (composition) or if a data member is a const variable meaning that it is not changeable after the object has been constructed
- You can use curly braces { } instead of brackets ( ) in the initialization list
- **Explicit constructors :**
    
    You should make all one parameter constructors explicit to avoid behind-the-scenes conversions ( there are somewhat lenient rules that will allow type conversions without explicit casting operations) which destroys strong typing and can lead to hard-to-find bugs
    
    Suppose the constructor prototype is not preceded with the explicit keyword, then a code like this one knowing that C is a user defined class:
    
    ```css
    C obj;
    obj = 30;
    ```
    
    will run successfully through the C++’s lenient rules, a one-parameter constructor defines an **implicit type conversion,** in which a temporary object is created holding the value 30, then the latter is assigned to obj 
    
    ```css
    C temporary = 30; // the constructor of the temporary can use the one-parameter constructor
    obj = temporary;
    ```
    
    Thus, when using explicit constructors, one-parameter constructor cannot be used to generate temporary object, so the compiler will indicate that there is a type mismatch
    
- **Accessor and mutator:**
    - a method that alter the state of its object is called a **mutator**
    - a method that only examines but does not modify its object is called an **accessor and characterized by the keyword const (const method)**
    - It’s recommended to specify that the function is mutator or accessor as a comment

## Separation of Interface and Implementation:

- In C++, it is common to separate the interface from the implementation
- Source code that requires knowledge of the interface must #include the header file ( .h) containing the interface, there is the danger that an interface might be read twice during the compilation of a program which is illegal, that is why we tend to use the preprocessor directives
    
    #ifndef …
    
    #define …
    
    #endif
    
- Never forget the binary scope resolution operator (: :) in the functions ‘ definitions

- A declaration like
    
    ```css
    C obj( );
    ```
    
    is illegal because the previous line defines a function with no parameter that returns an object of the class C
    

### vector and string:

C++ standard defines two classes: vector and string. vectors are a dynamic and flexible substitue of arrays, for example, built-in arrays cannot be copied using =, built-in arrays do not remember how many items they can store, and its indexing operator does not check that the index is within range.

**Vectors:**

- .size( ) is a method used to return the number of items that a vector object can store
- It’s legal to declare a vector as follows:

```cpp
vector<int> daysInMonth ={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
```

instead of a declaration like this one:

```cpp
vector<int> daysInMonth( 12 ); // No {} before C++11
daysInMonth[ 0 ] = 31; daysInMonth[ 1 ] = 28; 
daysInMonth[ 2 ] = 31;daysInMonth[ 3 ] = 30; 
daysInMonth[ 4 ] = 31; daysInMonth[ 5 ] = 30;
daysInMonth[ 6 ] = 31; daysInMonth[ 7 ] = 31; 
daysInMonth[ 8 ] = 30;daysInMonth[ 9 ] = 31; 
daysInMonth[ 10 ] = 30; daysInMonth[ 11 ] = 31;
```

However, using the assignment operator (=) when initializing a vector violates the spirit of uniform initialization, so it is preferable to initialize a vector using the following syntax:

```cpp
vector <int> daysInMonth {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
```

A problem: Is daysInMonth considered as a vector of size 1 or of size 12?

```cpp
vector <int> daysInMonth { 12 }; //This is considered as a vector of size 1 having the element 12
```

```cpp
vector <int> daysInMonth (12); // This is considered as a vector of size 12
```

The range for loop: the range for loop is used if every item in the array/vector/string is being accessed sequentially and only if the index is not needed , so basically it allows only the viewing of items not altering their values

```cpp
int square[5] = {1, 4, 5, 8, 9};
int sum = 0;
for (int x : square)    //  <=>    for (auto x : square) 
{                       //  <=>       sum += x;
	sum += x;             // in many cases, the type of the index is unneeded, so we can set it to auto, thus the compiler will automatically infer the appropriate type
}
```

### C++ pointers:

**Dynamic memory allocation :**

- It’s not a good practice to declare a pointer without initializing it to some value, as a solution, you can either initialize the pointer when being defined or initialize it to NULL before assigning some value to it. Because the use of uninitialized pointers crashes the program and causes the program to access illegal memory locations

**Garbage collection and delete :**

- In some languages, when an object is no longer referenced, it is subject to automatic garbage collection. C++, in the other hand, does not have automatic garbage collection, so the programmer needs to manually delete dynamic allocated objects, otherwise it results in memory leak
- Two pointers are equal if they point exactly at the same object/ variable

### Rvalues, Lvalues and References :

- An **lvalue** is an expression that identifies a non-temporary objecy
- An **rvalue** is an expression that identifies a temporary object, or is a value (such as a literal constant) not
associated with any object.
- There are some cases where a function returns an rvalue, for example when returning *ptr (dereference) or arr[x]...
- An lvalue reference is declared by placing one single ampresand & after the data type being referenced to. An lvalue reference then becomes a synonym (a second name) to the object it references
    
    ```cpp
    **string str = "hell";
    string & rstr = str; // rstr is another name for str
    rstr += ’o’; // changes str to "hello"
    bool cond = (&str == &rstr); // true; str and rstr are same object
    string & bad1 = "hello"; // illegal: "hello" is not a modifiable lvalue
    string & bad2 = str + ""; // illegal: str+"" is not an lvalue
    string & sub = str.substr( 0, 4 ); // illegal: str.substr( 0, 4 ) is not an lvalue**
    ```
    
- An rvalue reference is declared by placing (&&) after some data type, it has the same characteristics as an lvalue reference except that unlike an lvalue reference, an rvalue reference can also reference to an rvalue
    
    ```cpp
    **string str = "hell";
    string && bad1 = "hello"; // Legal
    string && bad2 = str + ""; // Legal
    string && sub = str.substr( 0, 4 ); // Legal**
    ```
    

- **lvalue reference use cases:**
    - The simplest use, is to use an lvalue reference as as an alias for complicated expressions
    - Range for loops instead of writing a code like this one knowing that arr is a vector object :
        
        ```cpp
        for (int i = 0 ; i < arr.size() ; ++i)
        		++arr[i];
        ```
        
        A more elegant way is to use range for loop
        
        ```cpp
        for (auto& x: arr)   // for (auto x : arr)
        		++x;             //     ++x;
        // this will not work as it makes a copy of x each time and doesn't affect the arr elements
        ```
        
    - To avoid copying overhead, e.g with vectors that contain a large number of items (Remember vectors are objects not pointers as built-in arrays so it’s better to use )
        
        Call-by-constant-reference is appropriate for large objects that should not be altered by the function and are expensive to copy
        
    - Passing an argument to functions to be able to alter its value
