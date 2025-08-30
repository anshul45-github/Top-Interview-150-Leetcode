// https://leetcode.com/problems/integer-to-roman

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        for(int i = 0; i < num / 1000; i++)
            roman += 'M';
        num -= (num / 1000) * 1000;
        if(num >= 900) {
            roman += "CM";
            num -= 900;
        }
        if(num >= 500) {
            roman += 'D';
            num -= 500;
        }
        if(num >= 400) {
            roman += "CD";
            num -= 400;
        }
        for(int i = 0; i < num / 100; i++) 
            roman += 'C';
        num -= (num / 100) * 100;
        if(num >= 90) {
            roman += "XC";
            num -= 90;
        }
        if(num >= 50) {
            roman += 'L';
            num -= 50;
        }
        if(num >= 40) {
            roman += "XL";
            num -= 40;
        }
        for(int i = 0; i < num / 10; i++) 
            roman += 'X';
        num -= (num / 10) * 10;
        if(num >= 9) {
            roman += "IX";
            num -= 9;
        }
        if(num >= 5) {
            roman += 'V';
            num -= 5;
        }
        if(num >= 4) {
            roman += "IV";
            num -= 4;
        }
        for(int i = 0; i < num; i++) 
            roman += 'I';
        return roman;
    }
};