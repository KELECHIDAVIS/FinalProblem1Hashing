/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kboss
 *
 * Created on December 14, 2023, 10:16 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <list>
using namespace std;

/*
 * 
 */

int returnNumber (char letter) ; // returns number on telephone represented by letter
int telephoneHash(string initials) ; 

int main(int argc, char** argv) {
    
    srand(time(0)); 
    
    const int size = 512; 
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    list<string> listArr[size] ; 
    
    // create 512 random 3 letter strings and place in the list 
    for(int i =0; i< size ; i++){
        
        string temp= ""; 
        for(int i = 0; i< 3; i++){
            temp += alphabet[rand()%alphabet.size()]; 
        }
        
        int index = telephoneHash(temp)%size; 
        
        listArr[index].push_back(temp); 
        
    }
    
    int counterSize=10; 
    int arr[counterSize ]= {0} ; // array used for counting how many list have a certain size; their size will be the index 
    
    for(int i =0 ; i<size; i++ )
    {
        arr[listArr[i].size()] ++; 
    }
    
    
    
    for(int i =0; i< counterSize  ; i++ )
    {
        cout<<"List with "<< i <<" elements: "<< arr[i]<<endl; 
    }
    return 0;
}

int telephoneHash(string initials)
{
    int temp = 0; 
    for(int i = 0 ; i< initials.size(); i++){
        
        int multiplier = pow(10, 2-i); // (hundreds tens ones place ) 
        
        temp+= returnNumber(initials[i]) *multiplier; 
    }
    
    return temp; 
}
int returnNumber (char letter) { // returns number on telephone represented by letter

    if(!isalpha(letter))
        return -1; 
    switch (tolower(letter))
    {
        case 'a':
        case 'b':
        case 'c':
            return 2; 
            
        case 'd':
        case 'e':
        case 'f':
            return 3; 
        
        case 'g':
        case 'h':
        case 'i':
            return 4; 
            
        case 'j':
        case 'k':
        case 'l':
            return 5; 
            
        case 'm':
        case 'n':
        case 'o':
            return 6; 
            
        case 'p':
        case 'q':
        case 'r':
        case 's':
            return 7; 
            
        case 't':
        case 'u':
        case 'v':
            return 8; 
            
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            return 9; 
        

    }
    
}