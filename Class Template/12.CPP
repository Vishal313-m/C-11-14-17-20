/* class TEMPLATE ARGUMENT DEDUCTION ctad*/


Class Template Argument Deduction (CTAD) in C++
Before C++17
Before C++17, template argument deduction was only available for function templates, not class templates. This meant that when you wanted to create an instance of a class template, 
you had to explicitly specify the template arguments. For example:

cpp
Copy code
template <typename T>
struct Wrapper {
    T data;
};

Wrapper<int> w{42};  // Template argument explicitly specified
To avoid this, helper functions like std::make_pair were used to deduce template arguments for standard library types:

cpp
Copy code
auto p = std::make_pair(42, 42.0);  // Deduce std::pair<int, double>
C++17 and CTAD
C++17 introduced Class Template Argument Deduction (CTAD), allowing the compiler to deduce the template arguments for class templates from the constructor arguments:

cpp
Copy code
template <typename T>
struct Wrapper {
    T data;
};

Wrapper w{42};  // Template argument deduced as int
Here, the compiler deduces that T is int from the argument 42.

How CTAD Works
The compiler uses deduction guides, which are fictional function templates, to deduce template arguments. It generates these guides based on the constructors of the class template.
 For example, for std::pair, the compiler might generate guides like:

cpp
Copy code
template <typename T1, typename T2>
std::pair<T1, T2> F(T1 const& x, T2 const& y);
If these guides don't cover your needs, you can write your own:

cpp
Copy code
namespace std {
    template <typename T1, typename T2>
    pair(T1&& v1, T2&& v2) -> pair<T1, T2>;
}
Examples with CTAD
Standard Library Types:

cpp
Copy code
std::pair p{42, 42.0};      // std::pair<int, double>
std::vector v{1, 2, 3, 4};  // std::vector<int>
User-defined Class:

cpp
Copy code
template <typename T>
struct Point {
    Point(T x, T y) : x(x), y(y) {}
    T x, y;
};

auto p = new Point(1, 2);  // Point<int>
Custom Deduction Guide:

cpp
Copy code
template <typename T>
struct Range {
    template <typename Iter>
    Range(Iter first, Iter last) {
        std::copy(first, last, std::back_inserter(data));
    }
    std::vector<T> data;
};

template <typename Iter>
Range(Iter, Iter) -> Range<typename std::iterator_traits<Iter>::value_type>;

int arr[] = {1, 2, 3, 4, 5};
Range r(std::begin(arr), std::end(arr));  // Range<int>
Special Cases and Limitations
Aggregate Types: In C++17, CTAD does not work with aggregate types without user-defined deduction guides:

cpp
Copy code
template <typename T>
struct Wrapper {
    T data;
};

// Deduction guide needed in C++17
template <typename T>
Wrapper(T) -> Wrapper<T>;

Wrapper w{42};  // Wrapper<int> in C++20 without a guide
Explicit Template Arguments: CTAD only works if no template arguments are explicitly specified:

cpp
Copy code
std::pair p2{2, "two"};  // OK
std::pair<int> p4{4, "four"};  // Error
Summary
CTAD in C++17 simplifies template usage by allowing the compiler to deduce template arguments for class templates from constructor arguments, 
eliminating the need for helper functions or explicit template arguments in many cases. However, certain cases might still require user-defined deduction guides to work correctly.