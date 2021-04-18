#pragma once
#include <string>
#include <map>
using namespace std;

namespace ariel{
    class NumberWithUnits{
        static map<string, pair<int, string>> units; 
        friend NumberWithUnits& operator+(const NumberWithUnits& curr);
        friend NumberWithUnits& operator-(const NumberWithUnits& curr);
        friend ostream& operator<<(ostream& os, const NumberWithUnits& curr);
        friend NumberWithUnits& operator *(const double d,NumberWithUnits& curr);
        friend  istream& operator>>(istream& is, const NumberWithUnits& curr);
        public:
            NumberWithUnits(int num, const string &unit){
                // throw invalid_argument("Invalid Unit");
            };
            static void read_units(ifstream &units_file);
            NumberWithUnits& operator +(const NumberWithUnits& other)const;
            NumberWithUnits& operator +=(const NumberWithUnits& other);
            NumberWithUnits& operator -(const NumberWithUnits& other)const;
            NumberWithUnits& operator -=(const NumberWithUnits& other);
            bool operator <(const NumberWithUnits& other)const;
            bool operator <=(const NumberWithUnits& other)const;
            bool operator ==(const NumberWithUnits& other)const;
            bool operator >=(const NumberWithUnits& other)const;
            bool operator >(const NumberWithUnits& other)const;
            bool operator !=(const NumberWithUnits& other)const;
            NumberWithUnits& operator ++();
            NumberWithUnits& operator --();


    };
}