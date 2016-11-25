#include <iostream>
#include <unistd.h>

using namespace std;

const char keys[] = "abcdefghijklmnopqrstuvwxyz .,!?";

int main(){
	
	int num_monkeys;
	string text;
	cout << "Welcome to a roomfull of monkeys on typewriters simulator 2016. Let's bruteforce some Shakesphere!"<< endl;

	cout << "What would you like them to type?"<<endl;
	getline(cin,text);	

	cout << "STARTING MONKEYS"<<endl;

	int current_longest=0;
	int random_num;
	bool completed = false;
	int attempts = 0;
		while(!completed){
			bool correct = true;
			int current_char_pos = 0;
			attempts ++;
			while(correct){
				random_num = rand()% sizeof(keys);
				if(keys[random_num] == text.at(current_char_pos)){
					current_char_pos += 1;
					if (current_char_pos == text.length()){
						completed = true;
						cout << text << endl;
						cout << "The monkeys have completed your work!";
						break;
					}


				}else {
					correct = false;
					if(current_char_pos > current_longest){
						current_longest = current_char_pos;
						cout << text.substr(0,current_longest)<< " written in "<< attempts << " attempts"<< endl;
					}



				}
			}

		}
	

}
