/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:45 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/05 12:39:51 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>

class Array
{
	private:
		T*				_elements;
		unsigned int	_n;

	public:
		Array();
		Array(unsigned int size);
		Array(const Array& other);
		~Array();
		Array& operator=(const Array& other);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int size() const;
};

template<typename T>
Array<T>::Array() : _elements(nullptr), _n(0) {}

template<typename T>
Array<T>::Array(unsigned int size) : _elements(new T[size]), _n(size) {}

template<typename T>
Array<T>::Array(const Array<T>& other) : _elements(new T[other._n]), _n(other._n)
{
	for (unsigned int i = 0; i < _n; ++i)
		_elements[i] = other._elements[i];
}


template<typename T>
Array<T>::~Array()
{
	delete[] _elements;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[] _elements;
		_n = other._n;
		_elements = new T[_n];
		for (unsigned int i = 0; i < _n; ++i)
			_elements[i] = other._elements[i];
	}
	return (*this);
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _n)
		throw std::exception();
	return _elements[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _n)
		throw std::exception();
	return (_elements[index]);
}

template<typename T>
unsigned int Array<T>::size() const
{
	return (_n);
}

#endif
