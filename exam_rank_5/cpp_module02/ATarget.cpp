/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:11:49 by brandebr          #+#    #+#             */
/*   Updated: 2024/10/28 12:03:59 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget(const std::string &type) : _type(type) {}

ATarget::~ATarget() {}

ATarget &ATarget::operator=(const ATarget &cpy) {
	this->_type = cpy._type;
	return *this;
}

ATarget::ATarget(const ATarget &cpy) {
	*this = cpy;
}

const std::string &ATarget::getType() const { return this->_type; }

void ATarget::getHitBySpell(const ASpell &name) const {
	std::cout << this->_type << " has been " << name.getEffects() << "!" << std::endl;
}

