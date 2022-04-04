/*
** EPITECH PROJECT, 2022
** ArcadeCommonInterface
** File description:
** Event
*/

/// \file include/Event.hpp

#ifndef ARCADECOMMONINTERFACE_EVENT_HPP
#define ARCADECOMMONINTERFACE_EVENT_HPP

namespace Arcade {

  /// \brief Represents a generic event interface
  /// this interface is shared across all the graphical libraries
  struct Evt {

    /// \brief data associated with a keyboard event
    /// currently supports only keycode from ascii table
    typedef char Key;

    /// \brief represents the state of a key (pressed or released)
    /// this is used is mouse click events
    typedef bool State;

    /// \brief represents which mouse button was pressed
    enum MouseClick { LEFT, RIGHT, MIDDLE, MOUSE_CLICK_SIZE };

    /// \brief represents the position of the cursor
    /// \todo x, y should be a templated vec2i
    template <typename T> struct MouseMove {
      T x;
      T y;
    };

    /// \brief represents the direction of the mouse wheel scoll
    enum MouseWheel { UP, DOWN, MOUSE_WHEEL_SIZE };

    /// \brief represents the mouse event parameters
    template <typename T> struct MouseEvt {
      T x;
      T y;
      State state;
      MouseClick click;
      MouseWheel wheel;
    };

    /// \brief represents a key modifier (ctrl, shift, alt, etc.)
    enum KeyModifier {
      KEY_MODIFIER_NONE,
      KEY_MODIFIER_SHIFT,
      KEY_MODIFIER_CTRL,
      KEY_MODIFIER_ALT,
      KEY_MODIFIER_SIZE
    };

    /// \brief represents a key event parameters
    struct KeyEvt {
      Key key;
      State state;
      KeyModifier modifier;
    };

    /// \brief represents a the resize event parameters
    template <typename T> struct ResizeEvt {
      T oldSize;
      T newSize;
    };
    /// \brief represents each type of event handled by the core
    enum EvtType {
      WIN_CLOSE,   //< window close event, no data
      WIN_RESIZE,  //< window resize event, data in ResizeEvt
      KEY,         //< key event, data in KeyEvt
      MOUSE_MOVE,  //< mouse move event, data in MouseEvt::(x, y)
      MOUSE_CLICK, //< mouse click event, data in MouseEvt::MouseClick
      MOUSE_WHEEL, //< mouse wheel event, data in MouseEvt::MouseWheel
      EVT_TYPE_SIZE
    };

    /// \brief event type
    EvtType evt_type;

    /// \brief event data
    union {
      /// \brief key event data, see KeyEvt
      KeyEvt key;
      /// \brief mouse event data, see MouseEvt
      MouseEvt<float> mouse;
      /// \brief resize event data, see ResizeEvt
      ResizeEvt<float> resize;
    };
  };
} // namespace Arcade
#endif // ARCADECOMMONINTERFACE_EVENT_HPP
