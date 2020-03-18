#include<iostream>
#include<vector>

using namespace std;


int sum( vector<int> v ){
	int add=0;
	if(v.size()==0)
		return 0;
	else
		for(unsigned i=0;i<v.size();i++)
			add+=v[i];
	return add;
}


int min( vector<int> v){
	int min=v[0];
	for(unsigned i=0; i<v.size();i++)
	  if(v[i]<min)
	  	min=v[i];
	return min;
}

int max( vector<int> v){

	int max=v[0];
	for(unsigned i=0;i<v.size();i++){
		if(max<v[i]){
			max=v[i];
	   }
	}
	return max;

}

float average( vector<int> v ){
	int add=0;
	for(unsigned i=0;i<v.size();i++)
		add+=v[i];
	return (float)add/v.size();
	
	
}


int main() {
	// Your code goes here
	int data;
	vector<int> v;
	while(cin>>data){
		v.push_back(data);
	}

	cout<<"count   = "<<v.size()<<endl;
	cout<<"minimum = "<<min(v)<<endl;
	cout<<"maximum = "<<max(v)<<endl;
	cout<<"sum     = "<<sum(v)<<endl;
	cout<<"average = "<<average(v)<<endl;

	return 0;
}
