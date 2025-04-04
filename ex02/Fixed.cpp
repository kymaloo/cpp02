/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 23:40:13 by trgaspar          #+#    #+#             */
/*   Updated: 2025/04/04 16:07:39 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor
Fixed::Fixed(void) : _value(0){
}

Fixed::Fixed(const Fixed &cpy)
{
	*this = cpy;
}

Fixed::Fixed(const int nb)
{
	_value = nb << _fractionalBits;
}

Fixed::Fixed(const float nb)
{
	_value = roundf(nb * (1 << _fractionalBits));
}

// Destructor
Fixed::~Fixed(void){
}

// Surcharge operator comparaison
Fixed &Fixed::operator=(const Fixed &op)
{
	_value = op._value;
	return (*this);
}

bool Fixed::operator>(const Fixed &op)
{
 	if (_value > op._value)
		return (true);
    return (false);
}

bool Fixed::operator<(const Fixed &op)
{
	if (_value < op._value)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &op)
{
	if (_value <= op._value)
		return (true);
	return (false);
}
bool Fixed::operator>=(const Fixed &op)
{
	if (_value >= op._value)
		return (true);
	return (false);
}
bool Fixed::operator==(const Fixed &op)
{
	if (_value == op._value)
		return (true);
	return (false);
}
bool Fixed::operator!=(const Fixed &op)
{
	if (_value != op._value)
		return (true);
	return (false);
}
// Surcharge operator arithmetique
float Fixed::operator+(const Fixed &op)
{
	return ((float)_value / (float)(1 << _fractionalBits) + (float)op._value / (float)(1 << _fractionalBits));
}

float Fixed::operator-(const Fixed &op)
{
	return ((float)_value / (float)(1 << _fractionalBits) - (float)op._value / (float)(1 << _fractionalBits));
}

float Fixed::operator*(const Fixed &op)
{
	return ((float)_value / (float)(1 << _fractionalBits) * (float)op._value / (float)(1 << _fractionalBits));
}

float Fixed::operator/(const Fixed &op)
{
	if (op._value == 0)
    {
        std::cout << "Divide by 0" << std::endl;
    	return (1);
    }
	return ((float)_value / (float)(1 << _fractionalBits) / (float)op._value / (float)(1 << _fractionalBits));
}
// Surcharge operator incrementation et decrementation
//void Fixed::operator++(const Fixed &op)
//{
//	_value =
//}

// Surcharge operator <<
std::ostream &operator<<(std::ostream &os, const Fixed &fd)
{
	os << fd.toFloat();
	return (os);
}

// Getter/Setter
int	Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

// Convertion
int Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (float)(1 << _fractionalBits));
}

