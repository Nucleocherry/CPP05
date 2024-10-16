/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:13:48 by leoherna          #+#    #+#             */
/*   Updated: 2024/10/16 13:13:48 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:
		Bureaucrat(/* args */);
		~Bureaucrat();

		Bureaucrat(const std::string name_given, int grade_given);

		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat &operator=(const Bureaucrat &other);
		Bureaucrat &operator++();
		Bureaucrat &operator--();
		Bureaucrat operator++(int);
		Bureaucrat operator--(int);
		/*---end of construction--*/


		class GradeTooHighException : public std::exception
		{
			public :
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
			const char* what() const throw();
		};
		/*---end of exception---*/

		int getGrade(void) const;
		const std::string getName(void) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
