/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:07:43 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/12 09:40:42 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# define RED			"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define BOLD_WHITE	"\033[1;37m"
# define RESET		"\033[0m"

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
