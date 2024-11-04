/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:07:09 by brandebr          #+#    #+#             */
/*   Updated: 2024/10/28 13:04:29 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator {
	private:

		TargetGenerator(const TargetGenerator &);
		TargetGenerator &operator=(const TargetGenerator &);
		std::map<std::string, ATarget *> _arr;

	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *);
		void forgetTargetType(const std::string type);
		ATarget *createTarget(std::string const &);
};

