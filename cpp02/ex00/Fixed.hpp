/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:40:39 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/23 11:45:34 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed {

    private:
        int _value;
        static const int _fractionalBits = 8;

    public:

        Fixed();

        Fixed(const Fixed &other);

        Fixed &operator=(const Fixed &other);

        ~Fixed();

        int getRawBits(void) const;

        void setRawBits(int const raw);
};