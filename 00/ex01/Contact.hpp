#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string fname_;
		std::string lname_;
		std::string nick_;
		std::string pnum_;
		std::string secret_;
	public:
		std::string	get_fname(void) const;
		std::string	get_lname(void) const;
		std::string	get_nick(void) const;
		std::string	get_pnum(void) const;
		std::string	get_secret(void) const;
		void		set_fname(std::string str);
		void		set_lname(std::string str);
		void		set_nick(std::string str);
		void		set_pnum(std::string str);
		void		set_secret(std::string str);
};

#endif
