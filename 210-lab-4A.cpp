// COMSC-210 | Lab 4A | Arkhip Finski
// IDE used : Visual Studio

#include<iostream>
#include<vector>
#include<random>
#include<iomanip>
using namespace std;

struct Color{
    int red,green,blue;
};

int randomEngine(int i, int l);
void outputC(const vector<Color> &c);

int main(){
    vector<Color> colors;
    int n = randomEngine(25,50);

    colors.resize(n);

    for(int i = 0; i < colors.size(); ++i){
        colors.at(i).red = randomEngine(0,255);
        colors.at(i).green = randomEngine(0,255);
        colors.at(i).blue = randomEngine(0,255);
    }

    return 0;
}

int randomEngine(int i, int l){
    int num;

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(i,l);
    num = distribution(generator);

    return num;
}