/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** IDisplay
*/

#ifndef ARCADE_IDISPLAY_HPP
#define ARCADE_IDISPLAY_HPP

#include "IEntity.hpp"
#include <string>

/// \brief represents a generic graphical library
class IGraph {

public:
  /// \brief Destructor
  virtual ~IGraph() = default;

  /// \brief Draw a circle
  /// \param pos the std::pair<float, float> position
  /// \param size the float size
  /// \param color the std::string color name
  /// \return true if the circle is succesfully drawed
  virtual bool drawCircle(std::pair<float, float> pos, float size,
                          std::string color) = 0;

  /// \brief Draw a rectangle
  /// \param pos the std::pair<float, float> position
  /// \param size the float size
  /// \param color the std::string color name
  /// \return true if the rectangle is succesfully drawed
  virtual bool drawRect(std::pair<float, float> pos, float size,
                        std::string color) = 0;

  /// \brief Draw a triangle
  /// \param pos the std::pair<float, float> position
  /// \param size the float size
  /// \param color the std::string color name
  /// \return true if the triangle is succesfully drawed
  virtual bool drawTriangle(std::pair<float, float> pos, float size,
                            std::string color) = 0;

  /// \brief Draw a text
  /// \param pos the std::pair<int, int> position
  /// \param text the std::string to display
  /// \return true if the text is succesfully drawed
  virtual bool drawText(std::pair<float, float> pos,
                        const std::string &text) = 0;

  /// \brief move an entity
  /// \param entity the IEntity position
  /// \param moveVector the std::pair<float, float> move vector
  /// \return true if the entity is succesfully moved
  virtual bool moveEntity(IEntity &entity,
                          std::pair<float, float> moveVector) = 0;

  /// \brief clear the window
  /// \return true if the window is succesfully cleared
  virtual bool clearWindow() = 0;

  /// \brief display the window
  /// \return true if the window is succesfully displayed
  virtual bool displayWindow() = 0;

protected:
private:
};

#endif // ARCADE_IDISPLAY_HPP
