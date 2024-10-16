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
#include "Intern.hpp"

int main()
{

	// Bureaucrat jacque("jacque", 2);

	// ShrubberyCreationForm document("shishou");

	// std::cout << jacque++ << std::endl;
	// std::cout << jacque << std::endl;

	// std::cout << document << std::endl;
	// jacque.signForm(&document);
	// std::cout << document << std::endl;

	// jacque.executeForm(document);

	Intern someRandomIntern;
	Bureaucrat jacque("jacque", 2);

	AForm* rrf[2];

	rrf[0] = someRandomIntern.makeForm("robotomy request", "Bender");
	jacque.signForm(rrf[0]);
	rrf[0]->execute(jacque);
	rrf[0]->execute(jacque);

	std::cout << "\n\n" << std::endl;

	rrf[1] = someRandomIntern.makeForm("Presidential pardon", "Shiraz");
	jacque.signForm(rrf[1]);
	rrf[1]->execute(jacque);
	rrf[1]->execute(jacque);


	delete rrf[0];
	delete rrf[1];

}
