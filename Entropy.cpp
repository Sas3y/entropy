#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    int coin[100] = { 0 }, i, am = 0, which = 0, side = 0, amount[101] = { 0 };

    for (i = 0;i < 100;i++) {
        if (i % 2) coin[i] = 1;
        //cout << coin[i]<<" "<<i<<endl;
    }

    ifstream inp1("rnd0to99x50000.txt");
    ifstream inp2("rnd0to1x50000.txt");
    ofstream otp1("outputexcel.txt");
   
    for (int k = 0;k < 5;k++) {
        for (int j = 0;j < 10000;j++) {
            inp1 >> which;
            inp2 >> side;

            //cout << which << " " << side << endl;

            coin[which] = side;

            for (i = 0;i < 100;i++) {
                am += coin[i];
            }
            otp1 << am << "\n";
            amount[am]++;
            am = 0;
        }
        cout << "Progress: " << k << "/5\n";
    }

    inp1.close();
    inp2.close();
    ofstream otp("output50000.txt");


    for (i = 0;i < 101;i++) {
        otp << i << " " << amount[i] << endl;
    }
    
    otp.close();

    cout << "Progress: 5/5\nIt is complete!\n";

    return 0;
}
