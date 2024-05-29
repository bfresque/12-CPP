/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:10:23 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/10 18:02:33 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) { *this = other; }

Serializer &Serializer::operator=(const Serializer &other) { (void)other; return (*this); }

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) { return (reinterpret_cast<uintptr_t>(ptr)); }

Data* Serializer::deserialize(uintptr_t raw) { return (reinterpret_cast<Data*>(raw)); }