/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:18:03 by leoherna          #+#    #+#             */
/*   Updated: 2024/10/16 14:18:03 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

AForm::AForm() :  name("unknown"), is_signed(false), grade_to_sign(150), grade_to_exec(150)
{

}
/*--fonction pour check les const value pour le constructeur----*/
int AForm::checkExec(int exec)
{
	if (exec < 1)
	{
		throw GradeTooHighException();
	}
    if (exec > 150)
	{
		throw GradeTooLowException();
	}
	return (exec);
}

int AForm::checkSign(int sign)
{
	if (sign < 1)
	{
		throw GradeTooHighException();
	}
    if (sign > 150)
	{
		throw GradeTooLowException();
	}
	return (sign);
}
/*-------------------------------------------*/

AForm::AForm(const std::string name_given, int sign, int exec) : name(name_given), is_signed(false), grade_to_sign(checkSign(sign)), grade_to_exec(checkExec(exec))
{

}

AForm::~AForm()
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

AForm::AForm(const AForm& copy)
 : name(copy.name), is_signed(copy.is_signed), grade_to_sign(copy.grade_to_sign), grade_to_exec(copy.grade_to_exec)
{
	/* Copy every values*/
	//std::cout << "Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->is_signed = other.is_signed;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << "AForm name :" << obj.getName() << "\nAForm grade to exec " << obj.getGradeExec() << "\nAForm grade to sign " << obj.getGradeSign() << "\nAForm is " << obj.getSign() <<"." << std::flush;
	return os;
}

/*------end of construction-----*/

int AForm::getGradeExec(void) const
{
	return (grade_to_exec);
}

int AForm::getGradeSign(void) const
{
	return (grade_to_sign);
}

const std::string AForm::getName(void) const
{
	return (name);
}

const std::string AForm::getSign(void) const
{
	if (this->is_signed)
		return ("signed");
	return ("not signed");
}

/*-----end of gettters---*/

void AForm::beSigned()
{
	if (!is_signed)
		is_signed = true;
	else
		std::cout << name << " is already signed" << std::endl;
}

// void AForm::execute(Bureaucrat const &executor)
// {
// 	return ;
// }
