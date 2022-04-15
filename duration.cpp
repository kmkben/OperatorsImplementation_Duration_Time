#include "duration.hpp"

using namespace std;


Duration::Duration(int hours, int minutes, int secondes) : m_hours(hours), m_minutes(minutes), m_secondes(secondes)
{
}


bool Duration::isEqual(Duration const& time) const
{
	return (m_hours == time.m_hours && m_minutes == time.m_minutes && m_secondes == time.m_secondes);
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
	else if (m_hours == time.m_hours && m_minutes == time.m_minutes && m_secondes < time.m_secondes)
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
	else if (m_hours == time.m_hours && m_minutes == time.m_minutes && m_secondes > time.m_secondes)
	{
		return true;
	}
	else
	{
		return false;
	}

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
