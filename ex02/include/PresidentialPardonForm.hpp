/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:46:41 by eieong            #+#    #+#             */
/*   Updated: 2025/12/02 12:08:52 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
	#define PRESIDENTIALPARDONFORM_HPP
	#include <iostream>
	#include "AForm.hpp"

	class	PresidentialPardonForm : public AForm
	{
		public:
			PresidentialPardonForm();
			PresidentialPardonForm(PresidentialPardonForm const & src);
			PresidentialPardonForm(const std::string name);
			~PresidentialPardonForm();
			PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);
	};

#endif
