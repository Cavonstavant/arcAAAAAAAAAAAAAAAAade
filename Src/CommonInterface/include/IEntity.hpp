/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** IEntity
*/

#ifndef IENTITY_HPP_
#define IENTITY_HPP_

#include <string>

/// \brief represents a generic entity within the game
class IEntity {
public:
    /// \brief Destructor
    ~IEntity() = default;
    virtual std::pair<int, int> getPos() const = 0;
    /// \brief Set the entity position
    /// \param pos the std::pair<int, int> position
    virtual void setPos(std::pair<int, int> pos) = 0;
    /// \brief Get the entity size
    /// \return the std::pair<int, int> size
    virtual std::pair<int, int> getSize() const = 0;
    /// \brief Set the entity size
    /// \param size the std::pair<int, int> size
    virtual void setSize(std::pair<int, int> size) = 0;
    /// \brief Set the texturePath of the entity
    /// \param std::string texturePath represents the path to find the texture
    virtual void setTexturePath(std::string texturePath) = 0;
    /// \brief Get the texturePAth of the Entity
    virtual std::string getTexturePath(void) const = 0;
};

#endif /* !IENTITY_HPP_ */
