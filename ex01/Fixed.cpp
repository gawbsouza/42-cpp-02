/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 07:16:35 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/03 18:49:22 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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

Fixed::Fixed( const float value )
{
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(value * (1 << this->_fracBits));
}

Fixed::Fixed( const int value )
{
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = value << this->_fracBits;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

// Methods

int Fixed::getRawBits( void ) const
{
    return this->_rawBits;
}

void Fixed::setRawBits( int const raw )
{
    this->_rawBits = raw;
}

float Fixed::toFloat( void ) const
{
    return this->_rawBits / (float)(1 << this->_fracBits);
}

int Fixed::toInt( void ) const
{
    return this->_rawBits >> this->_fracBits;
}

// Operators

Fixed & Fixed::operator=( const Fixed & fixed )
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_rawBits = fixed.getRawBits();
    return *this;
}

std::ostream &  operator<<( std::ostream& out, const Fixed & fixed ) {
	return out << fixed.toFloat();
}
