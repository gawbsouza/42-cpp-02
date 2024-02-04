/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 07:12:17 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/03 21:26:52 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <ostream>

class Fixed
{
private:

    int                 _rawBits;
    static const int    _fracBits;

public:

    Fixed( const Fixed & fixed );
    Fixed( const int value );
    Fixed( const float value );
    Fixed();
    ~Fixed();
    
    static Fixed &  min(Fixed & f1, Fixed & f2);
    static Fixed &  max(Fixed & f1, Fixed & f2);
    static const Fixed &  min(const Fixed & f1, const Fixed & f2);
    static const Fixed &  max(const Fixed & f1, const Fixed & f2);

    int             getRawBits( void ) const ;
    void            setRawBits( int const raw );
    float           toFloat( void ) const;
    int             toInt( void ) const;
    
    Fixed &         operator=( const Fixed & fixed );

    // Comparison operators
    bool            operator>( const Fixed & fixed );
    bool            operator<( const Fixed & fixed );
    bool            operator>=( const Fixed & fixed );
    bool            operator<=( const Fixed & fixed );
    bool            operator==( const Fixed & fixed );
    bool            operator!=( const Fixed & fixed );

    // Atithmetic operadores
    Fixed           operator+( const Fixed & fixed );
    Fixed           operator-( const Fixed & fixed );
    Fixed           operator*( const Fixed & fixed );
    Fixed           operator/( const Fixed & fixed );

    // Increment / Decrement operators
    Fixed           operator++( void ); //PreFix
    Fixed           operator++( int );  //PostFix
    Fixed           operator--( void ); //PreFix
    Fixed           operator--( int );  //PostFix
    
};

std::ostream &  operator<<( std::ostream& out, const Fixed & fixed );

#endif