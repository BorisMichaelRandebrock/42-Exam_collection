/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:11:49 by brandebr          #+#    #+#             */
/*   Updated: 2024/10/28 13:18:16 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	for (std::map<std::string, ASpell *>::iterator it = _arr.begin(); it != _arr.end(); ++it)
		delete it->second;
}

void SpellBook::learnSpell(ASpell *name) {
	std::map<std::string, ASpell *>::iterator it = _arr.find(name->getName());

	if (it == _arr.end())
		_arr[name->getName()] = name->clone();
}


void SpellBook::forgetSpell(const std::string name) {
	std::map<std::string, ASpell *>::iterator it = _arr.find(name);

	if (it != _arr.end()) {
		delete it->second;
		_arr.erase(it);
	}
}

ASpell *SpellBook::createSpell(std::string const &name) {
	std::map<std::string, ASpell *>::iterator it = _arr.find(name);

	if (it != _arr.end())
		return it->second->clone();
	return NULL;
}

