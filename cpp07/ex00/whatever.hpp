/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:38:24 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/14 12:31:13 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<class T>
static void swap(T & first, T & second) {
    T temp = first;
    first = second;
    second = temp;
};

template<class T>
static T min(T & first, T & second) {
    return (first < second ? first : second);
};

template<class T>
static T max(T & first, T & second) {
    return (first > second ? first : second);
};
