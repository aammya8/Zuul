
//------------------------------------------------------------MAIN CLASS------------------------------------------------------------

#include "room.h"
#include <utility>
#include <cstring>

using namespace std;


//function prototypes
void showExits(Room* room_ptr);
void showItems(vector<Item*> v);
void roomInfo(Room* room_ptr);
bool checkWin(Room* room_ptr);

//global variables declaration
vector<Room*> vect; //vector of Room pointers
vector<Item*> player_inventory; //vector of Item pointers



int main() { //START OF MAIN FUNCTION

	char name[50]; //name of room
    char description[500]; //room description
	char item[50]; //item in room

	//--------------------------------------CREATE ROOMS AND SET ITEMS--------------------------------------
	
    //Room #1 (START): Parking Lot
    strcpy(name, "Parking Lot");
    strcpy(description, "You need to work on your parking skills. Your car is taking up three parking spaces.");
	strcpy(item, "$100 Bill");
	Room* parking_lot = new Room(name, description, item);
	vect.push_back(parking_lot);

	Room* current_ptr = parking_lot; //current_ptr stores current location (room)

    //Room #2: Clothing Store
	strcpy(name, "Clothing Store");
    strcpy(description, "Do you need an outfit for the party? Perfect! Welcome to Zuul Mall's high-fashion clothing store.");
    strcpy(item, "Teletubby Suit");
    Room* clothing_store = new Room(name, description, item);
    vect.push_back(clothing_store);

    //Room #3: Pet Store
	strcpy(name, "Pet Store");
    strcpy(description, "Looking for a gift? You're at the right place! Pick up a pet :)");
    strcpy(item, "Elephant");
    Room* pet_store = new Room(name, description, item);
    vect.push_back(pet_store);

    //Room #4: Planet Fitness
    strcpy(name, "Planet Fitness");
	strcpy(description, "Trying to get in shape? Very nice. We at Planet Fitness support that movement. Do pick up a snack on your way out :D");
    strcpy(item, "French Fries");
	Room* planet_fitness = new Room(name, description, item);
	vect.push_back(planet_fitness);

    //Room #5: Apple Store
    strcpy(name, "Apple Store");
	strcpy(description, "Don't steal the iPads please.");
	strcpy(item, "Apple");
	Room* apple_store = new Room(name, description, item);
	vect.push_back(apple_store);

    //Room #6: Laser Tag
	strcpy(name, "Laser Tag");
    strcpy(description, "It sounds so deathly.");
    Room* laser_tag = new Room(name, description, item);
    vect.push_back(laser_tag);

    //Room #7: Tesla Store
	strcpy(name, "Tesla Store");
    strcpy(description, "Here's some hand sanitizer for your greasy hands. Please be careful around the cars. We're proud to say that our new model costs more than your house :)");
    strcpy(item, "Air");
    Room* tesla_store = new Room(name, description, item);
    vect.push_back(tesla_store);

    //Room #8: Bubble Tea Store
    strcpy(name, "Bubble Tea Shop");
	strcpy(description, "Yeehaw diabetes. Please do not get above 50 percent sweetness (disgusting, headache, nausea) *shudder*");
	strcpy(item, "Ice");
	Room* bubble_tea_shop = new Room(name, description, item);
	vect.push_back(bubble_tea_shop);

    //Room #9: Jewelry Store
    strcpy(name, "Jewelry Store");
	strcpy(description, "You're too broke for this. Please step away skrrt skrrt. SeCuRiTY!!! Nice to meet you, though!");
	strcpy(item, "HEHEHEHE secret item");
	Room* jewelry_store = new Room(name, description, item); 
	vect.push_back(jewelry_store);

    //Room #10: Build-a-Friend Store
    strcpy(name, "Build-a-Friend Store");
	strcpy(description, "How sad. Have no friends? Do not fear, you are now in the Build-a-Friend Store! Now you can pretend to not be lonely. Our products are very realistic.");
    strcpy(item, "Fire Lord Ozai");
	Room* build_a_friend_store = new Room(name, description, item); 
	vect.push_back(build_a_friend_store);

    //Room #11: Indoor Football Field
    strcpy(name, "Indoor Football Field");
	strcpy(description, "Wow! Look at them go! Imagine running when walking is already so difficult");
	Room* indoor_football_field = new Room(name, description, item); 
	vect.push_back(indoor_football_field);

    //Room #12: Movie Theater
	strcpy(name, "Movie Theater");
    strcpy(description, "Our popcorn does not taste like styrofoam. Come watch a movie! Mission Impossible 1295827 is playing in 10 minutes!");
    Room* movie_theater = new Room(name, description, item); 
    vect.push_back(movie_theater);

    //Room #13: Vinyl Store
    strcpy(name, "Vinyl");
	strcpy(description, "Manifesting a Frank Ocean album :_) Not the \"Blonde\" Vinyl selling for $200 smh.");
	strcpy(item, "\"Blonde\" Vinyl");
	Room* vinyl_store = new Room(name, description, item);
	vect.push_back(vinyl_store);

    //Room #14: Ice Skating Rink
	strcpy(name, "Ice Skating Rink");
    strcpy(description, "You'll love it here! How entertaining it is to watch people skate for the first time.");
    Room* ice_skating_rink = new Room(name, description, item); 
    vect.push_back(ice_skating_rink);

    //Room #15 (END): VIP Restaraunt
    strcpy(name, "VIP Restaraunt");
	strcpy(description, "Finally! You made it to the birthday party!");
	strcpy(item, "Picture with the President");
	Room* vip_restaurant = new Room(name, description, item);
	vect.push_back(vip_restaurant);



    //--------------------------------------CREATE EXITS (NORTH, EAST, SOUTH, WEST)--------------------------------------

    char* direction = new char(5);

    strcpy(direction, "EAST");
    parking_lot->setExit(direction, clothing_store);
    clothing_store->setExit(direction, laser_tag);
    laser_tag->setExit(direction, bubble_tea_shop);
    pet_store->setExit(direction, planet_fitness);
    planet_fitness->setExit(direction, apple_store);
    apple_store->setExit(direction, tesla_store);
    tesla_store->setExit(direction, movie_theater);
    build_a_friend_store->setExit(direction, vip_restaurant);
    vip_restaurant->setExit(direction, vinyl_store);
    
    strcpy(direction, "WEST");
    bubble_tea_shop->setExit(direction, laser_tag);
    laser_tag->setExit(direction, clothing_store);
    clothing_store->setExit(direction, parking_lot);
    movie_theater->setExit(direction, tesla_store);
    tesla_store->setExit(direction, apple_store);
    apple_store->setExit(direction, planet_fitness);
    planet_fitness->setExit(direction, pet_store);
    vinyl_store->setExit(direction, vip_restaurant);
    vip_restaurant->setExit(direction, build_a_friend_store);

    strcpy(direction, "NORTH");
    jewelry_store->setExit(direction, pet_store);
    pet_store->setExit(direction, parking_lot);
    build_a_friend_store->setExit(direction, planet_fitness);
    planet_fitness->setExit(direction, clothing_store);
    apple_store->setExit(direction, laser_tag);
    ice_skating_rink->setExit(direction, vinyl_store);
    vinyl_store->setExit(direction, tesla_store);
    bubble_tea_shop->setExit(direction, indoor_football_field);

    strcpy(direction, "SOUTH");
    indoor_football_field->setExit(direction, bubble_tea_shop);
    tesla_store->setExit(direction, vinyl_store);
    vinyl_store->setExit(direction, ice_skating_rink);
    laser_tag->setExit(direction, apple_store);
    clothing_store->setExit(direction, planet_fitness);
    planet_fitness->setExit(direction, build_a_friend_store);
    parking_lot->setExit(direction, pet_store);
    pet_store->setExit(direction, jewelry_store);



    //---------------------------------------------PLAY GAME---------------------------------------------

    bool playing = true;
    char* input = new char[10];

    cout << "Welcome to Zuul Mall! You have been invited to a birthday party in the VIP Restaurant! Get ready for the party and collect 5 certain items on your way there!" << endl;
    //print instructions
    cout << "COMMANDS KEY:" << endl;
    cout << "\'MOVE\': go to another room." << endl;
    cout << "\'PICK\': pick up the item in the room." << endl;
    cout << "\'PRINT\': print out your inventory (of items)." << endl;
    cout << "\'QUIT\': quit." << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    

    while (playing) {
        cout << '\n';
    	roomInfo(current_ptr); //print room information
    	cout << "Enter a command (\'MOVE\', \'PICK\', \'PRINT\', \'QUIT\')" << endl;
    	cin.getline(input, 10, '\n');

    	if (strcmp(input, "MOVE") == 0) { //move to another room
    		cout << "Which exit would you like to take?: ";
    		showExits(current_ptr);
    		cin.getline(input, 10, '\n');
    		current_ptr->move(input, current_ptr);
    	}
    	else if (strcmp(input, "PICK") == 0) { //pick up item in room 
    		if(player_inventory.size() <= 5) { //can only have a maximum of 5 items in inventory
    			cout << "Which item would you like to pick up?: ";
    			showItems(current_ptr->items);
    			cin.getline(input, 50,'\n');
    			Item* item_ptr = current_ptr->removeItem(input); //add item to inventory vector and remove from room vector
                if (item_ptr != NULL) { //check to see if item exists in room
    				player_inventory.push_back(item_ptr);
    			}
    			else {
    				cout << "This item does not exist in this room." << endl;
    			}
    		}	
    		else {
    			cout << "Your hands are already full! Drop an item and try again!" << endl;
    		}
    	}
    	else if (strcmp(input, "DROP") == 0) { //drop item 
    		cout << "Which item would you like to drop?: ";
    		showItems(player_inventory);
    		cin.getline(input, 50, '\n');
    		if (current_ptr->addItem(player_inventory, input)) {
    			cout << input << " has been dropped.";
    		}
    		else {
    			cout << input << " does not exist in your inventory." << endl;
    		}
    	}
    	else if (strcmp(input, "PRINT") == 0) { //print inventory
    		cout << "You are currently holding the following items: ";
    		showItems(player_inventory);
    	}
    	else if (strcmp(input, "QUIT") == 0) { //quit playing
    		playing = false;
            cout << "Okay. Bye." << endl;
    	}
    	else {
    		cout << "Invalid input. Please enter either \'MOVE\', \'PICK\', \'PRINT\', or \'QUIT\'." << endl;
    	}
    	
        //check current location to see if player has won (final destination has been reached and correct items have been collected)
    	if (checkWin(current_ptr) == true) {
    		cout << "Finally! You have all the right items. Don't trip over the Teletubby Suit and fall on your face in front of the VIPs. It would be very embarrasing." << endl;
    		cout << "Oops look at those security guards running towards you. That can't be good." << endl;
            cout << "Did you accidentally steal something from the jewelry store. How unfortunate. Time to skrrt from the party already." << endl;
            cout << "Probably won't be getting a picture with the president now :/ Run Run Run don't wanna end up in jail. Bye (:" << endl;
            cout << "Thanks for playing Zuul. The Mall will be quieter without you :D" << endl;
    		playing = false;
    	}
    }


    //--------------------------------------DELETE ROOM VECTOR AND ITEMS--------------------------------------
    while (!vect.empty()) {
        Room* room_ptr = vect.back();
        vect.pop_back();
        delete room_ptr;
    }
    while (!player_inventory.empty()) {
        Item* item_ptr = player_inventory.back();
        player_inventory.pop_back();
        delete item_ptr;
    }

	return 0;
} // END OF MAIN FUNCTION





//function to print items in room
void showItems(vector<Item*> v) {
	for(vector<Item*>::iterator it = v.begin(); it!= v.end(); it++) {
		cout << (*it)->getName() << endl;
	}
	 if ((v).empty()) {
        cout << "NO ITEMS" << endl;
    }
}


//function to print exits
void showExits(Room* room_ptr) {
    for (auto& x : room_ptr->exits) {
        cout << x.first << " ";
    }
    cout << endl;
}


//function to print room information
void roomInfo(Room* room_ptr) {
	cout << "YOU ARE AT THE: " << room_ptr->getName() << endl;
	cout << room_ptr->description << endl;
	cout << "ITEMS IN ROOM: ";
	showItems(room_ptr->items);
	cout << "EXITS: " ;
	showExits(room_ptr);
}


//function to check if player has won
bool checkWin(Room* room_ptr) {
	int count = 0;
	//check if player has all 5 required items in inventory
	for (vector<Item*>::iterator it = player_inventory.begin(); it != player_inventory.end(); it++) {
		if (strcmp((*it)->getName(), "Elephant") == 0){
			count++;
		} 
		if (strcmp((*it)->getName(), "Teletubby Suit") == 0){
			count++;
		} 
		if (strcmp((*it)->getName(), "Fire Lord Ozai") == 0){
			count++;
		} 
		if (strcmp((*it)->getName(), "HEHEHEHE secret item") == 0){
			count++;
		} 
        if (strcmp((*it)->getName(), "Air") == 0){
            count++;
        } 
	}
    //check if player is in correct room
	if (count == 5 && strcmp(room_ptr->getName(), "VIP Restaraunt") == 0) {
		return true;
	}
	else {
		return false;
	}

}