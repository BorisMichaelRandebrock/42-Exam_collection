/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:24:01 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/01 12:47:59 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
	protected:
		std::string _type;

		ATarget(const ATarget &);
		ATarget &operator=(const ATarget &);

	public:
		ATarget(const std::string &type);
		virtual ~ATarget();

		const std::string &getType() const;
		
		virtual ATarget *clone() const = 0;

		void getHitBySpell(const ASpell &) const;
};
