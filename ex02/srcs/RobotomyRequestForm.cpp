/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:11:43 by leoherna          #+#    #+#             */
/*   Updated: 2024/10/16 17:11:43 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), Target("Unknown target")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), Target(target)
{
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)  : AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec())
{
	/* Copy every values*/
	//std::cout << "Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->Target = other.Target;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& obj)
{
	os << "RobotomyRequestForm name :" << obj.getName() << "\nRobotomyRequestForm grade to exec " << obj.getGradeExec() << "\nRobotomyRequestForm grade to sign " << obj.getGradeSign() << "\nRobotomyRequestForm is " << obj.getSign() <<"." << std::flush;
	return os;
}

/*----end of construction------*/

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	static int random = 0;
	if (this->getSign() == "not signed")
	{
        std::cerr << "Form is not signed, cannot execute." << std::endl;
        return;
    }
	if (random % 2)
	{
		std::cout << Target << " has been robotomized" << std::endl;
	}
	else
	{
		std::cout << Target << "'s robotomy failed" << std::endl;
	}
	random++;
}
