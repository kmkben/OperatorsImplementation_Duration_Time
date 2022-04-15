#ifndef DEF_DURATION
#define DEF_DURATION


class Duration
{
	public:
		Duration(int hours = 0, int minutes = 0, int secondes = 0);

		bool isEqual(Duration const&) const;
		bool isLessThan(Duration const&) const;
		bool isGreaterThan(Duration const&) const;


	private:
		int m_hours;
		int m_minutes;
		int m_secondes;
};

bool operator==(Duration const&, Duration const&);
bool operator!=(Duration const&, Duration const&);

bool operator<(Duration const&, Duration const&);
bool operator<=(Duration const&, Duration const&);
bool operator>(Duration const&, Duration const&);
bool operator>=(Duration const&, Duration const&);


#endif  // DEF_DURATION
