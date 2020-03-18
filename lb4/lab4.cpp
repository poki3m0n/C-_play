//
//  lab4.cpp
//  
//
//  Created by Kritika Rana on 9/9/19.
//
#include<iostream>
#include<stdio.h>
#include"ArrayBag.h"
using namespace std;
int sum(vector<int> vec){
    int add = 0;
    for(unsigned i=0;i<vec.size();i++){

        add+= vec[i];
       // cout<<add<<"  "<<vec[i]<<endl;        
    }
    return add;
}


int main()
{
    
    ArrayBag<int> Bag;
    int data;
    int count=0;
    while (cin>>data) {
        //Bag.add(data);
        count++;
        if(Bag.add(data)==false)
            cout<<"Cannot add "<<data<< "; bag already has 30 items in it."<<endl;
        
        
    }
    vector<int> v;
    v = Bag.toVector();

    cout<<"The sum of the "<< Bag.getCurrentSize()<<" items in the bag is "<<sum(v)<<"."<<endl;

}

