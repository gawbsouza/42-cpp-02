/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 07:16:35 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/03 21:28:52 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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

Fixed &  Fixed::min(Fixed & f1, Fixed & f2)
{
    return f1.getRawBits() <= f2.getRawBits() ? f1 : f2;
}

Fixed &  Fixed::max(Fixed & f1, Fixed & f2)
{
    return f1.getRawBits() >= f2.getRawBits() ? f1 : f2;
}

const Fixed &  Fixed::min(const Fixed & f1, const Fixed & f2)
{
    return f1.getRawBits() <= f2.getRawBits() ? f1 : f2;
}

const Fixed &  Fixed::max(const Fixed & f1, const Fixed & f2)
{
    return f1.getRawBits() >= f2.getRawBits() ? f1 : f2;
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

// Comparison Operators

bool Fixed::operator>( const Fixed & fixed )
{
    return this->_rawBits > fixed.getRawBits();
}

bool Fixed::operator<( const Fixed & fixed )
{
   return this->_rawBits < fixed.getRawBits();
}

bool Fixed::operator>=( const Fixed & fixed )
{
    return this->_rawBits >= fixed.getRawBits();
}

bool Fixed::operator<=( const Fixed & fixed )
{
    return this-> _rawBits <= fixed.getRawBits();
}

bool Fixed::operator==( const Fixed & fixed )
{
    return this->_rawBits == fixed.getRawBits();
}

bool Fixed::operator!=( const Fixed & fixed )
{
    return this->_rawBits != fixed.getRawBits();
}

// Arithmetic Operators
Fixed Fixed::operator+( const Fixed & fixed )
{
    Fixed result;
    result.setRawBits(this->getRawBits() + fixed.getRawBits());
    return result;
}

Fixed Fixed::operator-( const Fixed & fixed )
{
    Fixed result;
    result.setRawBits(this->getRawBits() - fixed.getRawBits());
    return result;
}

Fixed Fixed::operator*( const Fixed & fixed )
{
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/( const Fixed & fixed )
{
    return Fixed(this->toFloat() / fixed.toFloat());
}

// Increment / Decrement operators
Fixed Fixed::operator++( void )
{
    ++this->_rawBits;
    return *this;
}

Fixed Fixed::operator++( int )
{
    Fixed old = *this;
    ++this->_rawBits;
    return old;
}

Fixed Fixed::operator--( void )
{
    --this->_rawBits;
    return *this;
}

Fixed Fixed::operator--( int )
{
    Fixed old = *this;
    --this->_rawBits;
    return old;
}