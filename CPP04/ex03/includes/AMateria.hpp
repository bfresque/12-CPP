/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:07:43 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/11 17:21:06 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "./ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(const std::string & type);
		AMateria(const AMateria& rhs);
		virtual ~AMateria();
		
		AMateria& operator=(const AMateria &other);
		
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
