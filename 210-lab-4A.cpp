// COMSC-210 | Lab 4A | Arkhip Finski
// IDE used : Visual Studio

#include<iostream>
#include<vector>
#include<random>
#include<iomanip>
using namespace std;

const int N_MAX = 50;
const int N_MIN = 25;
const int RGB_MAX_VALUE = 255;
const int RGB_MIN_VALUE = 0;

//Color structure that includes RGB values(red, green, blue)
struct Color{
    int red,green,blue;
};

int randomEngine(int i, int l);
void outputC(const vector<Color> &c);

int main(){
    //Vector for storing RGB values for each color
    vector<Color> colors;
    int n = randomEngine(N_MIN,N_MAX);
    colors.resize(n);

    //The loop used to give a random RGB values for each color in the vector      
    for(int i = 0; i < colors.size(); ++i){
        colors.at(i).red = randomEngine(RGB_MIN_VALUE,RGB_MAX_VALUE);
        colors.at(i).green = randomEngine(RGB_MIN_VALUE,RGB_MAX_VALUE);
        colors.at(i).blue = randomEngine(RGB_MIN_VALUE,RGB_MAX_VALUE);
    }
    outputC(colors);

    return 0;
}

//randomEngine generates a random integers between i(first number) and l(last number)
//arguments: i(first number) and l(last number), these numbers limit the range of the generated numbers
//return: A random generated integer in range from i(first number) to l(last number) 
int randomEngine(int i, int l){
    int num;

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(i,l);
    num = distribution(generator);

    return num;
}

//This function outputs a well-formatted table of colors and their RGB value stored in the vector "colors" of "color" data type 
//Arguments: const vector<Color> &c, gets a vector of "color" data type passed from a main function(for output), which cannot be edited 
void outputC(const vector<Color> &c){
    cout << setw(10) << "Color#" << setw(10) << "R value" << setw(10) << "G value" << setw(10) << "B value" << endl;
    cout << setw(10) << "------" << setw(10) << "-------" << setw(10) << "-------" << setw(10) << "-------" << endl;
    for (int i = 0; i < c.size(); ++i){
        cout << setw(8) << i+1 << setw(10) << c.at(i).red << setw(10) << c.at(i).green << setw(11) << c.at(i).blue << endl;
    }
}