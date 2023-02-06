#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <sstream>
# include <cmath>
# include <iomanip>

class Convert {
    private:
        std::string input_;
        char v_char_;
        int v_int_;
        float v_float_;
        double v_double_;
        bool err_;
    public:
        Convert(void);
        Convert(const Convert& obj);
		Convert& operator=(const Convert& obj);
		~Convert(void);
        Convert(std::string str);
        void setValue(std::string str);
        std::string getInput(void) const;
        char getChar(void) const;
        int getInt(void) const;
        float getFloat(void) const;
        double getDouble(void) const;
        bool getErr(void) const;
        char printChar(void) const;
        int printInt(void) const;
        float printFloat(void) const;
        double printDouble(void) const;
};

std::ostream& operator<<(std::ostream &out, const Convert &b);

#endif
