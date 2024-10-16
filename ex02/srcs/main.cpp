/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:13:33 by leoherna          #+#    #+#             */
/*   Updated: 2024/10/16 13:13:33 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{

	Bureaucrat jacque("jacque", 2);

	ShrubberyCreationForm document("shishou");

	std::cout << jacque++ << std::endl;
	std::cout << jacque << std::endl;

	std::cout << document << std::endl;
	jacque.signForm(&document);
	std::cout << document << std::endl;

	jacque.executeForm(document);

}
