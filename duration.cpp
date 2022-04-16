#include "duration.hpp"

using namespace std;


Duration::Duration(int hours, int minutes, int seconds) : m_hours(hours), m_minutes(minutes), m_seconds(seconds)
{
}


bool Duration::isEqual(Duration const& time) const
{
	return (m_hours == time.m_hours && m_minutes == time.m_minutes && m_seconds == time.m_seconds);
}

bool Duration::isLessThan(Duration const& time) const
{
	if (m_hours < time.m_hours)
	{
		return true;
	}
	else if (m_hours == time.m_hours && m_minutes < time.m_minutes)
	{
		return true;
	}
	else if (m_hours == time.m_hours && m_minutes == time.m_minutes && m_seconds < time.m_seconds)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Duration::isGreaterThan(Duration const& time) const
{
	if (m_hours > time.m_hours)
	{
		return true;
	}
	else if (m_hours == time.m_hours && m_minutes > time.m_minutes)
	{
		return true;
	}
	else if (m_hours == time.m_hours && m_minutes == time.m_minutes && m_seconds > time.m_seconds)
	{
		return true;
	}
	else
	{
		return false;
	}

}

Duration& Duration::operator+=(Duration const& time)
{
	m_seconds += time.m_seconds;

	m_minutes += m_seconds / 60;
	m_seconds %= 60;

	m_minutes += time.m_minutes;
	
	m_hours += m_minutes / 60;
	m_minutes %= 60;

	m_hours += time.m_hours;

	return *this;
}

Duration& Duration::operator+=(int seconds)
{
	//m_seconds += time.m_seconds;
	m_seconds += seconds;

	m_minutes += m_seconds / 60;
	m_seconds %= 60;

	//m_minutes += time.m_minutes;
	
	m_hours += m_minutes / 60;
	m_minutes %= 60;

	//m_hours += time.m_hours;

	return *this;
}

Duration& Duration::operator-=(Duration const& time)
{
	if (*this > time)
	{
		if (time.m_seconds > m_seconds)
		{
			--m_minutes;
			m_seconds += 60;
		}

		m_seconds -= time.m_seconds;

		if(time.m_minutes > m_minutes)
		{
			--m_hours;
			m_minutes += 60;
		}

		m_minutes -= time.m_minutes;

		m_hours -= time.m_hours;

		return *this;
	}
	else
	{
		Duration *copy = this;

		//cout << "Copy" << endl;
		//copy->print();


		/*m_hours = time.m_hours;
		m_minutes = time.m_minutes;
		m_seconds = time.m_seconds;*/

		Duration *c = new Duration(time);

		//cout << "C before operations" << endl;
		//c->print();

		if (copy->m_seconds > c->m_seconds)
		{
			--c->m_minutes;
			c->m_seconds += 60;
		}

		c->m_seconds -= copy->m_seconds;

		if(copy->m_minutes > c->m_minutes)
		{
			--c->m_hours;
			c->m_minutes += 60;
		}

		c->m_minutes -= copy->m_minutes;

		c->m_hours -= copy->m_hours;

		//cout << "C after " << endl;
		//c->print();

		m_hours = c->m_hours;
		m_minutes = c->m_minutes;
		m_seconds = c->m_seconds;


		return *this;
	}

	//return time;
}



void Duration::print(ostream& flux) const
{
	flux << m_hours << ":" << m_minutes << ":" << m_seconds ;
}


/****OPERATORS*****/

bool operator==(Duration const& time1, Duration const& time2)
{
	return time1.isEqual(time2);
}

bool operator!=(Duration const& time1, Duration const& time2)
{
	return !(time1==time2);
}

bool operator<(Duration const& time1, Duration const& time2)
{
	return time1.isLessThan(time2);
}

bool operator<=(Duration const& time1, Duration const& time2)
{
	return !(time1 > time2);
}

bool operator>(Duration const& time1, Duration const& time2)
{
	return time1.isGreaterThan(time2);
}

bool operator>=(Duration const& time1, Duration const& time2)
{
	return !(time1 < time2);
}


Duration operator+(Duration const& time1, Duration const& time2)
{
	Duration copy(time1);

	copy += time2;

	return copy;
}

Duration operator+(Duration const& time1, int seconds)
{
	Duration copy(time1);

	copy += seconds;

	return copy;
}

Duration operator-(Duration const& time1, Duration const& time2)
{
	Duration copy(time1);

	copy -= time2;

	return copy;
}

ostream& operator<<(ostream& flux, Duration const& time)
{
	time.print(flux);

	return flux;
}
