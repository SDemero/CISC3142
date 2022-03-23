// This file shows basic functions of reading in a CSV file using C++98
// Samuel Demero 

/* Homework Objective: fix this program to match the requirements listed: 
  1. successfully reads all lines of the input file
  2. calculate the average price per brand, average price per category 
  3. writes to an output file
  4. for each unique year, list the count of skus and also print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.

All programs must be able to compile in C++98 standard (the default version on Linux Machine). That means you cannot use the new features of C++11! :(
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "file_in.h"

using namespace std;

int main() {

  // define variables
  string sku, brand, category, year, price; 
  vector<int>vSKU;
  vector<string>vBrand;
  vector<string>vCategory;
  vector<int>vYear;
  vector<float>vPrice;

  ifstream in_stream;
  in_stream.open("data.csv"); //opening the file.

  ofstream out_stream;
  out_stream.open("output.txt"); // opening output file

  if (!in_stream.fail()) { //if the file is open

    string line;
    getline(in_stream,line);

    while (getline(in_stream, line)) { //while the end of file is NOT reached

     // Fields: sku,brand,category,year,price

     stringstream line2(line);

     getline(line2, sku, ',');
     stringstream ssku(sku); 
     int iSKU = 0;
     ssku >> iSKU;
     vSKU.push_back(iSKU);

     getline(line2, brand, ',');
     vBrand.push_back(brand);

     getline(line2, category, ',');
     vCategory.push_back(category);

     getline(line2, year, ','); 
     stringstream syear(year);
     int iYear;
     syear >> iYear;
     vYear.push_back(iYear);

     getline(line2, price, '\n'); 
     stringstream sprice(price);
     float fPrice;
     sprice >> fPrice;
     vPrice.push_back(fPrice);
     
    }

    in_stream.close(); //closing the file cout << "Number of entries: " << i-1 << endl;

   } else {
    cout << "Unable to open file"; 
   }
 
  //output values
  out_stream << "SKU" << "\t" << "Brand" << "\t" << "Category"<< "\t" << "Year" << "\t"<< "Price" << endl; 

  for (int j = 0; j < vBrand.size(); j++) {
    out_stream << vSKU[j] << "\t" << vBrand[j] << "         " << vCategory[j] << "\t    " << vYear[j] << "\t " << vPrice[j] << endl;
  }

  pricePerBrand(vBrand,vSKU,vPrice,out_stream);
  pricePerCategory(vCategory,vSKU,vPrice,out_stream);
 // skuPerYear(vSKU,vYear,out_stream);
  skuPerYear2(vSKU,vYear,out_stream);

  

  

  cout << endl;


  

}


void pricePerBrand(vector<string>vBrand,vector<int>vSKU, vector<float>vPrice, ofstream& out_stream)
{
  int count=0; 
  float total=0;
  vector<string>brandList;
  brandList.push_back("ABC");
  brandList.push_back("XYZ");


  for(int x=0;x<brandList.size(); x++){ //goes through list comapers them with unique brand names and finds average
    for(int j=0;j<vSKU.size();j++){
    if(vBrand[j] == brandList[x]){
      count=count+1;
      total=total+vPrice[j];
      }
    }
    float average=total/count;
  out_stream <<"Average price for "<< brandList[x]<< " is $"<<average<<endl;
  }
  out_stream << endl;
}

void pricePerCategory(vector<string>vCategorey, vector<int>vSKU, vector<float>vPrice, ofstream& out_stream)
{
  int count=0; 
  float total=0;
  vector<string>catList;
  catList.push_back("A");
  catList.push_back("B");
  catList.push_back("C");



  for(int x=0;x<catList.size(); x++){ //goes through list comapers them with unique brand names and finds average
    for(int j=0;j<vSKU.size();j++){
    if(vCategorey[j] == catList[x]){
      count=count+1;
      total=total+vPrice[j];
      }
    }
    float average=total/count;
  out_stream <<"Average price for Categorey "<< catList[x]<< " is $"<<average<<endl;
  }
  out_stream << endl;
}

void skuPerYear(vector<int>vSKU, vector<int>vYear, ofstream& out_stream)
{
  int count=0; 
  float total=0;
  vector<int>year;
  vector<int>skuTtl;
  year.push_back(2000);
  year.push_back(2010);
  year.push_back(2020);



  for(int x=0;x<year.size(); x++){ //goes through list comapers them with unique brand names and finds average
    for(int j=0;j<vSKU.size();j++){
    if(vYear[j] == year[x]){
      count=count+1;
      
      }
    }
    skuTtl.push_back(count);
    count=0;
  out_stream << year[x]<< " ("<< skuTtl[x]<<"):"<<"\n";
  }
  out_stream << endl;

}

void skuPerYear2(vector<int>vSKU, vector<int>vYear, ofstream& out_stream)
{
  int count=0; 
  float total=0;
  vector<int>year;
  vector<int>skuTtl;
  year.push_back(2000);
  year.push_back(2010);
  year.push_back(2020);



  for(int x=0;x<year.size(); x++){ //goes through list comapers them with unique brand names and finds average
    for(int j=0;j<vSKU.size();j++){
    if(vYear[j] == year[x]){
      skuTtl.push_back(vSKU[j]);
      
      }
    }
  out_stream << year[x]<< " ("<< skuTtl.size()<< "): ";
  for(int t = 0; t < skuTtl.size(); t++){
    out_stream << skuTtl[t] << ",";

  }
  out_stream << "\n";
  skuTtl.clear();
  }
  out_stream << endl;

}