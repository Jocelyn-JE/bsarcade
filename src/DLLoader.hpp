/*
** EPITECH PROJECT, 2025
** bsarcade
** File description:
** DLLoader
*/

#ifndef SRC_DLLOADER_HPP_
    #define SRC_DLLOADER_HPP_

    #include <memory>
    #include <string>
    #include <vector>

template <typename T>
class DLLoader {
 public:
    DLLoader() = delete;
    explicit DLLoader(std::string path) noexcept(false);
    std::unique_ptr<T> &getInstance(void) const noexcept(false);
    ~DLLoader() noexcept(false);
    class DLLoaderException : public std::exception {
     public:
        explicit DLLoaderException(std::string message) noexcept;
        ~DLLoaderException() noexcept;
        const char *what() const noexcept override;
     private:
        std::string _message;
    };
 private:
    void *_libHandle;
    std::vector<std::unique_ptr<T>> _instances;
};
#endif  // SRC_DLLOADER_HPP_
