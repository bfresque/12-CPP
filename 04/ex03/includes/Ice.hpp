/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:14:10 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/11 16:49:48 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "./AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &copy);
		virtual ~Ice();
		Ice& operator=(const Ice& other);
		
		std::string const &	getType() const;
		Ice*				clone() const;
		void				use(ICharacter& target);
};

#endif
