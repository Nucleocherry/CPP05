/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:17:38 by leoherna          #+#    #+#             */
/*   Updated: 2024/10/16 14:17:38 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Form
{
	private:

		const std::string name;

		bool is_signed;

		const int grade_to_sign;
		const int grade_to_exec;

	public:

		Form();
		/*--fonction pour check les const value pour le constructeur----*/
		int checkSign(int sign);
		int checkExec(int exec);
		/*-------------------------------------------*/

		Form(const std::string name_given, int sign, int exec);
		~Form();

		Form(const Form& copy);
		Form &operator=(const Form &other);
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
};

std::ostream& operator<<(std::ostream& os, const Form& obj);


