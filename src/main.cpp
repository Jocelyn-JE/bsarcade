/*
** EPITECH PROJECT, 2025
** bsarcade
** File description:
** main
*/

#include <memory>
#include <iostream>
#include <utility>
#include "DLLoader.hpp"
#include "IDisplayModule.hpp"

int main(void) {
    const char *libs[] = {"./lib/foo.so", "./lib/bar.so", "./lib/baz.so"};

    for (int i = 0; i < 3; i++) {
        class DLLoader<IDisplayModule> displayLib(libs[i]);
        std::unique_ptr<IDisplayModule> &module = displayLib.getInstance();

        module->init();
        std::cout << module->getName() << std::endl;
        module->stop();
    }
    std::cout << "End of the program" << std::endl;
    return 0;
}
