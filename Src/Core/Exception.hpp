/*
** EPITECH PROJECT, 2022
** aurele.nicolas@epitech.eu
** File description:
** Exception
*/

#ifndef ARCADE_EXCEPTION_HPP
#define ARCADE_EXCEPTION_HPP

#include <exception>
#include <string>

#define EX_PARAMS __PRETTY_FUNCTION__, __LINE__, __FILE__
#define ArcadeEX(what) ArcadeException(what, EX_PARAMS)
#define FactoryEX(what) FactoryException(what, EX_PARAMS)
#define InvalidFileEX(what) InvalidFileException(what, EX_PARAMS)
#define FileNotFoundEX(what) FileNotFoundException(what, EX_PARAMS)
#define FileCorruptedEX(what) FileCorruptedException(what, EX_PARAMS)
#define FileUnreadableEX(what) FileUnreadableException(what, EX_PARAMS)
#define LibraryEX(what) LibraryException(what, EX_PARAMS)
#define GameEX(what) GameException(what, EX_PARAMS)
#define GraphEX(what) GraphException(what, EX_PARAMS)
#define EntityEX(what) EntityException(what, EX_PARAMS)
#define EventEX(what) EventException(what, EX_PARAMS)
#define VeryStupidUserEX(what) VeryStupidUserException(what, EX_PARAMS)

class ArcadeException : public std::exception {
    public:
        // @brief Constructor
        // @param what The description of the exception
        // @param where The function where the exception is thrown
        explicit ArcadeException(std::string const &what, std::string const &func, int const &line, std::string const &file);
        // @brief returns the description of the exception
        // @return the description of the exception
        [[nodiscard]] const char *what() const noexcept override;
        // @brief returns where the exception is thrown
        // @return the where the exception has been thrown
        [[nodiscard]] const std::string &where() const noexcept;
        // @brief returns the function where the exception is thrown
        // @return the function where the exception is thrown
        [[nodiscard]] const std::string &getFunc() const noexcept;
        // @brief returns the file where the exception is thrown
        // @return the file where the exception is thrown
        [[nodiscard]] const std::string &getFile() const noexcept;
        // @brief returns the line where the exception is thrown
        // @return the line where the exception is thrown
        [[nodiscard]] const int &getLine() const noexcept;
        // @brief returns the name of the exception
        // @return the name of the exception
        [[nodiscard]] const std::string &getName() const noexcept;

    protected:
        std::string _name;
        std::string _what;
        std::string _where;
        std::string _func;
        std::string _file;
        int _line;

    private:
};

// @brief Exception class for the factory
class FactoryException : public ArcadeException {
    public:
        FactoryException(std::string const &what, std::string const &func, int const &line, std::string const &file) : ArcadeException(what, func, line, file) { _name = "FactoryException"; };
};
// @brief Exception class for the factory if a file is invalid
class InvalidFileException : public FactoryException {
    public:
        InvalidFileException(std::string const &what, std::string const &func, int const &line, std::string const &file) : FactoryException(what, func, line, file) { _name = "InvalidFileException"; };
};
// @brief Exception class for the factory if a file is not found
class FileNotFoundException : public InvalidFileException {
    public:
        FileNotFoundException(std::string const &what, std::string const &func, int const &line, std::string const &file) : InvalidFileException(what, func, line, file) { _name = "FileNotFoundException"; };
};
// @brief Exception class for the factory if a file is corrupted
class FileCorruptedException : public InvalidFileException {
    public:
        FileCorruptedException(std::string const &what, std::string const &func, int const &line, std::string const &file) : InvalidFileException(what, func, line, file) { _name = "FileCorruptedException"; };
};
// @brief Exception class for the factory if a file is unreadable
class FileUnreadableException : public InvalidFileException {
    public:
        FileUnreadableException(std::string const &what, std::string const &func, int const &line, std::string const &file) : InvalidFileException(what, func, line, file) { _name = "FileUnreadableException"; };
};
// @brief Exception class for the libraries
class LibraryException : public ArcadeException {
    public:
        LibraryException(std::string const &what, std::string const &func, int const &line, std::string const &file) : ArcadeException(what, func, line, file) { _name = "LibraryException"; };
};
// @brief Exception class for the "Game" libraries
class GameException : public LibraryException {
    public:
        GameException(std::string const &what, std::string const &func, int const &line, std::string const &file) : LibraryException(what, func, line, file) { _name = "GameException"; };
};
// @brief Exception class for the "Graph" libraries
class GraphException : public LibraryException {
    public:
        GraphException(std::string const &what, std::string const &func, int const &line, std::string const &file) : LibraryException(what, func, line, file) { _name = "GraphException"; };
};
// @brief Exception class for the entities
class EntityException : public ArcadeException {
    public:
        EntityException(std::string const &what, std::string const &func, int const &line, std::string const &file) : ArcadeException(what, func, line, file) { _name = "EntityException"; };
};
// @brief Exception class for the events
class EventException : public ArcadeException {
    public:
        EventException(std::string const &what, std::string const &func, int const &line, std::string const &file) : ArcadeException(what, func, line, file) { _name = "EventException"; };
};
// @brief Exception class when a user is very stupid and we can't do what anything for them
class VeryStupidUserException : public ArcadeException {
    public:
        VeryStupidUserException(std::string const &what = "", std::string const &func = "", int const &line = 0, std::string const &file = "") : ArcadeException("Please stop", "You probably need to restart your project from scratch", 0, "User IQ") { _name = "VeryStupidUserException"; (void)what; (void)func; (void)line; (void)file; };
};

#endif /* !ARCADE_EXCEPTION_HPP */
