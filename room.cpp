
//------------------------------------------------------------ROOM CLASS------------------------------------------------------------

#include "room.h"
#include <utility>
#include <cstring>

using namespace std;



//constructor for room with item(s)
Room::Room(char* name_, char* description_, char* item_) {
	name = new char[strlen(name_)];  
	strcpy(name, name_);
	description = new char[strlen(description_)];
	strcpy(description, description_);
	Item* item = new Item();
	item->name = new char[strlen(item_)]; 
	strcpy(item->name, item_);
	items.push_back(item);
}


//constructor for room with no item(s)
Room::Room(char* name_n, char* description_n) {
	name = new char[strlen(name_n)]; 
	strcpy(name, name_n);
	description = new char[strlen(description_n)];
	strcpy(description, description_n);
}


//destructor
Room::~Room() {
	if (name != NULL) {
		delete name;
	}
	if (description != NULL) {
		delete description;
	}
	if (!items.empty()) {
		items.clear();
	}
}


char* Room::getName() {
  return name;
}



//function to add an exit to a room
void Room::setExit(char* dir, Room* room) {
  char* direction = new char[strlen(dir)];
  strcpy(direction, dir);
  exits.insert(make_pair(direction, room)); //make_pair inserts direction and room into map as a pair
}



//function to move pointer to the room in direction chosen by user
void Room::move(char* direction, Room* &room_ptr) { 
	bool moved = false;
	for (auto& map : exits) {
		if(strcmp(map.first, direction) == 0) {
			room_ptr = map.second;
			moved = true;
		}
	}
	if (moved == false) {
		cout << "An exit does not exist in that direction." << endl;
	}
}



//function to add item from player inventory to room's item vector
bool Room::addItem(vector<Item*> &vect, char* item) {
	  for (vector<Item*>::iterator it = vect.begin(); it != vect.end(); it++) {
        if(strcmp((*it)->getName(), item) == 0) {
        	items.push_back(*it);
        	vect.erase(it);
        	return true;
        	break;
        }
    }
    return false;
}



//function to remove item from room's item vector and return item
Item* Room::removeItem(char* item) {
	for (vector<Item*>::iterator it = (items).begin(); it != (items).end(); ++it) {
		if (strcmp((*it)->getName(), item) == 0) {
			Item* ptr = *it;
			items.erase(it);
			return ptr;
			break;
		}
	}
	return NULL;
}