/*
** EPITECH PROJECT, 2022
** aurele.nicolas@epitech.eu
** File description:
** Logger
*/

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

class ArcadeException;
class ArcadeInfo;

/// \brief Logger class to log exceptions
class Logger {
    public:
        /// \brief Deleted Constructor, this class must not be instantiated.
        Logger() = delete;
        /// \brief log the exception before throwing it
        /// \param ex the exception to log
        /// \return the exception
        static ArcadeException log(ArcadeException exception);
        static ArcadeInfo log(ArcadeInfo info);
        /// \brief pass this function to the macros and they will log the exception
        /// \return true
        static bool ENABLED();
        /// \brief pass this function to the macros and they will not log the exception
        /// \return false
        static bool DISABLED();

    protected:
    private:
};

#endif /* !LOGGER_HPP_ */
