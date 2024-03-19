/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:05:22 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/18 11:15:56 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
// #include "../includes/Bureaucrat.hpp"

int main()
{
	Bureaucrat john("John Doe", 50);
	Form taxReturn("Tax Return", 75, 50); // Easier to sign
	Form topSecret("Top Secret", 25, 5); // Harder to sign

	// std::cout << john << std::endl;
	// std::cout << taxReturn << std::endl;
	// std::cout << topSecret << std::endl;


	// John should be able to sign this
	john.signForm(taxReturn);

	// John should not be able to sign this
	john.signForm(topSecret);

	return 0;
}



// int main() {
// 	try
// 	{
// 		Bureaucrat john("John Doe", 50);
// 		Form taxForm("1040EZ Tax Form", 45, 25); // Nécessite un grade plus élevé pour signer
// 		std::cout << john << std::endl;
// 		std::cout << taxForm << std::endl;

// 		john.signForm(taxForm); // Essaie de signer le formulaire
// 		std::cout << taxForm << std::endl; // Vérifie si le formulaire a été signé
// 	}
// 	catch (std::exception& e)
// 	{
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}

// 	try
// 	{
// 		Bureaucrat jane("Jane Smith", 1);
// 		Form secretProject("Classified Project X", 1, 1); // Nécessite le grade le plus élevé pour signer
// 		std::cout << jane << std::endl;
// 		std::cout << secretProject << std::endl;

// 		jane.signForm(secretProject); // Jane peut signer n'importe quel formulaire
// 		std::cout << secretProject << std::endl; // Vérifie si le formulaire a été signé
// 	}
// 	catch (std::exception& e)
// 	{
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}

// 	try
// 	{
// 		Bureaucrat newbie("Newbie", 150); // Le grade le plus bas possible
// 		Form impossibleForm("Mission Impossible", 1, 1); // Nécessite le grade le plus élevé pour signer
// 		std::cout << newbie << std::endl;
// 		std::cout << impossibleForm << std::endl;

// 		newbie.signForm(impossibleForm); // Newbie ne peut pas signer ce formulaire
// 	}
// 	catch (std::exception& e)
// 	{
// 		std::cerr << "Could not sign form: " << e.what() << std::endl;
// 	}

// 	return (0);
// }
