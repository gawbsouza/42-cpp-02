/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 07:12:17 by gasouza           #+#    #+#             */
/*   Updated: 2024/02/03 18:21:57 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

class Fixed
{
private:

    int                 _rawBits;
    static const int    _fracBits;

public:

    Fixed( const Fixed & fixed );
    Fixed();
    ~Fixed();

    int     getRawBits( void ) const ;
    void    setRawBits( int const raw );
    
    Fixed & operator=( const Fixed & fixed );
};

#endif