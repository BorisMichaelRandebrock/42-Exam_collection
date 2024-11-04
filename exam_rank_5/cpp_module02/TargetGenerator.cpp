/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:11:49 by brandebr          #+#    #+#             */
/*   Updated: 2024/10/28 13:06:44 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	for (std::map<std::string, ATarget *>::iterator it = _arr.begin(); it != _arr.end(); ++it)
		delete it->second;
}

void TargetGenerator::learnTargetType(ATarget *type) {
	std::map<std::string, ATarget *>::iterator it = _arr.find(type->getType());

	if (it == _arr.end())
		_arr[type->getType()] = type->clone();
}


void TargetGenerator::forgetTargetType(const std::string type) {
	std::map<std::string, ATarget *>::iterator it = _arr.find(type);

	if (it != _arr.end()) {
		delete it->second;
		_arr.erase(it);
	}
}

ATarget *TargetGenerator::createTarget(std::string const &type) {
	std::map<std::string, ATarget *>::iterator it = _arr.find(type);

	if (it != _arr.end())
		return it->second->clone();
	return NULL;
}

