Exception Handling in C++
Exception handling lets you manage runtime errors gracefully using three keywords: try, throw, and catch.

Core Mechanics
throw — signals that an error has occurred. You can throw any type: integers, strings, or objects.
try — wraps the code that might throw an exception.
catch — handles the exception. You can have multiple catch blocks for different types.
A catch(...) block catches anything — use it as a last-resort fallback.

Key Rules

Exceptions propagate up the call stack until caught; if never caught, std::terminate() is called.
Catch by const reference (const std::exception& e) to avoid slicing and unnecessary copies.
Standard exceptions live in <stdexcept>: std::runtime_error, std::out_of_range, std::invalid_argument, etc.
You can rethrow an exception inside a catch block using bare throw;.
Destructors run during stack unwinding — this is why RAII works so well with exceptions.
Mark functions that never throw with noexcept for optimization hints.