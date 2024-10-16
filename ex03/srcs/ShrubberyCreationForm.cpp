/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:41:50 by leoherna          #+#    #+#             */
/*   Updated: 2024/10/16 16:41:50 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), Target("Unknown target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), Target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec())
{
	/* Copy every values*/
	//std::cout << "Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->Target = other.Target;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& obj)
{
	os << "ShrubberyCreationForm name :" << obj.getName() << "\nShrubberyCreationForm grade to exec " << obj.getGradeExec() << "\nShrubberyCreationForm grade to sign " << obj.getGradeSign() << "\nShrubberyCreationForm is " << obj.getSign() <<"." << std::flush;
	return os;
}

/*----end of construction------*/

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	if (this->getSign() == "not signed")
	{
        std::cerr << "Form is not signed, cannot execute." << std::endl;
        return;
    }
    std::ofstream file((Target + "_shrubbery").c_str()); // Convert std::string to const char*
    if (file)
    {
        file << "           ccee88oo\n"
                "        C8O8O8Q8PoOb o8oo\n"
                "      dOB69QO8PdUOpugoO9bD\n"
                "     CgggbU8OU qOp qOdoUOdcb\n"
                "         6OuU  /p u gcoUodpP\n"
                "           \\\\//  /douUP\n"
                "             \\\\\\////\n"
                "              |||/\\\n"
                "              |||\\/\n"
                "              |||||\n"
                "        .....//||||\\....\n";
        file.close();
    }
    else 
    {
        std::cerr << "Error: Could not create file." << std::endl;
    }
}

/*
Required grades: sign 145, exec 137
Create a file <target>_shrubbery in the working directory, and writes ASCII trees
inside it.

*/