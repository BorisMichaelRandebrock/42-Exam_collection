/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:26:56 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/01 12:49:20 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget(const std::string &type) : _type(type) {
}

ATarget::~ATarget() {
}

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
