/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:00:22 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/17 14:02:51 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void validateArgs(int argc, char *argv[]) {

    if (argc != 4) {
        std::cerr << "This program takes exactly 3 arguments, a filename and "
                  "two strings" << std::endl;
        exit(1);
    }
    std::string s1 = argv[2];
    if (s1.empty()) {
        std::cerr << "The first string can not be an empty string" << std::endl;
        exit(1);
    }
}

std::ifstream openInputFile(const std::string& filename) {

    std::ifstream infile(filename, std::ios::in);
    if (!infile) {
        std::cerr << "No such file or incorrect permissions." << std::endl;
        std::cerr << "Exiting program." << std::endl;
        exit(1);
    }
    return infile;
}

std::ofstream openOutputFile(const std::string& filename) {

    std::string newFileName = filename + ".replace";
    std::ofstream outfile(newFileName);
    if (!outfile) {
        std::cerr << "Error creating file called: " << newFileName << std::endl;
        std::cerr << "Exiting program." << std::endl;
        exit(1);
    }
    return outfile;
}

std::string readFileToString(std::ifstream& infile) {

    std::stringstream stringStream;
    stringStream << infile.rdbuf();
    return (stringStream.str());
}

std::string replaceStringsInContent(const std::string& content,
    const std::string& s1, const std::string& s2) {

    std::string replacedString = content;
    size_t matchPos = 0;

    while ((matchPos = replacedString.find(s1, matchPos)) != std::string::npos) {
        replacedString.erase(matchPos, s1.length());
        replacedString.insert(matchPos, s2);
        matchPos = matchPos + s2.length();
    }

    return replacedString;
}

void writeToFile(std::ofstream& outfile, const std::string& content) {
    
    outfile << content;
}

int main(int argc, char* argv[]) {

    validateArgs(argc, argv);

    std::string filename(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);

    std::ifstream infile = openInputFile(filename);
    std::ofstream outfile = openOutputFile(filename);

    std::string fileContent = readFileToString(infile);

    std::string replacedContent = replaceStringsInContent(fileContent, s1, s2);

    outfile << replacedContent;

    infile.close();
    outfile.close();

    return 0;
}
