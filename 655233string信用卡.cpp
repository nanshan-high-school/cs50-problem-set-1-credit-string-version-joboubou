#include <iostream>
using namespace std;

int main() {
    string number;
    cout << "請輸入卡號";
    cin >> number;

    int length = 0;
    for (; number[length] != '\0'; length++) {

    }

    int oddSum = 0;
    int evenSum = 0;

    bool even = false;

    bool visaHead = false;
    bool mastercardHead = false;
    bool americanExpressHead = false;

    int j = (number[0] - '0') * 10 + (number[1] - '0');    

    for (int i = length - 1; i >= 0; i--) {
        int x = number[i] - '0';

        if (even) {
            // 偶數位要做的事
                
            // *2
            int now = x * 2;

            // 個位數+十位數
            // 加到 evenSum
            evenSum += (now % 10) + (now / 10);

        } else {
            // 奇數位要做的事

            // 加到 oddSum
            oddSum += x;
        }   

        if (j >= 10 && j <= 99) {
            if (j >= 40 && j <= 49) {
                visaHead = true;
            } else if (j >= 51 && j <= 55) {
                mastercardHead = true;
            } else if (j == 34 || j == 37) {
                americanExpressHead = true;
            }
        }

        even = !even;
    }

    // oddSum + evenSum
    int answer = oddSum + evenSum;

    // 判斷尾數是不是 0
    if (answer % 10 != 0) {
        cout << "無效卡號";

        return 0;
    }
    
    if (visaHead && (length == 13 || length == 16)) {
        cout << "VISA";

        return 0;
    }

    if (mastercardHead && length == 16) {
        cout << "MasterCard";

        return 0;
    }

    if (americanExpressHead && length == 15) {
        cout << "American Express";

        return 0;
    }

    // return 0;
}
