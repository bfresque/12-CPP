/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:06:07 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/06 13:05:12 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string in = av[1];
		std::string out = in + ".replace";
		std::string s1 = av[2];
		std::string s2 = av[3];
		std::ifstream inFile;
		std::ofstream outFile;
		std::string line;
		size_t position;

		inFile.open(in);
		outFile.open(out);
		if (!inFile || !outFile)
			return (-1);
		while(std::getline(inFile, line))
		{
			position = line.find(av[2]);
			if (position != std::string::npos)
			{
				line.erase(position, s1.length());
				line.insert(position, s2);
			}
			outFile << line << "\n";
		}
		outFile.close();
		inFile.close();
		return (0);
	}
	std::cout << "4 arguments are required" << std::endl;
	return (0);
}
