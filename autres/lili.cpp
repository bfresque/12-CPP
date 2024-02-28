#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	_n;
		static const int _value = 8;
	public:
		Fixed();
		Fixed(const int integerNum);
		Fixed(const float floatNum);
		Fixed(const Fixed &copy);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();
		int		toInt(void) const;
		float	toFloat(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fi);

#endif

Fixed::Fixed() // constructeur par defaut
{
	this->_n = 0;
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::~Fixed() // destructeur par defaut
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed &copy)  // constructeur de copy
{
	std::cout << "Copy constructor called" << std::endl;
	this->_n = copy.getRawBits();
	return;
}

Fixed::Fixed(const int integerNum) // constructeur de int
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(integerNum << this->_value);
	return;
}

Fixed::Fixed(const float floatNum) // constructeur de float
{
	std::cout << "Float constructor called" << std::endl;
	int twoPower = 1 << this->_value;
	int rawValue = (int)roundf(floatNum * twoPower);
	this->setRawBits(rawValue);
	return;
}

int	Fixed::toInt(void) const
{
	return (getRawBits() >> _value);
}

float	Fixed::toFloat( void ) const
{
	return (this->_n / pow(2, this->_value));
}

int	Fixed::getRawBits(void) const
{
	return(this->_n);
}

void	Fixed::setRawBits(const int raw)
{
	this->_n = raw;
	return;
}

std::ostream &operator<<(std::ostream &o, Fixed const &f)
{
	return (o << f.toFloat());
}
