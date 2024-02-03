/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 07:16:35 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/03 18:22:43 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// Constructors

const int Fixed::_fracBits = 8;

Fixed::Fixed( void )
{
    std::cout << "Default constructor called" << std::endl;
    this->_rawBits = 0;
}

Fixed::Fixed( const Fixed & fixed )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

// Methods

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_rawBits = raw;
}

// Operators

Fixed & Fixed::operator=( const Fixed & fixed )
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_rawBits = fixed.getRawBits();
    return *this;
}