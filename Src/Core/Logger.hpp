/*
** EPITECH PROJECT, 2022
** aurele.nicolas@epitech.eu
** File description:
** Logger
*/

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

class ArcadeException;

/// \brief Logger class to log exceptions
class Logger {
    public:
        enum Severity {
            SEVERITY_NONE = 0,
            SEVERITY_LOW = 1,
            SEVERITY_MEDIUM = 2,
            SEVERITY_HIGH = 3,
            SEVERITY_CRITICAL = 4,
            SEVERITY_INFO = 5
        };
        /// \brief Deleted Constructor, this class must not be instantiated.
        Logger() = delete;
        /// \brief log the exception before throwing it
        /// \param ex the exception to log
        /// \return the exception
        static ArcadeException log(ArcadeException exception, Severity severity);
        /// \brief pass this function to the macros and they will not log the exception
        /// \return Severity::NONE
        static Severity NONE();
        /// \brief pass this function to the macros and they will log the exception with a low severity
        /// \return Severity::LOW
        static Severity LOW();
        /// \brief pass this function to the macros and they will log the exception with a medium severity
        /// \return Severity::MEDIUM
        static Severity MEDIUM();
        /// \brief pass this function to the macros and they will log the exception with a high severity
        /// \return Severity::HIGH
        static Severity HIGH();
        /// \brief pass this function to the macros and they will log the exception with a critical severity
        /// \return Severity::CRITICAL
        static Severity CRITICAL();
        /// \brief pass this function to the macros and they will log an info
        /// \return Severity::INFO
        static Severity INFO();


    protected:
    private:
};

#endif /* !LOGGER_HPP_ */
