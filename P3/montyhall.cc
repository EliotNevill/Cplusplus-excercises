
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
	int N=10,num_doors = 3, estimate, switch_wins = 0, stick_wins = 0;
	
	if(argc>1){
		sscanf(argv[1], "%d" , &N);
	}	
	if(argc>2){
		sscanf(argv[2], "%d" , &num_doors);
	}
	
	for(int n=1; n<=N; n++){
		vector<bool> doors (num_doors,false);
		//Car placed in position
		doors[rand()%doors.size()] = true;
		//Contestant chooses a door
		int first_choice = rand()%doors.size();	
		//Monty Hall removes a door
		while(true){
			int rand_pos =rand()%doors.size();
			if(!doors[rand_pos] && rand_pos != first_choice){
			cout << doors.size();
				doors.erase(doors.begin() + rand_pos);
			cout << doors.size();
				break;			
			}
		}
		int switch_choice;
		while(true){
		switch_choice = rand()%doors.size();
			if(switch_choice != first_choice){
			 break;
			}
		}
		switch_wins += doors[switch_choice]? 1 :0;
		stick_wins += doors[first_choice]? 1 :0;
		cout << "Trials: "<< n<< "\tStick: "<< stick_wins<< " "<< (double)stick_wins/n << "% \tSwitch: "<< switch_wins<<" " << (double)switch_wins/n << "%" << endl;
	}
		
		
		
 




}
