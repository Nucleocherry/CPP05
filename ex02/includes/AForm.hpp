/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:17:38 by leoherna          #+#    #+#             */
/*   Updated: 2024/10/16 14:17:38 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class AForm
{
	private:

		const std::string name;

		bool is_signed;

		const int grade_to_sign;
		const int grade_to_exec;

	public:

		AForm();
		/*--fonction pour check les const value pour le constructeur----*/
		int checkSign(int sign);
		int checkExec(int exec);
		/*-------------------------------------------*/

		AForm(const std::string name_given, int sign, int exec);
		virtual ~AForm();

		AForm(const AForm& copy);
		AForm &operator=(const AForm &other);
		/*-----end of construction---*/

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
		/*------end of exception------*/

		int getGradeExec(void) const;
		int getGradeSign(void) const;
		const std::string getSign(void) const;
		const std::string getName(void) const;
		/*-----end of getters----*/
		void beSigned(void);
		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);


