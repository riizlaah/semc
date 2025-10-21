#pragma once

#include <string>
#include <iostream>

void print(const std::string& msg) {
    std::cout << msg;
    std::flush(std::cout);
}