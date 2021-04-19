#include<iostream>
using namespace std;
void towers(int num, char S, char D, char A) {
    if(num == 1) {
        cout<<"\n Move disk 1 from "<<S<<" to "<<D;
        return;
    }
    towers(num-1, S, A, D);
    cout<<"\n Move disk "<<num<<" from "<<S<<" to "<<D;
    towers(num-1, A, D, S);
}

int main() {
    int n;
    cout<<"\n Enter the number of disks: ";
    cin>>n;
    towers(n, 'S', 'D', 'A');
    return 0;
}
