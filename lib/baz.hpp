/*
** EPITECH PROJECT, 2025
** bsarcade
** File description:
** Baz
*/

#ifndef LIB_BAZ_HPP_
    #define LIB_BAZ_HPP_

    #include <string>
    #include "IDisplayModule.hpp"

class Baz : public IDisplayModule {
 public:
    Baz();
    void init() override;
    void stop() override;
    const std::string &getName() const override;
    ~Baz() override;
 private:
    std::string _name;
};

#endif  // LIB_BAZ_HPP_
