/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** AEntity
*/

#ifndef AENTITY_HPP_
#define AENTITY_HPP_

#include "IEntity.hpp"

class AEntity : public IEntity {
    public:
        /// \brief Constructor
        /// \param type The type of entity.
        AEntity();
        /// \brief Destructor
        ~AEntity();

        /// \brief Get the entity position
        /// \return The std::pair<int, int> position
        std::pair<int, int> getPos() const;
        /// \brief Set the entity position
        /// \param Pos the std::pair<int, int> position
        void setPos(std::pair<int, int> pos);
        /// \brief Get the entity size
        /// \return The std::pair<int, int> size
        std::pair<int, int> getSize() const;
        /// \brief Set the entity size
        /// \param Size the std::pair<int, int> size
        void setSize(std::pair<int, int> size);
        /// \brief Set the Entity boolean isMoving
        virtual void setIsMoving(bool isMoving);
        /// \brief Get the Entity boolean isMoving
        /// \return bool isMoving;
        virtual bool getIsMoving() const;

    protected:
        std::pair<int, int> _pos;
        std::pair<int, int> _size;
        bool _isMoving;
    private:
};

#endif /* !AENTITY_HPP_ */
