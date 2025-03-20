/*
** EPITECH PROJECT, 2025
** bsarcade
** File description:
** bar
*/

#ifndef LIB_BAR_HPP_
    #define LIB_BAR_HPP_

    #include <string>
    #include "IDisplayModule.hpp"

class Bar : public IDisplayModule {
 public:
    Bar();
    void init() override;
    void stop() override;
    const std::string &getName() const override;
    ~Bar() override;
 private:
    std::string _name;
};

#endif  // LIB_BAR_HPP_
