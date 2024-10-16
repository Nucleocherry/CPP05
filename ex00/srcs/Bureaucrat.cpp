/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:12:41 by leoherna          #+#    #+#             */
/*   Updated: 2024/10/16 13:12:41 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

Bureaucrat::Bureaucrat() : name("Unknown"), grade(150)
{
	return ;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

Bureaucrat::Bureaucrat(const std::string name_given, int grade_given) : name(name_given)
{
	try 
	{
		if (grade_given >= 151)
			throw GradeTooLowException();
	}
	catch (const GradeTooLowException &e)
	{
		std::cerr << e.what() <<std::endl;
	}
	try 
	{
		if (grade_given <= 0)
        	throw GradeTooHighException();
	}
	catch (const GradeTooHighException &e)
	{
		std::cerr << e.what() <<std::endl;
	}
	this->grade = grade_given;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name), grade(copy.grade)
{
	/* Copy every values*/
	//std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat &Bureaucrat::operator++()
{

    if (this->grade <= 1)
        throw GradeTooHighException();
    this->grade--;
    return *this;
}

Bureaucrat &Bureaucrat::operator--()
{
    if (this->grade >= 150)
        throw GradeTooLowException();
    this->grade++;
    return *this;
}
Bureaucrat Bureaucrat::operator++(int)
{
    Bureaucrat temp = *this;
    if (this->grade <= 1)
        throw GradeTooHighException();
    this->grade--;
    return temp;
}

Bureaucrat Bureaucrat::operator--(int)
{
    Bureaucrat temp = *this;
    if (this->grade >= 150)
        throw GradeTooLowException();
    this->grade++;
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << " , bureaucrat grade " << obj.getGrade() << "." << std::flush;
	return os;
}

/*----------end of construction-------*/

int Bureaucrat::getGrade(void) const
{
	return (grade);
}

const std::string Bureaucrat::getName(void) const
{
	return (name);
}
