/*
** EPITECH PROJECT, 2025
** bsarcade
** File description:
** IDisplayModule
*/

#ifndef SRC_IDISPLAYMODULE_HPP_
    #define SRC_IDISPLAYMODULE_HPP_

    #include <string>

class IDisplayModule {
 public:
    virtual ~IDisplayModule() = default;
    virtual void init() = 0;
    virtual void stop() = 0;
    virtual const std::string &getName() const = 0;
};

#endif  // SRC_IDISPLAYMODULE_HPP_
