/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:24:01 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/01 13:11:42 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"


class Warlock {
	private:
		std::string _name;
		std::string _title;

		Warlock(const Warlock &);
		Warlock &operator=(const Warlock &);
		std::map<std::string, ASpell *> _arr;

	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(const std::string &title);

		void introduce() const;

		void learnSpell(const ASpell *);
		void forgetSpell(const std::string name);
		void launchSpell(const std::string name, ATarget &);
};
