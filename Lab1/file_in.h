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
