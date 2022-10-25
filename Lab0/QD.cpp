//
// Created by Mark455 on 2022/9/9.
//

#include <iostream>
#include <sstream>


using namespace std;
static int listOfQuetou[14];
static bool test = false;
static bool ato = false;
static int autotime = 12450;
static string myhand;

class Mahhjong {
public:
    string type;
    int num;
    Mahhjong()
    {
        type = 'n';
        num = 0;
    }
    Mahhjong(string typeIn, int numIn) {
        type = *new string ;
        type = typeIn;
        num = *new int;
        num = numIn;
    }

};
int findQuetou(Mahhjong list[]) {
    int index=0;
    for (int i=0; i < 14; i++) {
        Mahhjong a = list[i];
        for (int i1=0; i1 < 14; i1++) {
            Mahhjong b = list[i1];
            if (a.type == b.type && a.num == b.num && i!= i1) {
                bool can = true;
                for (int i2 = 0; i2 < index; i2 ++) {
                    if (i == listOfQuetou[i2] || i1 == listOfQuetou[i2]) {
                        can = false;
                    }
                }
                if (can) {
                    listOfQuetou[index++] = i;
                    listOfQuetou[index++] = i1;
                }
            }
        }
    }
    return index;
}

int findSmallest(Mahhjong list[], int Considered[], int length) {
    int small=0;
    bool can;
    for (int i1 = 0; i1 < 14; i1++) {
        for (int i= 0 ; i < length; i++) {
            if (small == Considered[i]) {
                ++small;
            }
        }
    }

    for(int i = 0; i < 14; i++){
        can = true;
        if (list[i].num < list[small].num) {
            for (int i1 = 0 ; i1 < length; i1++) {
                if (i == Considered[i1]) {
                    can = false;
                }
            }
            if (can) {
                small = i;
            }
        }
    }
    if (test) {
        cout << "最小的是："<< small << endl;
    }

    return small;
}

bool findJuzi(Mahhjong list[], int Considered[], int a, int index) {
    if (index == 14) {
        return true;
    }
    if (test) {
        cout << "开始找相同的" << endl;
    }
    //Find Same 3
    int tempCon[3];
    int ind = 0;
    int ConsiderTemp[14];
    for (int i1= 0 ; i1 < index; i1++) {
        ConsiderTemp[i1] = Considered[i1];
    }

    for (int i = 0; i < 14; i++) {
        if (list[i].num == list[a].num && list[i].type == list[a].type) {
            bool can = true;
            for (int i1= 0 ; i1 < index; i1++) {
                if (i == Considered[i1]) {
                    can = false;
                }
            }
            for (int i1= 0 ; i1 < ind; i1++) {
                if (i == tempCon[i1]) {
                    can = false;
                }
            }
            if (can) {
                tempCon[ind++] = i;
                i=-1;
            }
        }
        if (ind == 3) {
            for (int i1= 0 ; i1 < ind; i1++) {
                Considered[index++] = tempCon[i1];
            }
            if (test) {
                cout << "有仨" << endl;
            }
            a = findSmallest(list,Considered,index);
            return findJuzi(list,Considered,a,index);
        }
    }

    //Find Different 3
    if (test) {
        cout << "开始找不同的" << endl;
    }
    int tempCon2[3];
    int ind2 = 0;
    for (int i = 0; i < 14; i++) {
        if (list[a].type == "z") {
            continue;
        }
        if (list[i].num == list[a].num+ind2 && list[i].type == list[a].type) {
            bool can = true;
            for (int i1= 0 ; i1 < index; i1++) {
                if (i == Considered[i1]) {
                    can = false;
                }
            }
            for (int i1= 0 ; i1 < ind2; i1++) {
                if (i == tempCon2[i1]) {
                    can = false;
                }
            }


            if (can) {
                tempCon2[ind2++] = i;
                i=-1;
            }
        }
        if (ind2 == 3) {
            if (test) {
                cout << "有一句" << endl;
            }

            for (int i1= 0 ; i1 < ind2; i1++) {
                Considered[index] = tempCon2[i1];
                index++;
            }
            if (test) {
                cout << "当前考虑到";
                for (int i = 0; i < index; i++) {
                    cout << Considered[i] << " ";
                }
                cout << endl;
            }

            a = findSmallest(list,Considered,index);
            return findJuzi(list,Considered,a,index);
        }
    }

    return false;
}
bool Check(Mahhjong list[], int Quetou[], int now, int QuetouCnt) {
    if (now == QuetouCnt) {
        return false;
    }
    int Considered[14];
    int index = 0;
    Considered[index++] = Quetou[now];
    Considered[index++] = Quetou[now+1];
    int a = findSmallest(list,Considered,index);
    if (findJuzi(list,Considered,a,index)) {
        return true;
    } else {
        now=now+2;
        if (test) {
            for (int i = 0; i < index; i++) {
                cout << Considered[i];
            }
            cout << endl << "找下一个"<<endl;
            cout << endl;
        }
        return Check(list, Quetou, now, QuetouCnt);
    }
}

int main() {
    int cnt;
    if (test) {
        cnt = 1;
    } else if (ato) {
        cnt = autotime;
    }
    else {

        cin >> cnt;
    }


    string list[cnt][14][2];
    for (int i = 0; i < cnt; i++) {
        string hand;
        if (test) {
            hand = "6b7s6b4b6z8b7s7b6z6z8b8b5b5b";
        } else if (ato) {
            myhand = hand;
        }
        else {
            cin >> hand;
        }

        for (int i1 = 0; i1 < 14; i1++) {
            list[i][i1][0] = hand[2*i1];
            list[i][i1][1] = hand[2*i1+1];
        }
    }
    for (int i = 0; i < cnt; i++) {
        Mahhjong handList[14];
        for (int i1 = 0; i1 < 14; i1++) {
            int num;
            string text = list[i][i1][0];
            stringstream ss;
            ss << text;
            ss >> num;
            string type = list[i][i1][1];
            Mahhjong thisMahh = Mahhjong(type, num);
            handList[i1] = thisMahh;
        }
        int QuetouCnt;
        QuetouCnt = findQuetou(handList);
        bool yes = Check(handList,listOfQuetou,0,QuetouCnt);


        if (yes) {
            cout << "Blessing of Heaven" << endl;
//            for (int i3 = 0; i3 < 14; i3++) {
//                cout << handList[i3].num << handList[i3].type;
//            }
        } else {
            cout << "Bad luck" << endl;
//            for (int i3 = 0; i3 < 14; i3++) {
//                cout << handList[i3].num << handList[i3].type;
//            }
        }



    }
}