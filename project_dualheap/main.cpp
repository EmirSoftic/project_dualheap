#include <iostream>
#include "dvostrukiheap.h"
using namespace std;

int main(){
    vector<int> v{10,50,2,5,12,4,7,34,66,87,99,321,1,9,32,26,72,94,0,1,19,222,89,13,11,111,45,57,88,31,56,76};
    DHeap h(v);
    h.Ispisi();
    cout << endl << "Heap nakon izbrisanog najmanjeg elementa: " << endl;
    h.Izbrisimin();
    h.Ispisi();
    cout << endl << "Heap nakon sto jos dva puta izbrisemo minimum: " << endl;
    h.Izbrisimin();
    h.Izbrisimin();
    h.Ispisi();
    cout << endl << "Heap nakon sto izbrisemo maksimum 3 puta: " << endl;
    h.Izbrisimaks();
    h.Izbrisimaks();
    h.Izbrisimaks();
    h.Ispisi();
    cout << endl << "Trenutni maksimum je: " << h.DHeapmaks() << ", a minimum je: " << h.DHeapmin();
    h.Izbrisimaks(); h.Izbrisimin();
    cout << endl << "Da jos jednom izbrisemo maksimum, maksimum bi bio: " << h.DHeapmaks() << ", a da izbrisemo minimum bio bi: " << h.DHeapmin();
}
