/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:16:23 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/11 16:46:30 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "./AMateria.hpp"
# include "./ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];
		int			_nbMateria; // Pour suivre le nb actuel d'objets dans l'inventaire

	public:
		Character();
		Character(std::string name);
		Character(const Character &copy);
		~Character();

		Character&		operator=(const Character &other);
		std::string const & getName() const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
		
};

#endif
