/*
** EPITECH PROJECT, 2025
** bsarcade
** File description:
** Foo
*/

#ifndef LIB_FOO_HPP_
    #define LIB_FOO_HPP_

    #include <string>
    #include "IDisplayModule.hpp"

class Foo : public IDisplayModule {
 public:
    Foo();
    void init() override;
    void stop() override;
    const std::string &getName() const override;
    ~Foo() override;
 private:
    std::string _name;
};

#endif  // LIB_FOO_HPP_
