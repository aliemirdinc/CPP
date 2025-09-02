#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _rawBits(0) {
}

Fixed::Fixed(const int value) {
    _rawBits = value << _fractionalBits;    
}

Fixed::Fixed(const float value) {
    _rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits() const {
    return _rawBits;
}

void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}

float Fixed::toFloat() const{
    return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _rawBits >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->_rawBits > other._rawBits;
}
bool Fixed::operator<(const Fixed& other) const {
    return this->_rawBits < other._rawBits;
}
bool Fixed::operator>=(const Fixed& other) const {
    return this->_rawBits >= other._rawBits;
}
bool Fixed::operator<=(const Fixed& other) const {
    return this->_rawBits <= other._rawBits;
}
bool Fixed::operator==(const Fixed& other) const {
    return this->_rawBits == other._rawBits;
}
bool Fixed::operator!=(const Fixed& other) const {
    return this->_rawBits != other._rawBits;
}



Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}


Fixed& Fixed::operator++() {
    ++_rawBits;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _rawBits++;
    return temp;
}

Fixed& Fixed::operator--() {
    --_rawBits;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _rawBits--;
    return temp;
}


Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
