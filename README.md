# CPP Modules — 00 to 09

> *C++ is a language where you can write efficient code,\
> or just suffer elegantly.*

---

## Table of Contents

- [About](#about)
- [General Rules](#general-rules)
- [Module 00 — Namespace, Class, Member Functions, stdio streams, Initialization Lists, Static, Const](#module-00)
- [Module 01 — Memory Allocation, Pointers to Members, References, Switch](#module-01)
- [Module 02 — Ad-hoc Polymorphism, Operator Overloading, Orthodox Canonical Class Form](#module-02)
- [Module 03 — Inheritance](#module-03)
- [Module 04 — Subtype Polymorphism, Abstract Classes, Interfaces](#module-04)
- [Module 05 — Repetition and Exceptions](#module-05)
- [Module 06 — C++ Casts](#module-06)
- [Module 07 — C++ Templates](#module-07)
- [Module 08 — Templated Containers, Iterators, Algorithms](#module-08)
- [Module 09 — STL](#module-09)

---

## About

This repository contains the all modules of the **42 School C++ curriculum**, covering core Object-Oriented Programming concepts in C++98. Each module introduces new language features progressively.

All exercises are compiled with:

```
c++ -Wall -Wextra -Werror -std=c++98
```

---

## General Rules

- **Language:** C++98 only — no C++11 or later features
- **No:** `printf`, `malloc`/`free`, `alloca`, VLAs
- **Yes:** `<iostream>`, `<string>`, `<fstream>`, `<sstream>`, `<iomanip>`, `<cmath>`, `<ctime>`
- Every class file is split into `.hpp` (header) and `.cpp` (implementation)
- Include guards on all headers (`#ifndef FOO_HPP / #define FOO_HPP / #endif`)
- No memory leaks (valgrind-clean where applicable)
- Compilation with `-Wall -Wextra -Werror -std=c++98` must succeed

---

## Module 00

> *Warming up with the basics.*

### ex00 — Megaphone

A simple command-line program that SHOUTS its arguments in uppercase.

```
./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
```

**Concepts:** `std::string`, `std::toupper`, `argc/argv`.

---

### ex01 — My Awesome PhoneBook

A retro phonebook that stores up to **8 contacts** in memory (no dynamic allocation, no file I/O). Supports three commands:

| Command  | Description                                             |
|----------|---------------------------------------------------------|
| `ADD`    | Prompts for and stores a new contact                    |
| `SEARCH` | Displays the contact list and allows lookup by index    |
| `EXIT`   | Terminates the program                                  |

When the phonebook is full, the oldest entry is replaced (circular overwrite).

**Key design decisions:**
- Input validation on all fields (name length, phone format, etc.)
- Fields are trimmed and capitalized automatically
- The SEARCH table truncates long fields to 10 chars with a trailing `.`

**Classes:** `Contact`, `PhoneBook`

---

### ex02 — The Job Of Your Dreams

Reconstruct the `Account.cpp` implementation from a pre-existing `tests.cpp` and `Account.hpp` so that the program output matches the provided log (timestamps excluded).

**Concepts:** Static class members, constructor/destructor logging, formatted output.

---

## Module 01

> *Heap, stack, references — choose wisely.*

### ex00 — BraiiiiiiinnnzzzZ

Demonstrates the difference between stack and heap allocation with a `Zombie` class.

- `newZombie(name)` — allocates on the heap, returns a pointer (caller is responsible for `delete`)
- `randomChump(name)` — allocates on the stack, auto-destroyed on scope exit

**Concepts:** `new`, `delete`, object lifetime.

---

### ex01 — Moar brainz!

`zombieHorde(N, name)` allocates an array of N `Zombie` objects with a single `new[]`, sets all their names, and returns the pointer. Freed with `delete[]`.

**Concepts:** Array allocation with `new[]`/`delete[]`.

---

### ex02 — HI THIS IS BRAIN

Declares a `std::string`, a pointer to it, and a reference to it, then prints all three memory addresses and all three values. Demonstrates that pointer and reference hold the same address.

**Concepts:** Pointers vs. references.

---

### ex03 — Unnecessary Violence

Implements two human classes that hold a weapon:

| Class    | Weapon member | Reason                                              |
|----------|---------------|-----------------------------------------------------|
| `HumanA` | `Weapon&`     | Always has a weapon — reference is safe             |
| `HumanB` | `Weapon*`     | May or may not have a weapon — pointer allows NULL  |

**Concepts:** When to use references vs. pointers as members.

---

### ex04 — Sed is for Losers

Reads a file, replaces every occurrence of string `s1` with string `s2`, and writes the result to `<filename>.replace`. Uses only `std::string` — `std::replace` is forbidden.

**Concepts:** File streams (`std::fstream`, `std::ofstream`), string manipulation.

---

### ex05 — Harl 2.0

`Harl` is a complaining robot with four log levels: `DEBUG`, `INFO`, `WARNING`, `ERROR`. Dispatching is done via an **array of member function pointers** — no if/else chain.

**Concepts:** Pointers to member functions.

---

### ex06 — Harl Filter

Extends ex05 with a `switch` statement so that passing a log level prints that level **and all higher levels**. Unknown levels print a default message.

**Concepts:** `switch` fall-through, member function pointer dispatch.

---

## Module 02

> *Numbers, operators, and the Orthodox Canonical Form.*

### Orthodox Canonical Class Form

Every class in this module follows the four mandatory special member functions:

```cpp
MyClass();                            // Default constructor
MyClass(const MyClass& other);        // Copy constructor
MyClass& operator=(const MyClass&);   // Copy assignment operator
~MyClass();                           // Destructor
```

---

### ex00 — My First Class in Orthodox Canonical Form

A `Fixed` class representing a fixed-point number with **8 fractional bits**. Supports only raw bit access (`getRawBits`, `setRawBits`) and logs all special member function calls.

---

### ex01 — Towards a More Useful Fixed-Point Number Class

Extends `Fixed` with:
- `Fixed(int)` — converts integer to fixed-point
- `Fixed(float)` — converts float to fixed-point (`roundf`)
- `toFloat()` / `toInt()` — conversion back
- `operator<<` — stream output (prints as float)

---

### ex02 — Now We're Talking

Full operator overload suite added to `Fixed`:

- **Comparison:** `>`, `<`, `>=`, `<=`, `==`, `!=`
- **Arithmetic:** `+`, `-`, `*`, `/`
- **Increment/Decrement:** `++` (pre/post), `--` (pre/post) — operate on the raw value (smallest representable epsilon)
- **Static utilities:** `min(a, b)` and `max(a, b)` with both const and non-const overloads

---

### ex03 — BSP (Binary Space Partitioning)

A `Point` class (built on `Fixed`) is used to implement a **point-in-triangle test** via the area method:

```
bsp(a, b, c, point) → bool
```

Returns `true` only if `point` is **strictly inside** the triangle (vertices and edges return `false`).

**Algorithm:** Sum of sub-triangle areas must equal the total triangle area, with no sub-area equal to zero.

---

## Module 03

> *The robot inheritance wars.*

All exercises build on a `ClapTrap` base class with:

| Attribute      | Default |
|----------------|---------|
| Hit Points     | 10      |
| Energy Points  | 10      |
| Attack Damage  | 0       |

---

### ex00 — ClapTrap

Base class with `attack()`, `takeDamage()`, and `beRepaired()`. Energy is consumed by attack and repair. Actions are blocked when HP or energy reaches zero.

---

### ex01 — Serena, My Love!

`ScavTrap` inherits from `ClapTrap` (members changed to `protected`):

| Attribute      | ScavTrap |
|----------------|----------|
| Hit Points     | 100      |
| Energy Points  | 50       |
| Attack Damage  | 20       |

Adds `guardGate()` and overrides `attack()` with its own message. Constructor/destructor chain is demonstrated explicitly.

---

### ex02 — Repetita Iuvant

`FragTrap` inherits from `ClapTrap`:

| Attribute      | FragTrap |
|----------------|----------|
| Hit Points     | 100      |
| Energy Points  | 100      |
| Attack Damage  | 30       |

Adds `highFivesGuys()` (positive attitude).

---

### ex03 — Now It's Getting Weird

`DiamondTrap` uses **multiple inheritance** from both `ScavTrap` and `FragTrap`. Both parents inherit `ClapTrap` **virtually** to avoid the diamond ambiguity.

| Attribute      | DiamondTrap (source) |
|----------------|----------------------|
| Hit Points     | FragTrap (100)       |
| Energy Points  | ScavTrap (50)        |
| Attack Damage  | FragTrap (30)        |

`DiamondTrap` has its **own** `_name`. The `ClapTrap` base receives `name + "_clap_name"`. The `whoAmI()` method prints both.

**Concepts:** Virtual inheritance, diamond problem, constructor call order.

---

## Module 04

> *Polymorphism, deep copies, and interfaces.*

### ex00 — Polymorphism

`Animal` base with a `virtual makeSound()`. `Dog` and `Cat` override it. Demonstrates correct virtual dispatch through base pointers/references.

`WrongAnimal` / `WrongCat` are provided as contrast — without `virtual`, the base version is called instead of the derived one.

---

### ex01 — I Don't Want to Set the World on Fire

`Dog` and `Cat` each own a `Brain*` (heap-allocated array of 100 `std::string` ideas). The **deep copy** requirement is enforced:

- Copy constructor: allocates a **new** `Brain` and copies contents
- Copy assignment: reuses or reallocates `Brain` safely
- Destructor: `delete brain`

No two animals share the same `Brain`.

---

### ex02 — Abstract Class

`Animal::makeSound()` becomes a **pure virtual function**:

```cpp
virtual void makeSound() const = 0;
```

`Animal` is now abstract — instantiating it directly is a compile-time error. Only `Dog` and `Cat` can be instantiated.

---

### ex03 — Interface & Recap

A mini RPG system built from scratch using interfaces and abstract classes:

```
IMateriaSource  (interface)
    └── MateriaSource

ICharacter      (interface)
    └── Character

AMateria        (abstract)
    ├── Ice
    └── Cure
```

**Flow:**
1. `MateriaSource` learns up to 4 materia types
2. `createMateria(type)` returns a cloned instance
3. `Character` equips up to 4 materia in an inventory
4. `character.use(idx, target)` triggers the materia's effect

**Memory management:** `unequip()` drops the pointer without deleting (leak is intentional per subject). Clone pattern ensures independence.

---

## Module 05

> *Bureaucracy: the only system where throwing an exception is a career move.*

### Core Concept — Exceptions

Module 05 introduces C++ exception handling through a satirical bureaucratic simulation. Every class in this module follows the **Orthodox Canonical Form**. Grade values are constrained to the range `[1, 150]` — lower number means higher rank.

---

### ex00 — Mommy, When I Grow Up I Want to Be a Bureaucrat!

A `Bureaucrat` class with a `const` name and an integer grade. Grade bounds are enforced at construction and mutation time.

| Member           | Description                                                    |
|------------------|----------------------------------------------------------------|
| `_name`          | `const std::string` — immutable after construction             |
| `_grade`         | `int` in range `[1, 150]`                                      |
| `incrementGrade` | Decrements the integer (`_grade--`), throws if already at 1   |
| `decrementGrade` | Increments the integer (`_grade++`), throws if already at 150 |

**Nested exception classes** (inherit from `std::exception`):

```cpp
class GradeTooHighException : public std::exception { ... };
class GradeTooLowException  : public std::exception { ... };
```

The `operator<<` overload prints `<name>, bureaucrat grade <grade>`.

**Concepts:** `std::exception`, nested exception classes, `what() const throw()`, `const` members.

---

### ex01 — Form Up, Maggots!

Introduces a `Form` class. A bureaucrat can attempt to sign a form via `signForm(Form&)`, which calls `form.beSigned(*this)` and reports success or failure.

| Attribute              | Description                                        |
|------------------------|----------------------------------------------------|
| `_name`                | `const std::string`                                |
| `_isSigned`            | `bool`, starts as `false`                          |
| `_gradeRequiredToSign` | `const int` — bureaucrat must be `<=` this value  |
| `_gradeRequiredToExecute` | `const int`                                  |

`beSigned(const Bureaucrat&)` throws `GradeTooLowException` if the bureaucrat's grade is insufficient. Already-signed forms are silently skipped.

**Concepts:** Cross-referencing classes with forward declarations, mutual dependency (Bureaucrat ↔ Form).

---

### ex02 — No, You Need More

`Form` becomes the abstract base class `AForm`. Three concrete form types are added, each with fixed grade requirements and a unique `execute()` action:

| Form                    | Sign Grade | Execute Grade | Action                                              |
|-------------------------|:----------:|:-------------:|-----------------------------------------------------|
| `ShrubberyCreationForm` | 145        | 137           | Writes ASCII trees to `<target>_shrubbery`          |
| `RobotomyRequestForm`   | 72         | 45            | Drills noisily; 50% success rate via `rand()`       |
| `PresidentialPardonForm`| 25         | 5             | Announces pardon by Zaphod Beeblebrox               |

`AForm::execute()` is pure virtual. A protected helper `checkExecutionRequirements(executor)` validates that the form is signed and the executor's grade is sufficient — all concrete forms call it first.

`Bureaucrat` gains `executeForm(AForm const&)`, which wraps `execute()` in a try/catch and reports the outcome.

**Concepts:** Abstract base classes, pure virtual functions, protected helpers, `std::ofstream`.

---

### ex03 — At Least This Is Not as Bad as It Looks

Adds an `Intern` class with no name, grade, or attributes. Its sole purpose is:

```cpp
AForm* Intern::makeForm(std::string formName, std::string target);
```

The implementation avoids if/else chains by using an **array of structs** containing form names and **member function pointers**:

```cpp
struct FormEntry {
    std::string name;
    AForm* (Intern::*creator)(std::string const& target);
};
```

The array is iterated to find the matching form name, then the corresponding factory method is called. Unknown names print an error message and return `NULL`.

**Concepts:** Pointers to member functions, Factory Method pattern, array dispatch.

---

## Module 06

> *With great power comes great undefined behavior.*

### Core Concept — The Four C++ Casts

| Cast                | Use case                                                              |
|---------------------|-----------------------------------------------------------------------|
| `static_cast`       | Compile-time conversions between related types                        |
| `reinterpret_cast`  | Low-level bit reinterpretation; pointer ↔ integer                    |
| `dynamic_cast`      | Runtime polymorphic downcasting; returns `NULL`/throws on failure    |
| `const_cast`        | Adding or removing `const` qualifier                                  |

C-style casts are forbidden throughout this module.

---

### ex00 — Conversion of Scalar Types

A non-instantiable `ScalarConverter` class with a single static method:

```cpp
static void convert(std::string const& literal);
```

The method detects the type of the literal (char, int, float, double, or special value) and prints all four scalar conversions.

**Detection pipeline:**

1. Check against special strings: `nan`, `nanf`, `inf`, `+inf`, `-inf`, `inff`, `+inff`, `-inff`
2. Single printable non-digit character → `char`
3. Digits only (optional leading sign) → `int`
4. Digits + optional dot + trailing `f` → `float`
5. Digits + mandatory dot (no `f`) → `double`
6. Anything else → `impossible` on all four lines

**Edge cases handled:** out-of-range values, non-displayable characters, integral vs. fractional display (appends `.0` when needed), overflow detection against `INT_MIN`/`INT_MAX`.

**Concepts:** `static_cast`, `std::strtod`, `std::strtol`, `std::isnan`, `std::isinf`, `std::isprint`.

---

### ex01 — Serialization

A non-instantiable `Serializer` class with two static methods:

```cpp
static uintptr_t serialize(Data* ptr);
static Data*     deserialize(uintptr_t raw);
```

`Data` is a plain struct with an `int value` field. The round-trip `deserialize(serialize(ptr)) == ptr` is validated for both stack and heap allocations.

**Concepts:** `reinterpret_cast`, `uintptr_t`, pointer identity, non-instantiable utility classes.

---

### ex02 — Identify Real Type

Three empty classes `A`, `B`, `C` all inherit from `Base` (which has only a virtual destructor). Two overloaded `identify` functions detect the actual runtime type:

```cpp
void identify(Base* p);   // uses dynamic_cast — NULL check
void identify(Base& p);   // uses dynamic_cast — try/catch
```

A `generate()` function randomly allocates one of the three types and returns a `Base*`.

**Key distinction:** Casting a pointer returns `NULL` on failure (no exception); casting a reference throws `std::bad_cast` on failure — so the reference version must use try/catch blocks.

**Concepts:** `dynamic_cast`, RTTI, virtual destructor requirement, pointer vs. reference cast semantics.

---

## Module 07

> *One function to rule them all.*

### Core Concept — Templates

C++ templates allow writing type-independent code. The compiler generates a concrete specialization for each type used. All template code lives in header files (the compiler needs the full definition at instantiation time).

---

### ex00 — Start With a Few Functions

Three function templates in `functions.hpp`:

```cpp
template void      swap(T& a, T& b);
template const T&  min(const T& a, const T& b);
template const T&  max(const T& a, const T& b);
```

`min` and `max` return the **second argument** on equality (by convention). All three work with any type that supports `<`, `>`, and `==`.

**Concepts:** Function templates, `typename`, return by `const T&`, preventing accidental type deduction conflicts with `::swap` vs `std::swap`.

---

### ex01 — Iter

A single function template that applies a function to every element of an array:

```cpp
template
void iter(const T* arr, const int size, void (*f)(const T&));
```

The callback `f` is a plain function pointer. `const T*` allows the template to accept both `const` and non-`const` arrays (the element is always passed as `const T&` to the function).

Test functions include `print<T>`, `printSquared<T>`, and `printLength` (non-template, works only on `std::string`).

**Concepts:** Function pointer as template parameter, `const` correctness with array templates.

---

### ex02 — Array

A class template `Array<T>` that wraps a dynamically allocated array with bounds checking:

```cpp
template
class Array {
    ...
    T&       operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;
};
```

| Constructor         | Behavior                                         |
|---------------------|--------------------------------------------------|
| `Array()`           | Empty array (`_data = NULL`, `_size = 0`)        |
| `Array(unsigned n)` | Allocates `n` elements, value-initialized        |
| `Array(const Array&)` | Deep copy — independent allocation             |

Out-of-bounds access throws `std::out_of_range`. Copy and assignment always produce independent copies (no shared memory).

**Concepts:** Class templates, `new T[n]` (value initialization), `delete[]`, `const` operator overloads, deep copy semantics.

---

## Module 08

> *The STL: someone else's algorithms, your problem.*

### Core Concept — Containers, Iterators, Algorithms

The C++ Standard Template Library provides generic containers (`vector`, `list`, `map`, `stack`, etc.) and algorithms (`std::find`, `std::sort`, `std::min_element`, etc.) that work through iterators.

---

### ex00 — Easy Find

A single function template that searches any integer sequence container for a value:

```cpp
template
void easyfind(const T& container, int value);
```

Uses `std::find(container.begin(), container.end(), value)`. Throws `std::exception` if the value is not found. Works with `std::vector<int>`, `std::list<int>`, or any container that provides `begin()`/`end()` iterators over `int`.

**Concepts:** Template + STL algorithm integration, iterator abstraction.

---

### ex01 — Span

A `Span` class stores up to `N` integers (set at construction) and can report the shortest and longest spans between any two stored values.

```cpp
Span(unsigned int N);
void         addNumber(int number);       // throws if full
unsigned int shortestSpan();              // throws if < 2 elements
unsigned int longestSpan();               // throws if < 2 elements
```

A range-insertion template method allows filling from any iterator pair:

```cpp
template
void addNumbers(T begin, T end);  // throws on overflow
```

`shortestSpan` sorts a copy and finds the minimum adjacent difference. `longestSpan` uses `std::max_element` and `std::min_element`.

**Concepts:** `std::vector`, `std::sort`, `std::distance`, `std::max_element`, range insertion with iterators.

---

### ex02 — Mutant Stack

`std::stack` is a container adaptor — it wraps a deque but deliberately hides its iterators. `MutantStack<T>` inherits from `std::stack<T>` and exposes the underlying container's iterators:

```cpp
template
class MutantStack : public std::stack {
    typedef typename std::stack::container_type::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end();   }
};
```

`this->c` is the protected member of `std::stack` (the underlying `std::deque<T>`).

**Concepts:** Inheriting from STL adaptors, `typename` in dependent type names, accessing protected members, `typedef` for nested types.

---

## Module 09

> *Real data, real algorithms, real pain.*

### Core Concept — STL in Practice

Module 09 applies STL containers and algorithms to three concrete problems: financial data processing, stack-based expression evaluation, and a comparison sort benchmark.

---

### ex00 — Bitcoin Exchange

A command-line tool that reads a historical Bitcoin price database (`data.csv`) and an input file, then prints the value of each Bitcoin amount on the closest available date.

```
./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 1.2 = 0.36
...
```

**Architecture:**

- `BitcoinExchange` holds a `std::map<std::string, double>` — date strings sort lexicographically, which matches chronological order perfectly
- `getRate(date)` uses `lower_bound` to find the exact or closest earlier date
- `processInputFile` validates each line with static helpers before looking up the rate

**Validation pipeline for input lines:**
- Date must match `YYYY-MM-DD` format with valid calendar values (leap year aware)
- Value must be a finite decimal number in `[0, 1000]`; rejects scientific notation, `nan`, `inf`, multi-dot
- Pipe separator `|` is required; both sides are whitespace-trimmed

**Concepts:** `std::map`, `lower_bound`, `std::strtod`, `std::strtol`, file parsing, input validation.

---

### ex01 — RPN

A Reverse Polish Notation calculator. Takes a single quoted expression as argument and evaluates it using a `std::stack<int>`.

```
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
```

**Token processing rules:**
- Single digit `[0-9]` → push onto stack
- Operator `+ - * /` → pop two operands, compute, push result
- Multi-character token, unknown character, division by zero → print `Error`
- Final stack must contain exactly one value; otherwise `Error`

**Concepts:** `std::stack`, RPN evaluation, error handling via exceptions, `std::stringstream` tokenization.

---

### ex02 — PmergeMe

The **Ford-Johnson algorithm** (merge-insertion sort) implemented for two containers in parallel, with timing output.

```
./PmergeMe 3 5 9 7 4
Before:   3 5 9 7 4
After:    3 4 5 7 9
Time to process a range of   5 elements with std::vector<int> : 2.4 us
Time to process a range of   5 elements with std::deque<int>  : 3.1 us
```

**Algorithm overview:**

1. Pair elements; sort each pair so the larger element is the "main chain" and smaller is "pending"
2. Recursively sort the main chain by the same algorithm
3. Re-align pending elements to their sorted main chain partners
4. Insert pending elements into the main chain in **Jacobsthal order** (minimizing comparisons) using binary search

**Jacobsthal insertion order:** The sequence `1, 3, 5, 11, 21, 43, ...` controls which pending element is inserted next to bound the binary search range optimally.

Both `std::vector<int>` and `std::deque<int>` run the full algorithm independently. Timing uses `clock()`.

| Helper                    | Description                                             |
|---------------------------|---------------------------------------------------------|
| `buildInsertionOrder(n)`  | Returns the Jacobsthal-based index order for n elements |
| `binaryInsertVector/Deque`| Binary search insert within `[0, upperBound)`          |
| `parseInput`              | Validates positive integer tokens, rejects duplicates   |

**Concepts:** `std::vector`, `std::deque`, recursive algorithms, binary search insertion, `clock_t` benchmarking, Jacobsthal numbers.

## Author

**caide-so** — caide-so@student.42sp.org.br
