#include <Mini/Core/Log.h>
#include <iostream>

void Mini::Core::Log(std::string_view message) {
    std::cout << "[MiniEngine] " << message << '\n';
}
