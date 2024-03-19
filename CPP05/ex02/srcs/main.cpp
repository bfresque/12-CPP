/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:05:22 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/19 11:23:14 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
// #include "../includes/Bureaucrat.hpp"

int main()
{
	Bureaucrat john("John Doe", 50);
	AForm taxReturn("Tax Return", 75, 50); // Easier to sign
	AForm topSecret("Top Secret", 25, 5); // Harder to sign

	// std::cout << john << std::endl;
	// std::cout << taxReturn << std::endl;
	// std::cout << topSecret << std::endl;


	// John should be able to sign this
	john.signAForm(taxReturn);

	// John should not be able to sign this
	john.signAForm(topSecret);

	return 0;
}



// int main() {
// 	try
// 	{
// 		Bureaucrat john("John Doe", 50);
// 		AForm taxAForm("1040EZ Tax AForm", 45, 25); // Nécessite un grade plus élevé pour signer
// 		std::cout << john << std::endl;
// 		std::cout << taxAForm << std::endl;

// 		john.signAForm(taxAForm); // Essaie de signer le AFormulaire
// 		std::cout << taxAForm << std::endl; // Vérifie si le AFormulaire a été signé
// 	}
// 	catch (std::exception& e)
// 	{
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}

// 	try
// 	{
// 		Bureaucrat jane("Jane Smith", 1);
// 		AForm secretProject("Classified Project X", 1, 1); // Nécessite le grade le plus élevé pour signer
// 		std::cout << jane << std::endl;
// 		std::cout << secretProject << std::endl;

// 		jane.signAForm(secretProject); // Jane peut signer n'importe quel AFormulaire
// 		std::cout << secretProject << std::endl; // Vérifie si le AFormulaire a été signé
// 	}
// 	catch (std::exception& e)
// 	{
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}

// 	try
// 	{
// 		Bureaucrat newbie("Newbie", 150); // Le grade le plus bas possible
// 		AForm impossibleAForm("Mission Impossible", 1, 1); // Nécessite le grade le plus élevé pour signer
// 		std::cout << newbie << std::endl;
// 		std::cout << impossibleAForm << std::endl;

// 		newbie.signAForm(impossibleAForm); // Newbie ne peut pas signer ce AFormulaire
// 	}
// 	catch (std::exception& e)
// 	{
// 		std::cerr << "Could not sign AForm: " << e.what() << std::endl;
// 	}

// 	return (0);
// }
