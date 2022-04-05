/*
** EPITECH PROJECT, 2022
** Color.hpp.h
** File description:
** Created by hjulien,
*/

#ifndef ARCADE_COLOR_HPP
#define ARCADE_COLOR_HPP

/// \brief Color structure
struct Color {
        enum TermColors {
            BLACK = 0,
            RED = 1,
            GREEN = 2,
            YELLOW = 3,
            BLUE = 4,
            MAGENTA = 5,
            CYAN = 6,
            WHITE = 7,
        };

        /// \brief Default Constructor
        Color() = default;

        /// \brief Constructor with R, G, B, A params
        /// \param R Amount of Red on a scale of 0 to 255
        /// \param G Amount of Green on a scale of 0 to 255
        /// \param B Amount of Blue on a scale of 0 to 255
        /// \param A Amount of Alpha of the color on a scale of 0 to 255. It represents the opacity of the color
        /// \param TF The foreground color for terminal graphical libraries
        /// \param TB The background color for terminal graphical libraries
        Color(int r, int g, int b, int a, TermColors tf = TermColors::WHITE, TermColors tb = TermColors::BLACK) : R(r), G(g), B(b), A(a), TF(tf), TB(tb) {};

        /// \brief Default Destructor
        ~Color() = default;

        /// \brief Red amount on a scale of 0 to 255
        int R;
        /// \brief Green amount on a scale of 0 to 255
        int G;
        /// \brief Blue amount on a scale of 0 to 255
        int B;
        /// \brief Alpha amount on a scale of 0 to 255
        int A;
        /// \brief Foreground color for terminal graphical libraries
        TermColors TF;
        /// \brief Background color for terminal graphical libraries
        TermColors TB;
};


#endif//ARCADE_COLOR_HPP
