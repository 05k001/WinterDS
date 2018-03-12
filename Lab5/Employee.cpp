#include <string>


// Example of an Employee class
class Employee
{
  public:
	explicit Employee(std::string n, double s, int sr) : name(n), salary(s), seniority(sr) {}
    const std::string & getName( ) const
      { return name; }

    bool operator==( const Employee & rhs ) const
      { return getName( ) == rhs.getName( ); }
    bool operator!=( const Employee & rhs ) const
      { return !( *this == rhs); }

      // Additional public members not shown

  private:
    std::string name;
    double salary;
    int    seniority;

      // Additional private members not shown
};

//This is added for strings

int hash (const std::string &);


int hash( const Employee & item )
{
    return hash( item.getName( ) );
}
