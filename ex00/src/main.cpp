/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:04:20 by eieong            #+#    #+#             */
/*   Updated: 2025/11/28 12:31:25 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int	main()
{
	Bureaucrat	*a = new Bureaucrat();
	std::cout << a;
	a->decrementGrade();
	std::cout << a;
	delete a;
	return (0);
}
