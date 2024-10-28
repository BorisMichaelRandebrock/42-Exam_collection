/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:07:09 by brandebr          #+#    #+#             */
/*   Updated: 2024/10/28 11:58:26 by brandebr         ###   ########.fr       */
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

