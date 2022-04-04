/*
** EPITECH PROJECT, 2022
** arcAAAAAAAAAAAAAAAAade
** File description:
** TextEntity
*/

#ifndef ARCADE_TEXTENTITY_HPP
#define ARCADE_TEXTENTITY_HPP

#include "AEntity.hpp"
#include "Color.hpp"
#include <string>

/// \brief TextEntity class inherits from AEntity
/// \param No param to construct all value by default
class TextEntity : public AEntity {
public:
    /// \brief Constructor
    explicit TextEntity(const std::string &text = "placeholder", const std::string &font = "Resources/Font/ARCADE_N.TTF", const int &fontSize = 14, const Color &color = {255, 255, 255, 255}, const Color &outlineColor = {0, 0, 0, 0});
    /// \brief Destructor
    ~TextEntity();

    /// \brief Get the text
    /// \return the text
    std::string getText() const;

    /// \brief Set the text
    /// \param text the text to set
    void setText(const std::string &text);

    /// \brief Get the font
    /// \return the font
    std::string getFont() const;

    /// \brief Set the font
    /// \param font the font to set
    void setFont(const std::string &font);

    /// \brief Get the font size
    /// \return the font size
    int getFontSize() const;

    /// \brief Set the font size
    /// \param fontSize the font size to set
    void setFontSize(int fontSize);

    /// \brief Set the color
    /// \param color the color to set
    void setColor(const Color &color);

    /// \brief Get the color
    /// \return the color
    Color getColor() const;

    /// \brief Set the outline color
    /// \param outlineColor the outline color to set
    void setOutlineColor(const Color &outlineColor);

    /// \brief Get the outline color
    /// \return the outline color
    Color getOutlineColor() const;

protected:
private:
    std::string _text;
    std::string _fontPath;
    int _fontSize;
    Color _color;
    Color _outlineColor;
};


#endif//ARCADE_TEXTENTITY_HPP
