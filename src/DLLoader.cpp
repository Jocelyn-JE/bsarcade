/*
** EPITECH PROJECT, 2025
** bsarcade
** File description:
** DLLoader
*/

#include <dlfcn.h>
#include <memory>
#include <string>
#include <iostream>
#include "DLLoader.hpp"

template <typename T>
DLLoader<T>::DLLoader(std::string path) noexcept(false) {
    _libHandle = dlopen(path.c_str(), RTLD_LAZY);
    if (!_libHandle)
        throw DLLoaderException(dlerror());
}

template <typename T>
std::unique_ptr<T> &DLLoader<T>::getInstance(void) const {
    std::unique_ptr<T> (*create)(void) = reinterpret_cast<std::unique_ptr<T>
        (*)(void)>(dlsym(_libHandle, "create"));

    if (!create)
        throw DLLoaderException(dlerror());
    _instances.push_back(create());
    return _instances.back();
}

template <typename T>
DLLoader<T>::~DLLoader() {
    for (std::unique_ptr<T> instance : _instances)
        instance->reset(nullptr);
    if (dlclose(_libHandle) != 0)
        throw DLLoaderException(dlerror());
}

//-----------------------------------------------------------------------------

template <typename T>
DLLoader<T>::DLLoaderException::DLLoaderException(std::string message)
    noexcept : _message(message) {
}

template <typename T>
DLLoader<T>::DLLoaderException::~DLLoaderException() noexcept {
}

template <typename T>
const char *DLLoader<T>::DLLoaderException::what() const noexcept {
    return _message.c_str();
}
