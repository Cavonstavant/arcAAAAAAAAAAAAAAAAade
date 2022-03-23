/*
** EPITECH PROJECT, 2022
** aurele.nicolas@epitech.eu
** File description:
** Logger
*/

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

class ArcadeException;

class Logger {
    public:
        /// \brief log the exception before throwing it
        /// \param ex the exception to log
        /// \return the exception
        static ArcadeException log(ArcadeException exception);
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
