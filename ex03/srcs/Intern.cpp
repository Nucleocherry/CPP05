/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:02:14 by leoherna          #+#    #+#             */
/*   Updated: 2024/10/16 19:02:14 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	return ;
}

Intern::~Intern()
{
	return ;
}

/*---- end of construction----*/

typedef AForm* (*FormCreator)(std::string target);

AForm* createPresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* createRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* createShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string type, std::string target)
{
    static std::map<std::string, FormCreator> formMap;

    if (formMap.empty())
	{
        formMap["presidential pardon"] = createPresidentialPardonForm;
        formMap["robotomy request"] = createRobotomyRequestForm;
        formMap["shrubbery creation"] = createShrubberyCreationForm;
    }

    std::map<std::string, FormCreator>::iterator it = formMap.find(type);
    if (it != formMap.end())
	{
        std::cout << "Intern creates " << type << std::endl;
        return it->second(target);
    }
    std::cout << "Invalid form type" << std::endl;
    return NULL;
}
