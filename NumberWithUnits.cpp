#include <string>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;

#include "NumberWithUnits.hpp"
using namespace ariel;


namespace ariel{
        void NumberWithUnits::read_units(ifstream &units_file){
            string unit_str;
            while (getline (units_file, unit_str)) {
                string unit = unit_str.substr(1, unit_str.find_first_of('=')-1);
                cout<<unit<<endl;
                
            }

        }
        NumberWithUnits& NumberWithUnits::operator +(const NumberWithUnits& other)const{
            return *(new NumberWithUnits(0, "km"));
        }
        NumberWithUnits& NumberWithUnits::operator +=(const NumberWithUnits& other){
            return *(new NumberWithUnits(0, "km"));
        }
        NumberWithUnits& operator+(const NumberWithUnits& curr){
            return *(new NumberWithUnits(0, "km"));
        }
        NumberWithUnits& operator-(const NumberWithUnits& curr){
            return *(new NumberWithUnits(0, "km"));
        }
        NumberWithUnits& NumberWithUnits::operator -(const NumberWithUnits& other)const{
            return *(new NumberWithUnits(0, "km"));
        }
        NumberWithUnits& NumberWithUnits::operator -=(const NumberWithUnits& other){
            return *(new NumberWithUnits(0, "km"));
        }
        ostream& operator<<(ostream& os, const NumberWithUnits& curr){
            return os;
        }
        bool NumberWithUnits::operator <(const NumberWithUnits& other)const{
            return true;
        }
        bool NumberWithUnits::operator <=(const NumberWithUnits& other)const{
            return true;
        }
        bool NumberWithUnits::operator ==(const NumberWithUnits& other)const{
            return true;
        }
        bool NumberWithUnits::operator >=(const NumberWithUnits& other)const{
            return true;
        }
        bool NumberWithUnits::operator >(const NumberWithUnits& other)const{
            return true;
        }
        bool NumberWithUnits::operator !=(const NumberWithUnits& other)const{
            return true;
        }
        NumberWithUnits& NumberWithUnits::operator ++(){
            return *(new NumberWithUnits(0, "km"));
        }
        NumberWithUnits& NumberWithUnits::operator --(){
            return *(new NumberWithUnits(0, "km"));
        }
        NumberWithUnits& operator *(const double d,NumberWithUnits& curr){
            return *(new NumberWithUnits(0, "km"));
        }
        istream& operator>>(istream& is, const NumberWithUnits& curr){
            return is;
        }


}