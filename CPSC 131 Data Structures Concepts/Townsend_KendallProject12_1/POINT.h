#include <iostream>
using namespace std;
#include <iomanip>
#include <string>

class POINT
{
private: int x, y;
public: void ReadPoint()
		{  char uselesschar;
			cin >> x; 
			cin >> uselesschar;
			cin >> y;
		}
		void ShowPoint()
		{ cout << "(" << x << "/" << y << ")"; }
		friend POINT operator+( POINT p, POINT q )
		{
			POINT r;
			if (p.y == q.y)
			{
				r.y = p.y;
				r.x = p.x + q.x;
			}
			else
			{
				r.y = p.y * q.y;
				r.x = (p.x * q.y) + (q.x * p.y);
			}
			return r;
		}

		friend POINT operator-( POINT p, POINT q )
		{
			POINT r;
			if (p.y == q.y)
			{
				r.y = p.y;
				r.x = p.x - q.x;
			}
			else
			{
				r.y = p.y * q.y;
				r.x = (p.x * q.y) - (q.x * p.y);
			}
			return r;

		}

		friend POINT operator*( POINT p, POINT q )
		{
			POINT r;
			r.x = p.x * q.x;
			r.y = p.y * q.y;

			return r;
		}

		friend POINT operator/( POINT p, POINT q )
		{
			POINT r;
			r.x = p.x * q.y;
			r.y = p.y * q.x;

			return r;
		}

		friend POINT operator++(POINT p)
		{
			POINT r;
			r.x = p.x + 1;
			r.y = p.y + 1;

			return r;
		}

		friend POINT operator--(POINT p)
		{
			POINT r;
			r.x = p.x - 1;
			r.y = p.y - 1;

			return r;
		}
};