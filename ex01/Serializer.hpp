/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 00:36:35 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/11 12:33:14 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER__HPP__
#define __SERIALIZER__HPP__

#include <stdint.h>
#include <string>

typedef struct s_data
{
	int id;
	std::string name;
	char initial;
} Data;

class Serializer
{
public:
	static uintptr_t serialize(Data *ptr) throw();
	static Data *deserialize(uintptr_t raw) throw();

private:
	Serializer(void) throw();
	Serializer(Serializer const & /* src */) throw();
	virtual ~Serializer(void) throw();

	Serializer &operator=(Serializer const & /* rhs */) throw();
};

#endif
