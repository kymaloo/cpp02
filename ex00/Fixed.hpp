/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 23:40:18 by trgaspar          #+#    #+#             */
/*   Updated: 2025/04/02 16:24:03 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
    	int                 _value;
    	static const int    _fractionalBits = 2;
	public:
    	Fixed(void);
		Fixed(const Fixed &cpy);
		Fixed &operator=(const Fixed &op);
    	~Fixed(void);
    	int getRawBits(void) const;
	    void setRawBits(int const raw);
};

