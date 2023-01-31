#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	idx_ = 0;
}

std::string	PhoneBook::add_spaces(int n)
{
	std::string	str;

	while (n-- > 0)
		str.append(" ");
	return (str);
}

std::string	PhoneBook::width_make(std::string str, unsigned long max)
{
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

int	PhoneBook::search_ui(Contact contacts[8])
{
	char	c;
	int		i;
	std::string	str;

	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	c = '0';
	i = 0;
	while (++c <= '8')
	{
		if (contacts[c - 1 - '0'].get_fname().size() && ++i)
		{
			str = c;
			str = width_make(str, 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = width_make(contacts[c - 1  - '0'].get_fname(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = width_make(contacts[c - 1 - '0'].get_lname(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = width_make(contacts[c - 1 - '0'].get_nick(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			std::cout << "|" << std::endl;
		}
	}
	std::cout << " ___________________________________________ " << std::endl;
	return (i);
}

void	PhoneBook::add(void)
{
	std::string	str;

	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a first name: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts_[this->idx_ % 8].set_fname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts_[this->idx_ % 8].set_lname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a nick name: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts_[this->idx_ % 8].set_nick(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a phone number: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts_[this->idx_ % 8].set_pnum(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a darkest secret: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts_[this->idx_ % 8].set_secret(str);
	}
	this->idx_++;
}

void	PhoneBook::print(Contact contact)
{
	if (!contact.get_fname().size())
	{
		std::cout << "Invaild contact instance." << std::endl;
	}
	std::cout << "First Name: " << contact.get_fname() << std::endl;
	std::cout << "Last Name: " << contact.get_lname() << std::endl;
	std::cout << "Nickname: " << contact.get_nick() << std::endl;
	std::cout << "Phone Number: " << contact.get_pnum() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_secret() << std::endl;
}

Contact	PhoneBook::get_contact(int idx)
{
	return (this->contacts_[idx % 8]);
}

void	PhoneBook::search(void)
{
	std::string	str;

	if (!search_ui(this->contacts_))
	{
		std::cout << std::endl << "There is no contact." << std::endl;
		return ;
	}
	while (!std::cin.eof())
	{
		std::cout << "Select an index: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
			get_contact(str[0] - 1 - '0').get_fname().size())
				break ;
		}
		if (str != "")
			std::cout << "Invaild index." << std::endl;
	}
	if (!std::cin.eof())
		this->print(get_contact(str[0] - 1 - '0'));
}
