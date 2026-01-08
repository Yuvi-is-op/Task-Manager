#include <iostream>
#include "App.hpp"

int main() {
    try{
        App app;
        app.run();
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error! " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Error! " << e.what() << std::endl;
    }
    catch(const std::runtime_error& e) {
        std::cout << "Error! " << e.what() << std::endl;
    }

    return 0;
}