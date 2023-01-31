#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts_[8];
		int		idx_;
	public:
		PhoneBook(void);
		std::string add_spaces(int n);
		std::string width_make(std::string str, unsigned long max);
		int		search_ui(Contact contacts[8]);
		void	add(void);
		void	search(void);
		void	print(Contact contact);
		Contact	get_contact(int idx);
};

#endif
