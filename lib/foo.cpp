/*
** EPITECH PROJECT, 2025
** bsarcade
** File description:
** foo
*/

#include "foo.hpp"
#include <string>
#include <cstdio>
#include <memory>

__attribute__((constructor)) void load(void) {
    printf("[Start] Loading foo...\n");
}

__attribute__((destructor)) void unload(void) {
    printf("[End] Unloading foo...\n");
}

extern "C" std::unique_ptr<IDisplayModule>create(void) {
    printf("Entrypoint for foo!\n");
    return std::make_unique<Foo>();
}

Foo::Foo() : _name("Foo") {
}

void Foo::init() {
    printf("Foo init\n");
}

void Foo::stop() {
    printf("Foo stop\n");
}

const std::string &Foo::getName() const {
    return _name;
}

Foo::~Foo() {
}
