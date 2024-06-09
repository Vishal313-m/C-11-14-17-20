// Inline Static Const variable 

class MyClass {
public:
    static inline const int kMyConstant = 42;
    static inline const std::string kMyString = "Hello, World!";
};

int main() {
    std::cout << "The static const value is: " << MyClass::kMyConstant << std::endl;
    std::cout << "The static const string is: " << MyClass::kMyString << std::endl;
    return 0;
}

