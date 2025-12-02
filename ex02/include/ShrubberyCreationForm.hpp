/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:44:18 by eieong            #+#    #+#             */
/*   Updated: 2025/12/02 12:04:17 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
	#define SHRUBBERYCREATIONFORM_HPP
	#include <iostream>
	#include "AForm.hpp"

	class	ShrubberyCreationForm : public AForm
	{
		public:
			ShrubberyCreationForm();
			ShrubberyCreationForm(ShrubberyCreationForm const & src);
			ShrubberyCreationForm(const std::string name);
			~ShrubberyCreationForm();
			ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);
	};

#endif
