

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <list>
#include <vector>

#define CS45 0.70710678118f;
#define SN45 0.70710678118f;

using namespace std;

void print_curve(list<pair<float,float> > curve);
void fold_curve(list<pair<float,float> >& curve,int position);


list<pair<float,float> > curve; 



int main(int argc, char* argv[]){
	int iterations=5;
	
	if(argc>1){
		sscanf(argv[1], "%d" , &iterations);
	}	



	curve.push_back(make_pair((float)0,(float)0));
	curve.push_back(make_pair((float)1,(float)0));

	for(int i = 0; i < iterations ; i++){
		int size = curve.size();
		for(int j = 0; j < size-1; j++){
			fold_curve(curve,j*2);
		}
	}
	print_curve(curve);
	


}

void print_curve(list<pair<float,float> > curve){
	list<pair<float,float> >::const_iterator iterator;
	for (iterator = curve.begin(); iterator != curve.end(); ++iterator) {
	    cout <<  iterator->first << "\t"<< iterator->second<< endl;
}
}
void fold_curve(list<pair<float,float> >& curve,int position){
		list<pair<float,float> >::const_iterator iterator = curve.begin();
		advance(iterator, position);
		float x1 = iterator->first;
		float y1 = iterator->second;
		advance(iterator, 1);
		float x2 = iterator->first;
		float y2 = iterator->second;
		float connect_vect_x = x2 - x1;
		float connect_vect_y = y2 - y1;
		float new_x = x1 +( ((position/2)%2==0)?(connect_vect_x - connect_vect_y):(connect_vect_x + connect_vect_y) ) * 0.5; 
		float new_y = y1 +( ((position/2)%2==0)?(connect_vect_x + connect_vect_y):(-connect_vect_x + connect_vect_y) ) * 0.5;		
		curve.insert(iterator,make_pair(new_x,new_y));
}
