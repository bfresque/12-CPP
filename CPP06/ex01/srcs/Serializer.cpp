/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:10:23 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/10 17:01:22 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) { *this = other; }

Serializer &Serializer::operator=(const Serializer &other) { (void)other; return (*this); }

Serializer::~Serializer() {}

void* Serializer::serialize(Data* ptr) { return static_cast<void*>(ptr); }

Data* Serializer::deserialize(void* raw) { return static_cast<Data*>(raw); }