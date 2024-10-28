/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:07:09 by brandebr          #+#    #+#             */
/*   Updated: 2024/10/28 12:01:29 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {
	protected:
		std::string _name;
		std::string _effects;

		ASpell(const ASpell &);
		ASpell &operator=(const ASpell &);

	public:
		ASpell(const std::string &name, const std::string &effects);
		virtual ~ASpell();
		const std::string &getName() const;
		const std::string &getEffects() const;

		virtual ASpell *clone() const = 0;

		void launch(const ATarget &);
};

