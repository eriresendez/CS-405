// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Ericka Resendez
//

#include <iostream>

// adding custom exception class derived from the std::exception 
// allowing for a customized message to be returned
class CustomException : public std::exception {
public: 
    const char* what() const noexcept override {
        return "Custom Exception.";
    }
};

bool do_even_more_custom_application_logic()
{
    // Throw any standard exception
    throw std::bad_exception();

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}
void do_custom_application_logic()
{
    // Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    try {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (const std::exception& exception) {
        std::cerr << "Exception message: " << exception.what() << std::endl;
    }

    // Throwing a custom exception derived from std::exception
    //  and catch it explictly in main
    throw CustomException();

    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    if (den == 0) {
        throw std::runtime_error("Error: division by zero not possible!");
    }
    return (num / den);
}

void do_division() noexcept
{
    //  create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;

    try {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }

    catch (const std::exception& exception) {
        std::cerr << "do_division(): Exception message: " << exception.what() << std::endl; 
    }
}
int main()
{
    try {
        std::cout << "Exceptions Tests!" << std::endl;

        // TODO: Create exception handlers that catch (in this order):
        //  your custom exception
        //  std::exception
        //  uncaught exception 
        //  that wraps the whole main function, and displays a message to the console.
        do_division();
        do_custom_application_logic();
    }
    catch (const CustomException & exception) {
        std::cerr << "main: Custom Exception has occured: " << exception.what() << std::endl;
    }
    catch (const std::exception & exception) {
        std::cerr << "main: Standard Exception has occured: " << exception.what() << std::endl;
    }
    // catching unhandled exceptions
    catch (...) {
        std::cerr << "main: Unknown exception occured" << std::endl;
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu