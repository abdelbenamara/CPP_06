/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 00:49:36 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/11 01:33:16 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(void)
{
	Data data;
	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);

	data.id = 1234567890;
	data.name = "Toto";
	data.initial = data.name.at(0);

	std::cout << "Info: &data: " << std::hex << &data << std::endl;
	std::cout << "Info: Serializer::serialize(data): raw: 0x" << raw << std::endl;
	std::cout << "Info: Serializer::deserialize(raw): ptr: " << ptr << std::dec << std::endl;
	std::cout << "Info: data.id: " << data.id << ", data.name: " << data.name << ", data.initial: " << data.initial << std::endl;
	std::cout << "Info: ptr->id: " << ptr->id << ", ptr->name: " << ptr->name << ", ptr->initial: " << ptr->initial << std::endl;

	return (0);
}
