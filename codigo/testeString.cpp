#include <iostream>
#include <string>
using namespace std;

int main(){
    string primeiro = "ola";
    string segundo;
    segundo = primeiro;
    segundo[0] = 'C';
    cout << primeiro << endl << segundo << endl;
}