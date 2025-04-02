/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:18:28 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/01 10:18:16 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
    AForm("ShrubberyCreationForm", 145, 137), _target(target) {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other) : 
    AForm(other.getName(), other.getMinSignGrade(), other.getMinExecuteGrade()),
    _target(other._target) {};

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other) {
    if (this != &other) {
        delete this;
        new(this) ShrubberyCreationForm(other);
    }
    return (*this);
};

ShrubberyCreationForm::~ShrubberyCreationForm() {};

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    canExecute(executor);
    try {
        std::ofstream file;
        file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
        std::string fileName = _target + "_shrubbery";
        file.open(fileName.c_str());
        file << tree();
        file.close();
        std::cout << "ShrubberyCreationForm executed" << std::endl;
    }
    catch (std::exception & e) {
        std::cerr << "Opening file failed: " << e.what() << std::endl;
    }
};

std::string ShrubberyCreationForm::tree() const {
    return (
        "\
          &&& &&  & &&\n\
      && &\\/&\\|& ()|/ @, &&\n\
      &\\/(/&/&||/& /_/)_&/_&\n\
   &() &\\/&|()|/&\\/ '%' & ()\n\
  &_\\_&&_\\ |& |&&/&__%_/_& &&\n\
&&   && & &| &| /& & % ()& /&&\n\
 ()&_---()&\\&\\|&&-&&--%---()~\n\
     &&     \\|||\n\
             |||\n\
             |||\n\
             |||\n\
       , -=-~  .-^- _\n\
 _____________________________\n\
| Why is it, when you want a |\n\
| stupid tree, it is so much |\n\
|   bureaucracy to get it?   |\n\
 -----------------------------\n"
    );
};