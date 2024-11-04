/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:26:56 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/01 12:51:41 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell(const std::string &name, const std::string &effects) : _name(name), _effects(effects) {
}

ASpell::~ASpell() {
}

ASpell &ASpell::operator=(const ASpell &cpy) {
	this->_name = cpy._name;
	this->_effects = cpy._effects;
	return *this;
}

ASpell::ASpell(const ASpell &cpy) {
	*this = cpy;
}

const std::string &ASpell::getName() const { return this->_name; }
const std::string &ASpell::getEffects() const { return this->_effects; }

void ASpell::launch(const ATarget &target) const {
	target.getHitBySpell(*this);
}
