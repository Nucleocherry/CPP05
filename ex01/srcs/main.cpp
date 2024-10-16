/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:13:33 by leoherna          #+#    #+#             */
/*   Updated: 2024/10/16 13:13:33 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Form	document("Impot", 150, 150);
	Bureaucrat jacque("jacque", 11);
	std::cout << jacque++ << std::endl;
	std::cout << jacque << std::endl;

	std::cout << document << std::endl;
	jacque.signForm(&document);
	std::cout << document << std::endl;

}
