#ifndef DEF_DURATION
#define DEF_DURATION

#include <iostream>

class Duration
{
	public:
		Duration(int hours = 0, int minutes = 0, int secondes = 0);

		int timeToSeconds();

		bool isEqual(Duration const&) const;
		bool isLessThan(Duration const&) const;
		bool isGreaterThan(Duration const&) const;

		Duration& operator+=(Duration const&);
		Duration& operator+=(int);
		Duration& operator-=(Duration const&);
		Duration& operator-=(int);

		void print(std::ostream&) const;


	private:
		int m_hours;
		int m_minutes;
		int m_seconds;
};

bool operator==(Duration const&, Duration const&);
bool operator!=(Duration const&, Duration const&);

bool operator<(Duration const&, Duration const&);
bool operator<=(Duration const&, Duration const&);
bool operator>(Duration const&, Duration const&);
bool operator>=(Duration const&, Duration const&);

Duration operator+(Duration const&, Duration const&);
Duration operator-(Duration const&, Duration const&);

Duration operator+(Duration const&, int);
Duration operator-(Duration const&, int);

std::ostream& operator<<(std::ostream&, Duration const&); 




#endif  // DEF_DURATION
