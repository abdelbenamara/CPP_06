/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 00:37:27 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/11 12:42:28 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) throw() { return; }

Serializer::Serializer(Serializer const & /* src */) throw() { return; }

Serializer::~Serializer(void) throw() { return; }

Serializer &Serializer::operator=(Serializer const & /* rhs */) throw() { return (*this); }

uintptr_t Serializer::serialize(Data *ptr) throw() { return reinterpret_cast<uintptr_t>(ptr); }

Data *Serializer::deserialize(uintptr_t raw) throw() { return reinterpret_cast<Data *>(raw); }
