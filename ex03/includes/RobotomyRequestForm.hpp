/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:12:08 by leoherna          #+#    #+#             */
/*   Updated: 2024/10/16 17:12:08 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string Target;
	public:
		
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		/*----end of construction ----*/

		virtual void execute(Bureaucrat const &executor) const;
};