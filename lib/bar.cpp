/*
** EPITECH PROJECT, 2025
** bsarcade
** File description:
** bar
*/

#include "bar.hpp"
#include <string>
#include <cstdio>
#include <memory>

__attribute__((constructor)) void load(void) {
    printf("[Start] Loading bar...\n");
}

__attribute__((destructor)) void unload(void) {
    printf("[End] Unloading bar...\n");
}

extern "C" std::unique_ptr<IDisplayModule>create(void) {
    printf("Entrypoint for bar!\n");
    return std::make_unique<Bar>();
}

Bar::Bar() : _name("Bar") {
}

void Bar::init() {
    printf("Bar init\n");
}

void Bar::stop() {
    printf("Bar stop\n");
}

const std::string &Bar::getName() const {
    return _name;
}

Bar::~Bar() {
}
