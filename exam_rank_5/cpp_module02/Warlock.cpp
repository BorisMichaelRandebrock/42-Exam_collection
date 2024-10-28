/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:11:49 by brandebr          #+#    #+#             */
/*   Updated: 2024/10/28 13:02:21 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title) {
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

Warlock &Warlock::operator=(const Warlock &cpy) {
	this->_name = cpy._name;
	this->_title = cpy._title;
	return *this;
}

Warlock::Warlock(const Warlock &cpy) {
	*this = cpy;
}

const std::string &Warlock::getName() const { return this->_name; }
const std::string &Warlock::getTitle() const { return this->_title; }

void Warlock::setTitle(const std::string &title) {
	this->_title = title;
}

void Warlock::introduce() const {
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}


void Warlock::learnSpell(ASpell *name) {
	_arr.learnSpell(name);
}


void Warlock::forgetSpell(const std::string name) {
	_arr.forgetSpell(name);
}

void Warlock::launchSpell(const std::string name, ATarget &target) {
	ASpell *spell = _arr.createSpell(name);

	if (spell) {
		spell->launch(target);
		delete spell;
	}
}

