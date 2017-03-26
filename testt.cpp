#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <unistd.h> //Import the sleep function (only works with linux compiler)
#include <thread>
#include <chrono>
#include <future>

using namespace std::chrono;

int efficiency_calculation(int, int, bool);

void battle_processor(std::vector<std::string>, long, long, long, long, int, int, int);

int randRange(int low, int high){
    return rand() % high + low;
}

bool turn_assignment(int);

void metallurgy(long _metalamount, long _drones, long _specimens, long _armors, long _missiles, long _bombs, int counter){
    int choice;
    int amount;
    while(1){
        std::cout<<"\n"
        <<"\n"
        <<"<--METALLURGY LABORATORY-->"<<"\n"
        <<"\n"
        <<"Metal: "<<_metalamount<<"\n"
        <<"\n"
        <<"Specimens: "<<_specimens<<"\n"
        <<"1. Drones factory"<<"\n"
        <<"2. Cyborg's armors and weapons"<<"\n"
        <<"3. Bombs\n"
        <<"4. Missiles\n"
        <<"5. Exit" <<std::endl;
        std::cin>>choice;
    }
        switch(choice){

            case 1:
                    std::cout<<std::endl;
                    std::cout<<"Tell us how many drones you want to create my lord!"<<"\n"
                    <<"Drone's price: 17"<<"\n"
                    <<"Metal: "<<_metalamount<<std::endl;
                    std::cin>>amount;
                    if(_metalamount == 0){
                        std::cout<<"Lord! our metal reserves are fully empty we must extract minerals from a nearby planet"<<std::endl;
                        break;
                    }
                    else if(_metalamount < 25 * amount){
                        while(1){
                            if(_metalamount > amount * 25)
                                break;
                            std::cout<<"Lord! you don't have that much metal yet"<<"\n"
                            <<"Type in a smaller amount!"<<std::endl;
                            std::cin>>amount;
                        }
                        usleep(efficiency_calculation(amount, 1000, false));
                        _metalamount -= amount * 25;
                        _drones += amount;
                        if(_specimens < _drones){
                            std::cout<<"Unfortunately my lord, you still don't have enough specimens to be armed with so many weapons"<<std::endl;
                            _drones -= amount;
                            break;
                        }
                        else if(_specimens >= _drones){
                            _specimens -= _drones;
                            std::cout<<"Our drones will fly the enemy's sky and cause the greatest fear in its soul.."<<std::endl;
                            break;
                        }
                    }
                    else if(amount == 0)
                        break;
                    else if(_metalamount > amount * 25){
                        usleep(efficiency_calculation(amount, randRange(1, 2), false));
                        _metalamount -= amount * 25;
                        _drones += amount;
                        if(_specimens < _drones){
                            std::cout<<"Unfortunately my lord, you still don't have enough specimens to be armed with so many weapons"<<std::endl;
                            _drones -= amount;
                            break;
                        }
                        else if(_specimens >= _drones){
                            _specimens -= _drones;
                            std::cout<<"Our drones will fly the enemy's sky and cause the greatest fear in its soul.."<<std::endl;
                            break;
                        }

                    }
                    break;


            case 2:
                    std::cout<<std::endl;
                    std::cout<<"Metal: "<<_metalamount<<"\n"
                    <<"Armor's price: "<<"17"<<"\n"
                    <<"\n"<<std::endl;
                    std::cout<<"How many armors and weapons?"<<std::endl;
                    std::cin>>amount;
                    if(_metalamount == 0){
                        std::cout<<"Lord! our metal reserves are fully empty we must extract minerals from a nearby planet"<<std::endl;
                        break;
                    }
                    else if(_metalamount < amount * 17){
                        while(1){
                            if(_metalamount < amount * 17)
                                break;
                            std::cout<<"Lord! you don't have that much metal yet"<<"\n"
                            <<"Type in a smaller amount!"<<std::endl;
                            std::cin>>choice;
                        }
                        usleep(efficiency_calculation(amount, 1000, false));
                        _metalamount -= amount * 17;
                        _armors += amount;
                        if(_specimens < _armors){
                            std::cout<<"Unfortunately my lord, you still don't have enough specimens to be armed with so many weapons"<<std::endl;
                            _armors -= amount;
                            break;
                        }
                        else if(_specimens >= _armors){
                            _specimens -= _armors;
                            std::cout<<"Oh yes my lord, this new armors are worth dying for!"<<std::endl;
                            break;
                        }

                    else if(choice == 0)
                        break;
                    else if(_metalamount > amount * 17){
                        usleep(efficiency_calculation(amount, 1000, false));
                        _metalamount -= amount * 17;
                        _armors += amount;
                        if(_specimens < _armors){
                            std::cout<<"Unfortunately my lord, you still don't have enough specimens to be armed with so many weapons"<<std::endl;
                            _armors -= amount;
                            break;
                        }
                        else if(_specimens >= _armors){
                            _specimens -= _armors;
                            std::cout<<"Oh yes my lord, this new armors are worth dying for!"<<std::endl;
                            break;
                        }
                    }
                    break;

            case 3:
                    std::cout<<std::endl;
                    std::cout<<"Metal: "<<_metalamount<<"\n"
                    <<"Bomb's price: "<<"10"<<"\n"
                    <<"\n"<<std::endl;
                    std::cout<<"How many bombs?"<<std::endl;
                    std::cin>>amount;
                    if(_metalamount == 0){
                        std::cout<<"Lord! our metal reserves are fully empty we must extract minerals from a nearby planet"<<std::endl;
                        break;
                    }
                    else if(_metalamount < amount * 10){
                        while(1){
                            if(_metalamount < amount * 10)
                                break;
                            std::cout<<"Lord! you don't have that much metal yet"<<"\n"
                            <<"Type in a smaller amount!"<<std::endl;
                            std::cin>>amount;
                        }
                        efficiency_calculation(amount, 1000, false);
                        _metalamount -= amount * 10;
                    _bombs += amount;
                    }
                    else if(amount == 0)
                        break;
                    else if(_metalamount > amount * 10){
                        efficiency_calculation(amount, 1000, false);
                        _metalamount -= amount * 10;
                        _bombs += amount;
                        }

                    break;
            case 4:
                    std::cout<<std::endl;
                    std::cout<<"Metal: "<<_metalamount<<"\n"
                    <<"Missile's price: "<<"10"<<"\n"
                    <<"\n"<<std::endl;
                    std::cout<<"How many missiles?"<<std::endl;
                    std::cin>>amount;
                    if(_metalamount == 0){
                        std::cout<<"Lord! our metal reserves are fully empty we must extract minerals from a nearby planet"<<std::endl;
                        break;
                    }
                    else if(_metalamount < amount * 10){
                        while(1){
                            if(_metalamount < amount * 10)
                                break;
                            std::cout<<"Lord! you don't have that much metal yet"<<"\n"
                            <<"Type in a smaller amount!"<<std::endl;
                            std::cin>>choice;
                        }
                        _metalamount -= amount * 10;
                        _missiles += amount;
                    }
                    else if(choice == 0)
                        break;
                    else if(_metalamount > amount * 10){
                        usleep(efficiency_calculation(amount, randRange(1, 2), false));
                        _metalamount -= amount * 10;
                        _missiles += amount;
                    }
                    break;

            case 5: break;
        }
        break;
    }
}

void damage_calculation(std::vector<std::string> balance, std::string attack_type, int amount, float hp, int level, long civilians, int morale, int counter){
    int _soldierslevel;
    if(level == 5)
        _soldierslevel = 5;
    float total_damage;
    float total_hp;
    long targets;
    int random_civilians_casualties = randRange(1000, 10000);
    int morale_effect;
    bool battle;
    if(attack_type == "Civilians attack"){
        for(int i = 0; i < amount; i++){
            civilians -= 1;
        }
        morale_effect = efficiency_calculation(amount, randRange(1, 2), true);
        morale -= morale_effect;
    }
    else if(attack_type == "Cyborgs attack"){
        total_damage = amount * 50 * level - morale;
        targets = std::ceil(total_damage/hp);
        civilians -= random_civilians_casualties;
        if(turn_assignment(counter))
            battle_processor(balance, 0, targets, 0, targets, level, _soldierslevel, counter);
        else
            battle_processor(balance, 0, targets, 0, 0, level, _soldierslevel, counter);
    }
    else if(attack_type == "Missiles attack"){
        total_damage = amount * 50 * level - morale;
        targets = std::ceil(total_damage/hp);
        civilians -= random_civilians_casualties;
        if(turn_assignment(counter))
            battle_processor(balance, targets, 0, targets, 0, level, _soldierslevel, counter);
        else
            battle_processor(balance, targets, 0, targets, 0, level, _soldierslevel, counter);
    }
    else if(attack_type == "Drone bombardment"){
        total_damage = amount * 50 * level - morale;
        targets = std::ceil(total_damage/hp);
        civilians -= random_civilians_casualties;
        if(turn_assignment(counter))
            battle_processor(balance, targets, 0, 0, targets, level, _soldierslevel, counter);
        else
            battle_processor(balance, 0, targets, 0, targets, level, _soldierslevel, counter);
    }
}

bool turn_assignment(int counter){
    if(counter % 2)
        return false;
    else
        return true;
}

void decision_maker(int choice, long arsenal1, long arsenal2, long enemies_metal, long enemies_energy, float relative_difference, float marginal_loss, bool arsenal1_or_arsenal2){
    int selection; //The production choice that will be passed into metallurgy
    if(arsenal1 - arsenal2 <= relative_difference){   //If the difference between both arsenals is greater than the average casualties per battle
            if(arsenal1 <= relative_difference){     //If the AI has lost more men than there are elements within the arsenal
                if(enemies_energy > 500000){        //If the AI has more than enough energy
                    if(arsenal1_or_arsenal2){       //If the AI has a specific preference for one arsenal or the other
                        choice = 1;                 //This function will also be used for missiles and bombs
                    }
                    else{
                        choice = 2;
                    }
                }
                else{
                    choice = 2; //More drones need to be produced, the metallurgy function will be called!
                }
            }
            else{                                //Since there is more of that item than there have been deaths, the ratio is good so the AI produces more of the other item
                if(enemies_energy > 500000){ //If the AI has more than enough energy
                    if(arsenal1_or_arsenal2){ //If it has a preference for one over the other because there is more of one item than the other
                        choice = 1;             //Note this decision may lead to errors in the sense it might not be the most optimal but the AI can make mistakes too
                    }                           //as long as they are controlled
                    else{
                        choice = 2;
                    }
                } //Else we don't want to waste energy so we will try to optimise by spending metal instead then energy will hopefully be updated positively in the next iteration
                if(30 > marginal_loss){  //If we have more metal than the total amount of metal we lost 30 is the average price of an item in the metallurgy laboratory
                    choice = 2;         //We can afford Drones/Cyborgs!
                }
                else{
                    choice = randRange(1, 2); //Else the AI is fucked so it will choose either one or two randomly
                }
            }
        }
        else
            if(arsenal1_or_arsenal2)
                choice = 1;
            else
                choice = 2;

}

void battle_end(int count, std::string final_outcome){
    //It will give the final battle reports
    //It should take deaths as a parameter as well as casualties and all the resources that have been wasted
    //The amount of battles during the war
    //It will take morale as a parameter and print a message in a tone that suits the soldiers' mood !

}

void balance_counter(std::vector<std::string> balance, bool end_battle, bool turn){
    int counter;
    for(int i = 0; i < balance.size(); i++){
        if(balance[i] == "Defeat")
            counter += 1;
        continue;
    }
    if(!turn){ //If it's the AI's turn
        if(counter >= balance.size()/2){
            battle_end(counter, "Victory");
            end_battle = true; //More user's defeats mean that the machine was closer to winning than the player but lacked resources
        }
        else{
            battle_end(counter, "Defeat");
            end_battle = true; //More user's victories mean that the machine was really far from a victory
        }
    }
    else{ //If it's the user's turn
        if(counter >= balance.size()/2){
            battle_end(counter, "Defeat"); //Inputs are inverted according to the turn variable
            end_battle = true;
        }
        else{
            battle_end(counter, "Victory");
            end_battle = true;
        }
    }
}

void check_victory(std::vector<std::string> balance, long enemy_energy, long energy, long enemy_metal, bool end_battle, int _metalamount){
    int count;
    bool  turn = false; //User or AI, both require different outcome calculations
    if(!enemy_energy || !enemy_metal) //If the enemy is out of resources
        balance_counter(balance, end_battle, turn);
    turn = true; //Switch to user's turn
    if(!energy || !_metalamount) //If the user is out of resources
        balance_counter(balance, end_battle, turn);
}

void update_energy(int level, int energy, int morale){
    if(level < 5 && level > 5)
        energy += randRange(50, 100) + morale; //Energy will be updated in each iteration through the loop to allow for more realism
    else if(level > 10 && level < 15)
        energy += randRange(100, 150) + morale; //It will be in accordance to the level but morale can also add a bias
    else if(level > 15 &&  level < 17)
        energy += randRange(150, 200) + morale;
}

void update_morale(std::vector<std::string> balance, int morale, int enemy_morale){
    int count;
    for(int i = 0; i < balance.size(); i++){
        if(balance[i] == "Victory") //It can count victory or defeat, logic would just have to be inverted
            count += 1;
    }
    if(count > balance.size()/2) //If the balance is positive (more victories than defeats)
        morale += randRange(50, 100);  //We increase morale by random amount (morale has an effect on the hp)
    else
        morale -= randRange(50, 100);
        morale = std::abs(morale); //We don't want it to be negative
}

void AI(std::vector<int> metal_stock, int choice, long aliens, int arsenal1, int arsenal2, int enemies_metal, int enemies_energy){
    metal_stock.push_back(enemies_metal);
    std::vector<int> average_loss; //Keeps track of the average losses in order to compute marginal loss as an average
    float marginal_loss; //Marginal loss gives the AI a notion of how much metal has been lost, in terms of units
    float relative_difference;
    int total;
    std::reverse(metal_stock.begin(), metal_stock.end());
    if(metal_stock.size() == 1){
        relative_difference = aliens/3;
        marginal_loss = randRange(1, 9);
    }
    else{
        for(int i = 0; i < metal_stock.size(); i++){
        average_loss.push_back(metal_stock[i] - metal_stock[i + 1]); //Each member will be subtracted to its posterior neighbour
        }                                                               //This is to compute by how much the metal variable has been reduced
                                                                    //On an individual basis throughout the battle
        for(int i = 0; i < average_loss.size(); i++){ //We are going to compute the average;
        total = average_loss[i] + average_loss[i + 1];
        }
        marginal_loss = total/average_loss.size();
        relative_difference = aliens/3; //This variable lets the AI know how many people must join the airforce(e.g how many airplanes must be produced) or the cyborg's army
    }                                    //Given a certain amount of aliens
    if(arsenal1 > arsenal2)  //It will use drones if there are more drones than cyborgs and viceversa
        decision_maker(choice, enemies_metal, enemies_energy, arsenal1, arsenal2, relative_difference, marginal_loss, true);
        //true if the AI decides to attack with drones
    else //false if the AI decides to attack with cyborgs
        decision_maker(choice, enemies_metal, enemies_energy, arsenal1, arsenal2, relative_difference, marginal_loss, false);
}




void battle_preparation(long enemies_drones, long enemies_cyborgs, long enemies_level, long energy, long enemy_energy, long aliens){
    std::vector<std::string> balance;
    std::vector<int> metal_stock;
    int choice;
    int amount;
    int missiles_amount = 200000; //AI's choice of how many missiles will be dropped
    long enemies_missiles = 2000; //Amount of missiles the enemy has at disposal
    long enemies_bombs = 20000;
    long bombs_amount = 20000;
    long _metalamount = 941238;
    long _specimens = 1000000;
    long _armors = 34000;
    long _soldierslevel = 5;
    long _bombs = 100000;
    long _missiles = 100000;
    long _drones = 10000;
    long _cyborgs = 10000;
    long enemies_metal;
    int morale = 100;
    int enemy_morale = 100;
    int counter = 1;
    bool done = false;
    bool back_to_menu = false;
    bool end_battle = false;
    float enemy_cyborgs_hp = 50.0 * enemies_level + morale;
    float enemy_drones_hp = 100.0 * enemies_level + morale;
    int cyborgs_hp = 50 * 5 + morale;
    int drones_hp = 100 * 5 + morale;
    while(!end_battle){
        std::cout<<std::endl;
        if(back_to_menu)
            ;
        else
            counter += 1;
            counter % 2 ?  std::cout<<"It is the enemy's turn my lord!"<<std::endl : std::cout<<"It is your turn master!"<<std::endl;
        std::cout<<std::endl;
        check_victory(balance, enemy_energy, energy, enemies_metal, end_battle, 500000);
        update_morale(balance, morale, enemy_morale); //First we update the morale for both user and AI
        update_energy(enemies_level, enemy_energy, enemy_morale); //We update the energy for both user and AI separately (allows for code reusability)
        update_energy(5, energy, morale);
        if( turn_assignment(counter)){
             std::cout<<"<---HEADQUARTERS--->"<<"\n"
            <<"1. Cyborg attack\n"
            <<"2. Drones attack\n"
            <<"3. Metallurgy"<<std::endl;
            std::cin>>choice;
        }
        else{
            AI(metal_stock, choice , aliens, enemies_drones, enemies_cyborgs, enemies_metal, enemy_energy);
        }
        switch(choice){

            case 1:{
                    done = false;
                    while(!done){
                        if( turn_assignment(counter) ){
                            std::cout<<std::endl;
                            std::cout<<"<--CYBORG HEADQUARTERS-->\n"
                            <<"Welcome commander! we are pleased to serve you!\n"
                            <<"Tell us what to do my master\n"<<"\n"
                            <<"1. Annihilate civilians(it will have an effect on the enemy's morale,)\n"
                            <<"2. Attack enemy(reduce the enemy's army)\n"
                            <<"3  Return"<<std::endl;
                            std::cin>>choice;
                        }
                        else
                            choice = randRange(1, 2);
                        switch(choice){

                            case 1: while(1){
                                        std::cout<<std::endl;
                                        if(turn_assignment(counter)){
                                            std::cout<<"How many civilians do you want to kill my master?"<<std::endl;
                                            std::cin>>amount;
                                            while(energy < amount/2 || _armors < amount){
                                                if(_armors == 0){
                                                    std::cout<<"My lord you will need to produce more armors my lord"<<std::endl;
                                                    back_to_menu = true;
                                                    done = true;
                                                }
                                                std::cout<<std::endl;
                                                std::cout<<"My lord these are our available resources"<<"\n"
                                                <<"Energy: "<<energy<<"\n"
                                                <<"Armors: "<<_armors<<"\n"
                                                <<"\n"<<std::endl;
                                                std::cin>>amount;
                                            }
                                            energy -= std::floor(amount / 2.0);
                                            damage_calculation(balance, "Civilians attack", amount, 100.0, _soldierslevel, aliens, enemy_morale, counter);
                                            break;
                                        }
                                        else{
                                            if(enemy_energy >= 5000000){
                                                amount = randRange(10000, 100000);
                                                enemy_energy -= randRange(1000, 100000);
                                                std::cout<<"Civilians attack\n"<<std::endl;
                                                damage_calculation(balance, "Civilians attack", amount, 100.0, _soldierslevel, aliens, morale, counter);
                                                break;

                                            }
                                            else if(enemy_energy < 5000000){
                                                amount = randRange(10000, 100000);
                                                enemy_energy -= randRange(1000, 100000);
                                                std::cout<<"Civilians attack"<<std::endl;
                                                damage_calculation(balance, "Civilians attack", amount, 100.0, enemies_level, aliens, morale, counter);
                                                break;
                                            }

                                     }
                                }
                                done = true;
                                break;

                            case 2: while(1){
                                        if(turn_assignment(counter)){
                                            std::cout<<std::endl;
                                            std::cout<<"How many enemies do you want to kill my master?"<<std::endl;
                                            std::cin>>amount;
                                            while(energy < enemies_cyborgs/2 || enemies_cyborgs < amount){
                                                if(_armors == 0){
                                                    std::cout<<"My lord you will need to produce more armors"<<std::endl;
                                                    back_to_menu = true;
                                                    done = true;
                                                }
                                                std::cout<<std::endl;
                                                std::cout<<"My lord these are our available resources"<<"\n"
                                                <<"Energy: "<<energy<<"\n"
                                                <<"Armors: "<<_armors<<"\n"
                                                <<"\n"<<std::endl;
                                                std::cin>>amount;
                                            }
                                            energy -= std::floor(amount / 2.0);
                                            damage_calculation(balance, "Cyborgs attack", amount, enemy_cyborgs_hp, _soldierslevel, aliens, enemy_morale, counter);
                                            done = true;
                                            break;
                                        }
                                        else{
                                            if(enemy_energy >= 5000000){
                                                amount = randRange(100000, 300000);
                                                enemy_energy = randRange(10000, 250000);
                                                std::cout<<"Cyborgs attack\n"<<std::endl;
                                                damage_calculation(balance, "Cyborgs attack", amount, cyborgs_hp, enemies_level, aliens, morale, counter);
                                                break;

                                            }
                                            else if(enemy_energy < 5000000){
                                                amount = randRange(100000, 300000);
                                                enemy_energy = randRange(10000, 250000);
                                                std::cout<<"Cyborgs attack\n"<<std::endl;
                                                damage_calculation(balance, "Cyborgs attack", amount, cyborgs_hp, enemies_level, aliens, morale, counter);
                                                break;
                                            }
                                        }
                                    }
                                    done = true;
                                    break;
                            case 3: back_to_menu = true;
                                    done = true;
                                    break;


                        }
                    }
                    break;
                }
            case 2: done = false;
                    while(!done){
                        if(turn_assignment(counter)){
                            std::cout<<std::endl;
                            std::cout<<"<--DRONES HEADQUARTERS-->"<<"\n"
                            <<"1. Missiles (DronesvsDrones)\n"
                            <<"2. Bombardment(DronesvsCyborgs)\n"
                            <<"3. Return"<<std::endl;
                            std::cin>>choice;
                        }
                        else
                            AI(metal_stock, choice, aliens, enemies_bombs, enemies_missiles, enemies_metal, enemy_energy);

                        switch(choice){

                            case 1: while(1){
                                        std::cout<<std::endl;
                                        if(turn_assignment(counter)){
                                            std::cout<<"<--DRONES HEADQUARTERS-->"<<"\n"
                                            <<"Lord let us know how many missiles you want each drone to drop!"<<std::endl;
                                            std::cin>>missiles_amount;
                                            while(amount > _missiles || energy < missiles_amount / 2){
                                                if(_missiles == 0){
                                                    std::cout<<"My lord you will need to produce more bombs"<<std::endl;
                                                    back_to_menu = true;
                                                    done = true;
                                                }
                                                std::cout<<"My lord this is the current amount of resources you have at disposal"<<"\n"
                                                <<"Missiles: "<<_missiles<<"\n"
                                                <<"Drones: "<<_drones<<"\n"
                                                <<"Energy: "<<energy<<"\n"
                                                <<std::endl;
                                                std::cin>>missiles_amount;
                                            }
                                            std::cout<<std::endl;
                                            std::cout<<"Now my lord, type in the amount of drones you want to send for this attack\n"<<std::endl;
                                            std::cin>>amount;
                                            while(amount > _drones || energy < amount / 2){
                                                if(_drones == 0){
                                                    std::cout<<"My lord we will need to produce more drones"<<std::endl;
                                                    back_to_menu = true;
                                                    done = true;
                                                }
                                                std::cout<<"My lord, this is the current amount of resources you have at disposal"<<"\n"
                                                <<"Bombs: "<<_bombs<<"\n"
                                                <<"Drones: "<<_drones<<"\n"
                                                <<"Missiles: "<<_missiles<<"\n"
                                                <<"Energy: "<<energy<<"\n"
                                                <<std::endl;
                                                std::cin>>amount;
                                            }
                                            std::cout<<std::endl;
                                            std::cout<<"Fantastic my lord, we will send our drones to this miserable planet!\n"
                                            <<"and take these dirty inferior beings to an intergalactic hell...\n"<<std::endl;
                                            energy -= std::floor(amount/2.0);
                                            damage_calculation(balance, "Missiles attack", amount*missiles_amount, enemy_drones_hp, _soldierslevel, aliens, enemy_morale, counter);
                                            done = true;
                                            break;
                                        }
                                        else{
                                            if(enemy_energy >= 5000000){
                                                amount = randRange(1, 40);
                                                missiles_amount = randRange(1, 40);
                                                enemies_missiles -= missiles_amount;
                                                enemy_energy -= randRange(10000, 250000);
                                                std::cout<<"Missiles attack"<<std::endl;
                                                damage_calculation(balance, "Missiles attack", amount*missiles_amount, drones_hp, 5, _specimens, morale, counter);
                                                break;

                                            }
                                            else if(enemy_energy < 5000000){
                                                amount = randRange(1, 40);
                                                missiles_amount = randRange(1, 40);
                                                enemies_missiles -= missiles_amount;
                                                enemy_energy -= randRange(10000, 250000);
                                                std::cout<<"Missile attack\n"<<std::endl;
                                                damage_calculation(balance, "Missiles attack", amount*missiles_amount, drones_hp, 5, _specimens, morale, counter);
                                                break;
                                            }
                                        }

                                    }
                                    done = true;
                                    break;

                            case 2: while(1){
                                         std::cout<<std::endl;
                                        if(turn_assignment(counter)){
                                            std::cout<<"<--DRONES HEADQUARTERS-->"<<"\n"
                                            <<"Lord let us know how many bombs you want each drone to drop!"<<std::endl;
                                            std::cin>>bombs_amount;
                                            while(amount > _bombs || energy < amount / 2){
                                                if(_bombs == 0){
                                                    std::cout<<"My lord you will need to produce more bombs"<<std::endl;
                                                    back_to_menu = true;
                                                    done = true;
                                                }
                                                std::cout<<"My lord this is the current amount of resources you have at disposal"<<"\n"
                                                <<"Bombs: "<<_bombs<<"\n"
                                                <<"Drones: "<<_drones<<"\n"
                                                <<"Energy: "<<energy<<"\n"
                                                <<std::endl;
                                                std::cin>>bombs_amount;
                                            }
                                            std::cout<<std::endl;
                                            std::cout<<"Now my lord, type in the amount of drones you want to send for this attack\n"<<std::endl;
                                            std::cin>>amount;
                                            while(amount > _drones || energy < amount / 2){
                                                if(_drones == 0){
                                                    std::cout<<"My lord you will need to produce more drones in the factory"<<std::endl;
                                                    back_to_menu = true;
                                                    done = true;
                                                }
                                                std::cout<<"My lord, this is the current amount of resources you have at disposal"<<"\n"
                                                <<"Bombs: "<<_bombs<<"\n"
                                                <<"Drones: "<<_drones<<"\n"
                                                <<"Energy: "<<energy<<"\n"
                                                <<std::endl;
                                                std::cin>>amount;
                                            }
                                            std::cout<<std::endl;
                                            std::cout<<"Fantastic my lord, we will send our drones to this miserable planet!\n"
                                            <<"and take these dirty inferior beings to an intergalactic hell...\n"<<std::endl;
                                            damage_calculation(balance, "Drone bombardment", amount*bombs_amount, enemy_drones_hp, enemies_level, aliens, enemy_morale, counter);
                                            break;
                                        }
                                        else{
                                            if(enemy_energy >= 5000000){
                                                amount = randRange(1, 40);
                                                bombs_amount = randRange(1, 40);
                                                enemies_bombs -= bombs_amount;
                                                enemy_energy -= randRange(10000, 250000);
                                                std::cout<<"Drone bombardment"<<std::endl;
                                                damage_calculation(balance, "Drone bombardment", amount*bombs_amount, drones_hp, 5, _specimens, morale, counter);
                                                break;

                                            }
                                            else if(enemy_energy < 5000000){
                                                amount = randRange(1, 40);
                                                bombs_amount = randRange(1, 40);
                                                enemies_bombs -= bombs_amount;
                                                enemy_energy -= randRange(10000, 250000);
                                                std::cout<<"Drone bombardment"<<std::endl;
                                                damage_calculation(balance, "Drone bombardment", amount*bombs_amount, drones_hp, 5, aliens, morale, counter);
                                                break;
                                            }
                                        }
                                    }
                                    done = true;
                                    break;
                            case 3: done = true;
                                    back_to_menu = true;
                                    break;

                        }
                    }
                    break;
            case 3: metallurgy(_metalamount, _drones, _specimens, _armors, _missiles, _bombs, counter);
                    break;
        }
    }
}

void battle_reports(int warriors, long surrender_limit, int deaths, long arbitrary_stop, int adjustment, int nanoseconds, bool players_attack, int counter){
    int results;
    std::string report;
    if(turn_assignment(counter)){
        if(players_attack){
            report = "The enemy had ";
        }
        else{
            report = "My lord we had ";
        }
    }
    else if(!turn_assignment(counter)){
        if(players_attack)
            report = "The enemy had ";
        else
            report = "My lord we had ";
    }
    while(warriors >= surrender_limit){
        if (deaths > 300000){
            results = deaths;
            deaths  = 0;
            adjustment = 5;
        }
        arbitrary_stop = rand() % adjustment + deaths;
        usleep(nanoseconds);
        warriors -= 1;
        deaths += 1;
        if(deaths == arbitrary_stop){
            if(results > 0){
                std::cout<<report<<deaths + results<<" casualties"<<std::endl;
                adjustment = deaths;
            }
            else{
                std::cout<<report<<deaths<<" casualties"<<std::endl;
                adjustment = deaths;
            }
        }
    }
}

void casualties(long warriors, int level, bool players_attack, int counter){
    int nanoseconds = 17 - level;
    long surrender_limit;
    int deaths;
    int arbitrary_stop;
    int adjustment = 13;
    if(warriors % 2){
        surrender_limit = rand() % warriors/4; //This variable will be used for the while condition, it must not be a float!
    }
    else if(warriors % 2 != 0){
        warriors += 1;
        surrender_limit = rand() % warriors/4;
    }
    std::thread t1(battle_reports, warriors, surrender_limit, deaths, arbitrary_stop, adjustment, nanoseconds, players_attack, counter);
    t1.join();
}

int outcome_calculator(long warriors, int level, bool players_attack, int counter){
    high_resolution_clock::time_point p1 = high_resolution_clock::now();
    std::thread t2(casualties, warriors, level, players_attack, counter);
    t2.join();
    high_resolution_clock::time_point p2 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(p2 - p1).count();
    return duration;
}

float soldiers_fate(float ceilling){
    float addition = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/ceilling));
    return addition;
}

long random_victim_assignment(long warriors){
    float pivot;
    float fate;
    float ceilling;
    int random_constant;
    pivot = std::floor(warriors/2);
    random_constant = randRange(1, 2);
    ceilling = warriors - pivot;
    fate = soldiers_fate(ceilling);
    if(random_constant == 1){
        warriors += fate;
    }
    else if(random_constant == 2){
        warriors -= fate;
    }
    int n = static_cast<long>(warriors);
    return n;
}


void battle_processor(std::vector<std::string> balance, long drones, long cyborgs, long enemies_drones, long enemies_cyborgs, int level, int _soldierslevel, int counter){    //One processor to rule them all, One processor to find them,
    //One processor to bring them all and in the darkness bind them
    std::cout<<"\n"  //REWRITE PROCESS CHECK THE FIGHTER VARIABLE ASSIGNMENT!
    <<"Our soldiers will get ready for the glorious day my lord!"<<"\n"
    <<"Always willing to serve you and die for you! "<<"\n"
    <<std::endl;
    long first_turn;
    long second_turn;
    long player_warriors = drones + cyborgs;
    long enemy_warriors = enemies_drones + enemies_cyborgs;
    long strike_back_victims;
    int fighter_level1;
    int fighter_level2;
    bool players_attack;
    if(turn_assignment(counter)){
        players_attack = true;
        strike_back_victims = enemy_warriors;
        first_turn = random_victim_assignment(enemy_warriors);
        second_turn = strike_back_victims;
        fighter_level1 = _soldierslevel;
        fighter_level2 = level;
    }
    else if(!turn_assignment(counter)){
        players_attack = false;
        strike_back_victims = player_warriors;
        first_turn = random_victim_assignment(player_warriors);
        second_turn = strike_back_victims;
        fighter_level1 = level;
        fighter_level2 = _soldierslevel;
    }
    std::future<int> result1(std::async(outcome_calculator, first_turn, fighter_level1, players_attack, counter));
    int players_duration = result1.get();
    players_attack = true ? players_attack = false : players_attack = true;
    std::future<int> result2(std::async(outcome_calculator, second_turn, fighter_level2, players_attack, counter));
    int enemys_duration = result2.get();
    if(players_duration >= enemys_duration)
        balance.push_back("Victory");
    else if(players_duration < enemys_duration)
        balance.push_back("Defeat");
}

//no need to copy and paste this module
int efficiency_calculation(int resources, int slaves, bool battle){
    int efficiency;
    int time;
    int level;
    if(battle)
        level = 5 ;
    if(level >= 0 && level <= 5){
        if(resources < 5000){
            slaves % 2 == 0 ? slaves = randRange(10, 15) : slaves = randRange(1, 5);
            efficiency = 20* 2 - slaves;
            if(efficiency > 30){
                time = 3;
            }
            else
                time = 4;

        }
        else if(resources > 5000){
            slaves % 2 == 0 ? slaves = randRange(10, 12) : slaves = randRange(1, 2);
            efficiency = 20 * 2 - slaves;
            if(efficiency > 30){
                time = 4;
            }
            else
                time = 5;
        }
    }
    else if(level >= 5 && level <= 10){
        if(resources < 5000){
            slaves % 2 == 0 ? slaves = randRange(10, 15) : slaves = randRange(1, 5);
            efficiency = randRange(10, 15) * 2 - slaves;
            if(efficiency >= 15){
                time = 2;
            }
            else
                time = 3;

        }
        else if(resources > 5000){
            slaves % 2  == 0 ? slaves = randRange(10, 12) : slaves = randRange(1, 2);
            efficiency = randRange(10, 15) * 2 - slaves;
            if(efficiency >= 15){
                time = 3;
            }
            else
                time = 4;
        }
    }
    else if(level > 10 && level <= 15){
        if(resources < 5000){
            slaves % 2 == 0 ? slaves = randRange(10, 15) : slaves = randRange(1, 5);
            efficiency = randRange(5, 10) * 2 - slaves;
            if(efficiency > 15)
                time = 1;
            else
                time = 2;
        }
        else if(resources > 5000){
            slaves % 2 == 0 ? slaves = randRange(10, 12) : slaves = randRange(1, 2);
            efficiency = randRange(5, 10) * 2 - slaves;
            if(efficiency > 10)
                time = 2;
            else
                time = 3;
        }
    }
    else if(level >= 15){
        if(resources < 5000){
            slaves % 2 == 0 ? slaves = randRange(10, 15) : slaves = randRange(1, 5);
            efficiency = randRange(1, 5) * 2 - slaves;
            if(efficiency > 5)
                time = 0;
            else
                time = 1;

        }
        else if(resources >= 5000){
            slaves % 2 == 0 ? slaves = randRange(10, 12) : slaves = randRange(1, 2);
            efficiency = randRange(1, 5) * 2 - slaves;
            if(efficiency > 5)
                time = 1;
            else
                time = 2;
        }
    }
    return time;
}


int main()
{
    srand(unsigned(time(NULL)));
    battle_preparation(100000, 200000, 5, 1000000.0, 1000000.0, 1000000);
    return 0;
}
