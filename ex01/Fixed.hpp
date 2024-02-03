/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 07:12:17 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/03 10:27:39 by gasouza          ###   ########.fr       */
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

    int             getRawBits( void ) const ;
    void            setRawBits( int const raw );
    float           toFloat( void ) const;
    int             toInt( void ) const;
    
    Fixed &         operator=( const Fixed & fixed );
};

std::ostream &  operator<<( std::ostream& out, const Fixed & fixed );

#endif