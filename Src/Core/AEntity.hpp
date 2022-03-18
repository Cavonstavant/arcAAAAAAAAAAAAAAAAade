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
        /// @brief Constructor
        /// @param type The type of entity.
        AEntity(EntityType type);
        /// @brief Destructor
        ~AEntity();

        /// @brief Get the entity type
        /// @return the EntityType
        EntityType getType() const;
        /// @brief Set the entity type
        /// @param type the EntityType
        void setType(EntityType type);
        /// @brief Get the entity position
        /// @return the std::pair<int, int> position
        std::pair<int, int> getPos() const;
        /// @brief Set the entity position
        /// @param pos the std::pair<int, int> position
        void setPos(std::pair<int, int> pos);
        /// @brief Get the entity size
        /// @return the std::pair<int, int> size
        std::pair<int, int> getSize() const;
        /// @brief Set the entity size
        /// @param size the std::pair<int, int> size
        void setSize(std::pair<int, int> size);

    protected:
    private:
        EntityType _type;
        std::pair<int, int> _pos;
        std::pair<int, int> _size;
};

#endif /* !AENTITY_HPP_ */
