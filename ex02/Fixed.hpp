/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 23:40:18 by trgaspar          #+#    #+#             */
/*   Updated: 2025/04/03 15:22:23 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
	private:
    	int                 _value;
    	static const int    _fractionalBits = 8;
	public:
        // Constructor
    	Fixed(void);
		Fixed(const Fixed &cpy);
		Fixed(const int nb);
		Fixed(const float nb);
       	// Destructor
		~Fixed(void);
        // Surcharge operator comparaison
		Fixed &operator=(const Fixed &op);
		bool operator>(const Fixed &op);
		bool operator<(const Fixed &op);
		bool operator<=(const Fixed &op);
		bool operator>=(const Fixed &op);
		bool operator==(const Fixed &op);
		bool operator!=(const Fixed &op);
		// Surcharge operator arithmetique
		float operator+(const Fixed &op);
		float operator-(const Fixed &op);
		float operator*(const Fixed &op);
		float operator/(const Fixed &op);
		// Surcharge operator incrementation et decrementation
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);
        // Surcharge operator <<
		friend std::ostream &operator<<(std::ostream& os, const Fixed& fd);
    	// Getter/Setter
    	int getRawBits(void) const;
	    void setRawBits(int const raw);
        // Convertion
		float toFloat(void) const;
		int toInt(void) const;
        // Min/Max
		static const Fixed &min(const Fixed &op1, const Fixed &op2);
		static Fixed &min(Fixed &op1, Fixed &op2);
		static const Fixed &max(const Fixed &op1, const Fixed &op2);
		static Fixed &max(Fixed &op1, Fixed &op2);
};