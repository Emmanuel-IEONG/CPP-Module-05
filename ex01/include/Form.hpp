/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:08:21 by eieong            #+#    #+#             */
/*   Updated: 2025/11/28 18:14:20 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
	#define FORM_HPP
	#include <iostream>
	#include <string>

	class	Form
	{
		private:
			const std::string	_name;
			bool				_signed;
			const int			_grade_to_sign;
			const int			_grade_to_execute;
		public:
			Form();
			Form(Form const & src);
			~Form();
			Form &	operator=(Form const & rhs);
	};

#endif
