/*
** EPITECH PROJECT, 2022
** Player.hpp.h
** File description:
** Created by hjulien,
*/

#ifndef ARCADE_PLAYER_HPP
#define ARCADE_PLAYER_HPP

#include "AEntity.hpp"

/// \brief Player class inherits from AEntity
/// \param No param to construct all value by default
class Player : public AEntity {
public:
    /// \brief Constructor
    Player();
    /// \brief Destructor
    ~Player();

    /// \brief Set the Entity boolean _isMoving
    void setIsMoving(bool isMoving) override;
    /// \brief Get the Entity boolean _isMoving
    /// \return bool isMoving;
    bool getIsMoving() const override;
    /// \brief Set the Entity boolean _boosted
    void setBoosted(const bool boosted);
    /// \brief Get the Entity boolean _boosted
    /// \return boolean _boosted
    bool getBoosted() const;

protected:
private:
    int _speed;
    bool _boosted;
};


#endif //ARCADE_PLAYER_HPP
