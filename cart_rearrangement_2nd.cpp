#include <iostream>
using namespace std;

int main()
{
    int a[5], b[5], i, j, tmp1 = 0, tmp2 = 0, tmp3 = 0, ctrl;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    for (i = 0; i < 5; i++)
    {
        ctrl = 0;
        if (a[i] == 5-i)
            b[i] = a[i];
        else
        {
            for (j = i; j < i + 3; j++)
            {
                if (tmp1 == 0)
                    tmp1 = a[i];
                else if (tmp2 == 0)
                    tmp2 = a[i];
                else if (tmp3 == 0)
                    tmp3 = a[i];
                else
                    ctrl = 1;
                if (tmp1 == 5-i)
                {
                    b[i] = tmp1;
                    tmp1 = 0;
                }
                else if (tmp2 == 5-i)
                {
                    b[i] = tmp2;
                    tmp2 = 0;
                }
                else if (tmp3 == 5-i)
                {
                    b[i] = tmp3;
                    tmp3 = 0;
                }
                if (ctrl == 1)
                {
                    if (tmp1 == 0)
                    {
                        tmp1 = a[i];
                        ctrl = 0;
                    }
                    else if (tmp2 == 0)
                    {
                        tmp2 = a[i];
                        ctrl = 0;
                    }
                    else if (tmp3 == 0)
                    {
                        tmp3 = a[i];
                        ctrl = 0;
                    }
                    else
                        break;
                }
            }
        }
    }
    if (ctrl == 1)
        cout << "重排失败";
    else
        cout << b[4] << ' ' << b[3] << ' ' << b[2] << ' ' << b[1] << ' ' << b[0];
    return 0;
}