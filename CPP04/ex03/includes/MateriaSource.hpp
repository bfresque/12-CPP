/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:16:21 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/11 17:05:05 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAS_HPP
# define MATERIAS_HPP

# include "./AMateria.hpp"
# include "./IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_inventory[4];
		int			_nbMateria;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		virtual ~MateriaSource();
		AMateria*	createMateria(std::string const & type);
		void		learnMateria(AMateria* newMateria);
};

#endif
