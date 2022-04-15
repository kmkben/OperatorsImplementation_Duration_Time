#include <iostream>

#include "duration.hpp"

using namespace std;


int main()
{
	
	Duration time1(0, 10, 28);
	Duration time2(0, 10, 28);

	cout << "\nOPERATOR== \n" << endl;
	if (time1 == time2)
	{
		cout << "These two times are identics" << endl;
	}
	else
	{
		cout << "The two times are not identics" << endl;
	}
	
	cout << "\nOPERATOR!= \n" << endl;
	if (time1 != time2)
	{
		cout << "These two times are differents" << endl;
	}
	else
	{
		cout << "The two times are not differents" << endl;
	}

	cout << "\nOPERATOR< \n" << endl;
	if (time1 < time2)
	{
		cout << "time1 < time2" << endl;
	}
	else
	{
		cout << "time1 is not less than time2" << endl;
	}


	cout << "\nOPERATOR<= \n" << endl;
	if (time1 <= time2)
	{
		cout << "time1 <= time2" << endl;
	}
	else
	{
		cout << "time1 is less than or equal to time2" << endl;
	}

	cout << "\nOPERATOR> \n" << endl;
	if (time1 > time2)
	{
		cout << "time1 > time2" << endl;
	}
	else
	{
		cout << "time1 is not greater than time2" << endl;
	}

	cout << "\nOPERATOR>= \n" << endl;
	if (time1 >= time2)
	{
		cout << "time1 >= time2" << endl;
	}
	else
	{
		cout << "time1 is not greater than or equal to time2" << endl;
	}


	return 0;
}
