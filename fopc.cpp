//
//  ifElse.cpp
//  C++ stdc++
//
//  Created by Amal Saeed on 2/28/16.
//  Copyright © 2016 Amal Saeed. All rights reserved.
//

#include "ifElse.hpp"
#include <iostream>
using namespace std;

int main() {
    
    //One-Condition IF-ELSE
    
    int clouds = 70;
    
    if (clouds > 50) {
        cout<<"There are many clouds out today.\n";
    } else {
        cout<<"There aren't many clouds out today.\n";
    }
    
    cout << "There are about " << clouds <<" out today.\n"<< endl;

    
    //Multi-conditional IF-ELSE
    
    /* int clouds = 35;
    bool cloudy(false);
    if (cloudy==false) {
        if (clouds > (30) || clouds < 50) {
            cout<<"There are a handful of clouds out today.\n";
        } else {
            cout<<"There aren't many clouds out today.\n";
        }
    }*/
    
    
    //WHILE LOOP
    
    /* int number, sum = 0;  // can declare and initialize multiple variables (of the same type) in one line
    
    while (true) {     // will always be true
        cout<<"Enter a number: ";
        cin>>number;  // user input
        
        if (number != 0) {
            sum += number;
        }
        else {
            break;    // terminates the loop if number = 0
        }
        
    }
    cout<<"Sum = "<<sum;*/
    
    
    //FOR LOOP
    
    /* for (int i = 1; i <= 10; ++i) {
        if ( i == == 9) {
            continue;
            cout<<"7 ate 9!";  // continue; causes the loop to skip printing out when i=9
        }
        cout<<i<<"\t";  // puts a tab between each number printed
    }*/
    
    
    //DO WHILE LOOP
    
    /* int x = 0;
     do {
        cout<<x <<endl;
        x++;  // increments x
     }
     while(x < 6);  // stops printing after 5
     */
    
    
    //SWITCH/ CASE STATEMENT
    
    /*
     int menuChoice = 3;
     switch(menuChoice) {
        default:
        cout<<"You have the menu.\n";  // this is the default case
     case 1:
        cout<<"You chose 1!\n";
        break;  // C++ requires the break statement, otherwise, it will continue executing the statements 
                    //in the following cases until it finds another break;
     case 2:
        cout<<"Fritatas it is.\n";
        break;
     case 3:
        cout<<"Breakfast for dinner!\n";
        break;
     }
     cout<<"You have exited the switch statement.\n";
    */
    
    

    return 0;
}
