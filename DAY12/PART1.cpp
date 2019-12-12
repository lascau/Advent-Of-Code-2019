#include <bits/stdc++.h>

using namespace std;

int main() {
	tuple<int, int, int> coordinates[4];
	tuple<int, int, int> velocity[4];
	int kinetic_energy[4] = {0};
	int potential_energy[4] = {0};
	int total_energy = 0;
 
    coordinates[0] = make_tuple(-6,   2,  -9); 
    coordinates[1] = make_tuple( 12, -14, -4); 
    coordinates[2] = make_tuple( 9,  5,  -6); 
    coordinates[3] = make_tuple( -1,   -4, 9);
    
	velocity[0] = make_tuple( 0,   0,  0); 
    velocity[1] = make_tuple( 0,   0,  0); 
    velocity[2] = make_tuple( 0,   0,  0); 
	velocity[3] = make_tuple( 0,   0,  0);
    
    for (int step = 1; step <= 1000; ++step) {
    	for (int i = 0; i < 4; ++i) {
    		for (int j = i + 1; j < 4; ++j) {
    			//x
    			if (get<0>(coordinates[i]) < get<0>(coordinates[j])) {
    				++get<0>(velocity[i]);
    				--get<0>(velocity[j]);
    			} else if (get<0>(coordinates[i]) > get<0>(coordinates[j])) {
    				--get<0>(velocity[i]);
    				++get<0>(velocity[j]);
    			}
    			//y
    			if (get<1>(coordinates[i]) < get<1>(coordinates[j])) {
    				++get<1>(velocity[i]);
    				--get<1>(velocity[j]);
    			} else if (get<1>(coordinates[i]) > get<1>(coordinates[j])) {
    				--get<1>(velocity[i]);
    				++get<1>(velocity[j]);
    			}
    			//z
    			if (get<2>(coordinates[i]) < get<2>(coordinates[j])) {
    				++get<2>(velocity[i]);
    				--get<2>(velocity[j]);
    			} else if (get<2>(coordinates[i]) > get<2>(coordinates[j])) {
    				--get<2>(velocity[i]);
    				++get<2>(velocity[j]);
    			}
    		}

    	}
    	for (int planet = 0; planet < 4; ++planet) {
    		get<0>(coordinates[planet]) = 	get<0>(coordinates[planet]) + get<0>(velocity[planet]);
    		get<1>(coordinates[planet]) = 	get<1>(coordinates[planet]) + get<1>(velocity[planet]);
			get<2>(coordinates[planet]) = 	get<2>(coordinates[planet]) + get<2>(velocity[planet]);
    	}
    	for (int planet = 0; planet < 4; ++planet) {
    		potential_energy[planet] = abs(get<0>(coordinates[planet])) + abs(get<1>(coordinates[planet])) + abs(get<2>(coordinates[planet]));
    	}
    	for (int planet = 0; planet < 4; ++planet) {
    		kinetic_energy[planet] = abs(get<0>(velocity[planet])) + abs(get<1>(velocity[planet])) + abs(get<2>(velocity[planet]));
    	}
    	/*
    	//debug
    	cout << "After step " << step << "\n";
    	for (int planet = 0; planet < 4; ++planet) {
    		cout << "pos = (" << get<0>(coordinates[planet]) << ' ' <<get<1>(coordinates[planet]) << " " 
    			 << get<2>(coordinates[planet]);
    		cout << ")    vel = (" << get<0>(velocity[planet]) << ' ' <<   get<1>(velocity[planet]) << " " 
    			 <<  get<2>(velocity[planet]);
    		cout << ")\n";
    	}
    	*/
    }
    for (int planet = 0; planet < 4; ++planet) {
    	total_energy += potential_energy[planet] * kinetic_energy[planet]; 
    }
    cout << total_energy;
	return 0;
}