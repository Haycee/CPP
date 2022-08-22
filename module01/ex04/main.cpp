/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:44:01 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/22 11:24:52 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// check if file is a directory

static std::string	findAndReplace(std::string str, std::string s1, std::string s2);

int main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		copy;
	std::string		buffer;

	if (argc != 4)
	{
		std::cout << "Usage : ./sed filename s1 s2" << std::endl;
		return (0);
	}

	infile.open(argv[1]);
	if (infile.is_open())
	{
		while (std::getline(infile, buffer))
		{
			if (!infile.eof())
				buffer.append("\n");
			buffer = findAndReplace(buffer, argv[2], argv[3]);
			copy.append(buffer);
		}
		infile.close();
	}
	else
	{
		std::cout << "Error: failed to open " << argv[1] << std::endl;
		return (1);
	}

	outfile.open("outfile");
	if (outfile.is_open())
	{
		outfile << copy;
		outfile.close();
	}
	else
	{
		std::cout << "Error: failed to create outfile" << std::endl;
		return (1);
	}
	return (0);
}

static std::string	findAndReplace(std::string str, std::string s1, std::string s2)
{
	int pos = 0;

	if (s1.empty() || s1.compare(s2) == 0)
		return (str);
	while (str.find(s1, pos) != std::string::npos)
	{
		pos = str.find(s1, pos);
		str.erase(pos, s1.length());
		str.insert(pos, s2);
		pos += s2.length();
	}
	return (str);
}
