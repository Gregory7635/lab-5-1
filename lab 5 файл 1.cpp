#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class Stack {
private:
    std::vector<T> elements;
public:
    void push(const T& element) {
        elements.push_back(element);
    }

    T pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        T element = elements.back();
        elements.pop_back();
        return element;
    }

    const T& top() const {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elements.back();
    }

    bool empty() const {
        return elements.empty();
    }
};

int main() {
    try {
        Stack<int> intStack;
        intStack.push(1);
        intStack.push(2);
        std::cout << "Top of intStack: " << intStack.top() << std::endl;

        Stack<double> doubleStack;
        doubleStack.push(3.14);
        doubleStack.push(2.718);
        std::cout << "Top of doubleStack: " << doubleStack.top() << std::endl;

        Stack<std::string> stringStack;
        stringStack.push("Hello");
        stringStack.push("World");
        std::cout << "Top of stringStack: " << stringStack.top() << std::endl;
        // Попытка извлечь элемент из пустого стека
        // Это вызовет исключение
        std::cout << "Popping from intStack: " << intStack.pop() << std::endl;
        std::cout << "Popping from intStack: " << intStack.pop() << std::endl;
        std::cout << "Popping from intStack: " << intStack.pop() << std::endl; // This line will throw an exception

    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
