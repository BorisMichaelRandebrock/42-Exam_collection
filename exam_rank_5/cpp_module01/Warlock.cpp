/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:26:56 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/01 13:19:12 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title) {
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	for (std::map<std::string, ASpell *>::iterator it = _arr.begin(); it != _arr.end(); ++it)
		delete it->second;
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

void Warlock::setTitle(const std::string &title) { this->_title = title; }

void Warlock::introduce() const {
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void Warlock::learnSpell(const ASpell *name) {
	std::map<std::string, ASpell *>::iterator it = _arr.find(name->getName());

	if (it == _arr.end())
		_arr[name->getName()] = name->clone();
}

void Warlock::forgetSpell(const std::string name) {
	std::map<std::string, ASpell *>::iterator it = _arr.find(name);

	if (it != _arr.end()) {
		delete it->second;
		_arr.erase(it);
	}
}

void Warlock::launchSpell(const std::string name, ATarget &target) {
	std::map<std::string, ASpell *>::iterator it = _arr.find(name);

	if (it != _arr.end())
		it->second->launch(target);
}
