/*
** EPITECH PROJECT, 2025
** bsarcade
** File description:
** baz
*/

#include "baz.hpp"
#include <string>
#include <cstdio>
#include <memory>

__attribute__((constructor)) void load(void) {
    printf("[Start] Loading baz...\n");
}

__attribute__((destructor)) void unload(void) {
    printf("[End] Unloading baz...\n");
}

extern "C" std::unique_ptr<IDisplayModule>create(void) {
    printf("Entrypoint for baz!\n");
    return std::make_unique<Baz>();
}

Baz::Baz() : _name("Baz") {
}

void Baz::init() {
    printf("Baz init\n");
}

void Baz::stop() {
    printf("Baz stop\n");
}

const std::string &Baz::getName() const {
    return _name;
}

Baz::~Baz() {
}
