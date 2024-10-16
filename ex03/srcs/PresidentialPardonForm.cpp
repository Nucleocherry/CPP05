/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:19:02 by leoherna          #+#    #+#             */
/*   Updated: 2024/10/16 17:19:02 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), Target("Unknown target")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), Target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec())
{
	/* Copy every values*/
	//std::cout << "Copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->Target = other.Target;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& obj)
{
	os << "PresidentialPardonForm name :" << obj.getName() << "\nPresidentialPardonForm grade to exec " << obj.getGradeExec() << "\nPresidentialPardonForm grade to sign " << obj.getGradeSign() << "\nPresidentialPardonForm is " << obj.getSign() <<"." << std::flush;
	return os;
}

/*----end of construction------*/

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	if (this->getSign() == "not signed")
	{
        std::cerr << "Form is not signed, cannot execute." << std::endl;
        return;
    }
	std::cout << Target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
