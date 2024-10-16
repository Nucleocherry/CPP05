/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:18:03 by leoherna          #+#    #+#             */
/*   Updated: 2024/10/16 14:18:03 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

Form::Form() :  name("unknown"), is_signed(false), grade_to_sign(150), grade_to_exec(150)
{

}
/*--fonction pour check les const value pour le constructeur----*/
int Form::checkExec(int exec)
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

int Form::checkSign(int sign)
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

Form::Form(const std::string name_given, int sign, int exec) : name(name_given), is_signed(false), grade_to_sign(checkSign(sign)), grade_to_exec(checkExec(exec))
{

}

Form::~Form()
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

Form::Form(const Form& copy)
 : name(copy.name), is_signed(copy.is_signed), grade_to_sign(copy.grade_to_sign), grade_to_exec(copy.grade_to_exec)
{
	/* Copy every values*/
	//std::cout << "Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->is_signed = other.is_signed;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << "form name :" << obj.getName() << "\nform grade to exec " << obj.getGradeExec() << "\nform grade to sign " << obj.getGradeSign() << "\nform is " << obj.getSign() <<"." << std::flush;
	return os;
}

/*------end of construction-----*/

int Form::getGradeExec(void) const
{
	return (grade_to_exec);
}

int Form::getGradeSign(void) const
{
	return (grade_to_sign);
}

const std::string Form::getName(void) const
{
	return (name);
}

const std::string Form::getSign(void) const
{
	if (this->is_signed)
		return ("signed");
	return ("not signed");
}

/*-----end of gettters---*/

void Form::beSigned()
{
	if (!is_signed)
		is_signed = true;
	else
		std::cout << name << " is already signed" << std::endl;
}

