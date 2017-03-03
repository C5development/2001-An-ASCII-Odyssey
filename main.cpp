#include <iostream>
#include<vector>
#include<array>
#include<cstdlib>
#include<string>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<unistd.h> //Import the sleep function (only works with linux compiler)
class Star
{

    friend class Spaceship;

    private:

        float _starssurface;
        int _starsheat;
        int _starsradius;

    protected:
        char _startype;
        int _starsradiation;
        int _starsgravitationalforce;

    public:

        int random_number_generator();

        int randRange(int, int);

        int getstarsheat();

        int getstarsradiation();

        int getstartype();

        void display_stars_data(std::string);

        void define_type_of_star();

        void stars_generator();

        Star();
};

int Star::random_number_generator(){
    int n;
    n = (rand()%4 + 1);
    return n;
}


void Star::display_stars_data(std::string star_name){
    std::string startype;
    if(_startype == 1){
        startype = "Neutron star";
    }
    else if(_startype == 2){
        startype = "Blue giant";
    }
    else if(_startype == 3){
        startype = "Yellow star";
    }
    else if(_startype == 4){
        startype = "Red giant";
    }
    std::cout<<"|--"<<star_name<<"--|"<<std::endl;
    std::cout<<"Type of star: "<<startype<<std::endl;
    std::cout<<"Star's temperature: "<<_starsheat<<" celcius"<<std::endl;
    std::cout<<"Star's surface :"<<_starssurface<<" millions of square km"<<std::endl;
    std::cout<<"Star's radiaton level :"<<_starsradiation<<std::endl;
}

int Star::randRange(int low, int high)
{
    return rand() % (high - low + 1) + low;
}

void Star::define_type_of_star()
{

    _starsradius = randRange(1,800); //In millions of kilometers
    if(_starsradius >= 1 && _starsradius <= 250)
        _startype = 1;
    else if(_starsradius >= 260 && _starsradius <= 500)
        _startype = 2;
    else if(_starsradius >= 510 && _starsradius <= 750)
        _startype = 3;
    else if(_starsradius >= 760 && _starsradius <= 800)
        _startype = 4;
    _starssurface = randRange(100000, 1000000);

}

void Star::stars_generator()
{

        define_type_of_star();
            //We are going to start by defining the stars heat, this is set in relation to its radius (which in turn determines the kind of star)
        if(_startype == 1)
            _starsheat = randRange(100000, 200000 ); //We are defining the heat of a white dwarf here in celcius
        else if(_startype == 2)
            _starsheat = randRange(10000, 20000); //We are defining the heat of a blue giant here in celcius
        else if(_startype == 3)
            _starsheat = randRange(5000, 7000); //We are defining the heat of a yellow star here in celcius
        else if(_startype == 4)
            _starsheat = randRange(1000, 5000); //We are defining the heat of a red giant here in celcius

            //We proceed with the radiation definition, this is set in relation to its heat

        if(_starsheat >= 3000 && _starsheat <= 4000)
            _starsradiation = randRange(8, 10); //We are defining the radiation of a white dwarf here

        else if(_starsheat >= 2000 && _starsheat <= 3000)
            _starsradiation = randRange(6, 7); //We are defining the radiation of a blue giant here

        else if(_starsheat >= 1000 && _starsheat <= 2000)
            _starsradiation = randRange(3, 5); //We are defining the radiation of a yellow star here
        else if(_starsheat >= 0 && _starsheat <= 1000)
            _starsradiation = randRange(2, 3); //We are defining the radiation of a red giant here
}
Star::Star(){

    _starsradiation = randRange(0, 10);

    define_type_of_star();

    stars_generator();

}

class Planet: public Star
{
    friend class Spaceship;

    private:
        int _planetsradius;
        int _gravitationalforce;
        int _planetstemperature;
        float _planetssurface;
        char _planettype;
        bool _rockyorgas;
        bool _defeated = false;
        std::string _atmospherecomposition;
        bool _breathableatmosphere;
        bool _magneticprotection;
        int _magneticfieldintensity;
        int _magneticfieldvsradiation;
        int _distancefromstar;
        bool _habitable;
        int _rotationangle; //From 90 to 180
        std::string _planetname;
        int _diamonds; //Diamonds is given as a currency automatically
        int _mercury; //It is given in megatons of fuel
        int _gas; //It is also given in megatons, along with antimatter it will power the WARP drive
        int _metal; //Metal can be classified at will to define the weaponery, space ships and
        int _bacteria; //Bacteria will be classified by the game itself in order to determine what kind of bacteria there is
        int _humans; //Humans can be classified at will to define the crew
        int _antimatter; //Mixed with the gas you can power the WARP drive
        int _protozoo; //Amount of protozoo to strengthen the army
        int _staphillococcus; //
        int _pseudomona;





    public:


        int random_number_generator();

        int random_percentage_generator();

        int randRangep(int, int);

        int gethabitability();

        bool getpotentialhabitability();

        float geteccentricity();

        char getplanettype();

        int getmetal();

        int getdiamonds();

        int getmercury();

        int gethumans();

        std::vector<int> getbacteriae();

        int getgas();

        int gettemperature();

        int getplanetsdistance();

        int getmagneticfieldvsradiation();

        bool getbreathableatmosphere();

        int getstaphilloccocus();

        int getdistancefromstar();

        int getprotozoo();

        int getpseudomona();

        void turn_into_habitable();

        void setmetal(int);

        void setdiamonds(int);

        void setmercury(int);

        void sethumans(int);

        void setbacteriae(int, int, int);

        void setgas(int);

        void defeat();

        bool getdefeat();

        std::string getplanetsname();

        bool element_finder();

        void define_type_of_planet();

        void define_planetstemperature();

        float determine_orbit_eccentricity();

        void define_atmosphere_composition();

        void define_planets_orbit();

        void determine_magnetic_field();

        void determine_type_of_bacteria();

        void determine_amount_of_resources();

        void determine_habitability();

        void display_planets_data(std::string, int);

        Planet();
};
int Planet::random_number_generator(){
        int n;
        n = (rand()%4 + 1);
        return n;
    }

int Planet::random_percentage_generator(){
    int n;
    n = (rand()%100 + 1);
    return n;
    }

int Planet::randRangep(int low, int high)
{
    return rand() % (high - low + 1) + low;
}

int Planet::gethabitability(){
    return _habitable;
}

int Planet::getplanetsdistance(){
    return _distancefromstar;
}

bool Planet::getbreathableatmosphere(){
    return _breathableatmosphere;
}

int Planet::getmetal(){
    return _metal;
}

int Planet::gettemperature(){
    return _planetstemperature;
}

int Planet::getdiamonds(){
    return _diamonds;
}

int Planet::getmercury(){
    return _mercury;
}

int Planet::gethumans(){
    return _humans;
}


int Planet::getstaphilloccocus(){
    return _staphillococcus;
}

int Planet::getprotozoo(){
    return _protozoo;
}

int Planet::getpseudomona(){
    return _pseudomona;
}

std::vector<int> Planet::getbacteriae(){
    std::vector<int> bacteriae = {_protozoo, _staphillococcus, _pseudomona};
    return bacteriae;
}

int Planet::getgas(){
    return _gas;
}

int Planet::getmagneticfieldvsradiation(){
    return _magneticfieldvsradiation;
}

void Planet::turn_into_habitable(){
    _habitable = true;
}

void Planet::setmetal(int n){
    _metal += n;
}

void Planet::setdiamonds(int n){
    _diamonds += n;
}

void Planet::setmercury(int n){
    _mercury += n;
}

void Planet::sethumans(int n){
    _humans += n;
}

void Planet::setgas(int n){
    _gas += n;
}

void Planet::defeat(){
    _defeated = true;
}

bool Planet::getdefeat(){
    return _defeated;
}

void Planet::setbacteriae(int x, int y, int z){
    _protozoo += x;
    _staphillococcus += y;
    _pseudomona += z;
}

void Planet::define_type_of_planet()
{
    int random_event = random_number_generator();
    //It will randomly predetermine the radius of our planet
    if(random_event == 0){
        _planetsradius = randRangep(10000, 30000); //This should be size of a small rocky planet like pluto
        _rockyorgas = true;
    }
    else if(random_event == 1){
        _planetsradius = randRangep(10000, 30000); //This should be size of a small rocky planet like pluto
        _rockyorgas = true;
    }
    else if(random_event == 2){
        _planetsradius = randRangep(40000, 100000); //This should be size of a normal rocky planet like earth
        _rockyorgas = true;
    }
    else if(random_event == 3){
        _planetsradius = randRangep(60000, 170000); //This should be the size of a gigantic rocky planet
        _rockyorgas = true;
    }

    else if(random_event == 4){
        _planetsradius = randRangep(60000, 170000); //This is the expected size of a gas giant
        _rockyorgas = false;

    }


    float pi = 3.14;
    _planetssurface = (4*pi*_planetsradius) / 3;
}


void Planet::define_planetstemperature()
{
    int _distancefromstar = randRange(100, 4000);
    define_type_of_planet();
    if(_startype == 1){
        if(_rockyorgas){
                if(_distancefromstar <= 1300){
                    _planetstemperature = randRange(1000, 1500);
                    _planettype = 2; //Diamond planet you can use it to trade with other civilisations and make money
                }
                else if(_distancefromstar >= 1300){
                    _planetstemperature = randRange(500, 1000); //Just for the sake of realism
                    _planettype = 1; //It will be considered a lava planet, you can get metal for weapons and technology
                }
            }
            else
                _planettype = 6; //It is a gas planet, can be used to power light-speed travel mode
                _planetstemperature = randRange(200, 1000);
    } //If the star is a white dwarf

    else if(_startype == 2){ //If the star is a blue giant
        if(_rockyorgas){
            if(_distancefromstar <= 1300){
                _planetstemperature = randRange(1000, 1500);
                _planettype = 1; //It will be considered a lava planet, you can get metal for weapons and technology
            }
            else if(_distancefromstar >= 1300){
                _planetstemperature = randRange(200, 350);
                _planettype = 2; // Diamond planet you can use it to purchase points
            }
        }
        else
            _planettype = 6;
            _planetstemperature = randRange(200, 1000); //It is a gas planet, can be used to power light-speed travel mode
    }


    else if(_startype == 3){ //If it is a yellow star
        if(_rockyorgas){
            if(_distancefromstar <= 1300){
                _planetstemperature = randRange(100, 500);
                _planettype = 3; //Mercury planet can be used to extract minerals and process fuel
            } else if(_distancefromstar >= 1300){
                _planetstemperature = randRange(20, 40);
                _planettype = 4; //This planet is likely to be habitable if it has people you can increase your space ship crew to colonise other planets depending how advanced their civilisation is
            }
        } else
            _planettype = 6;
            _planetstemperature = randRange(200, 1000); //It is a gas planet, can be used to power light-speed travel mode

    }
    else if(_startype == 4){ //If it is a red giant
        if(_rockyorgas){
            if(_distancefromstar <= 1300){
                _planetstemperature = randRange(20, 40);
                _planettype = 4; //This planet is likely to be habitable if it has people you can increase your space ship crew t
            } else if(_distancefromstar >= 1300){
                _planetstemperature = randRange(-500, 0);
                _planettype = 5; //This is a frozen planet, you can extract water molecules and bacteria to perform genetical modifications on your enslaved humans
            }
        }
        else
            _planettype = 6;
            _planetstemperature = randRange(0, 1000); //It is a gas planet, can be used to power light-speed travel mode

    }

}

char Planet::getplanettype(){
    return _planettype;
}

void Planet::define_atmosphere_composition(){
    if(_planettype == 1)
        _atmospherecomposition = "Carbon dioxide";
    else if(_planettype == 2)
        _atmospherecomposition ="Cosmic rays";
    else if(_planettype == 3)
        _atmospherecomposition ="Cyanide";
    else if(_planettype == 4)
        _atmospherecomposition ="Oxygen";
    else if(_planettype == 5)
        _atmospherecomposition = "Kriptonite";
    else if(_planettype == 6)
        _atmospherecomposition = "Nitrogen";

}

float Planet::determine_orbit_eccentricity(){
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return r;
}

void Planet::determine_magnetic_field(){
    if(_breathableatmosphere){
        int random_constant = randRange(1, 2);
        switch(random_constant){

            case 1: _magneticfieldintensity = randRange(5, 7);
                if(_magneticfieldintensity >= _starsradiation)
                    _magneticprotection = true;
                else if(_magneticfieldintensity <= _starsradiation);
                    _magneticprotection = false;
                    _magneticfieldvsradiation = randRange(3, 5); //This variable will let the user the amount of resources that will have to be put into the creation of a magnetic field

            case 2: _magneticfieldintensity = randRange(0, 5);
                    if(_magneticfieldintensity >= _starsradiation)
                        _magneticprotection = true;
                    else if(_magneticfieldintensity <= _starsradiation)
                        _magneticprotection = false;
                        _magneticfieldvsradiation =  randRange(5, 7); //This variable will let the user know the amount of technology that will be needed for a stronger magnetic field
        }
    }
    else
        ;
}


void Planet::determine_habitability(){
    if(_planettype == 4){
        if(_magneticprotection && _breathableatmosphere){
        _habitable = true;
        _humans = randRange(10000000, 70000000);
        }

        else if(_breathableatmosphere){
            _habitable = false;
            }
        else
            _habitable = false;
        }
    else
        _habitable = false;
}

void Planet::determine_amount_of_resources(){

    switch(_planettype){

        case 1: _metal = randRange(1000, 10000); //measured in kg

        case 2: _diamonds = randRange(10000, 100000); //measured in kg

        case 3: _mercury = randRange(1, 10000); //Given in megatons

        case 5: _protozoo = randRange(10000, 60000);
                _staphillococcus = randRange(10000, 60000);
                _pseudomona = randRange(10000, 60000);
                //Given in thousands of millions

        case 6: _gas = randRange(1, 10000); //Given in  megatons
    }
}


std::string Planet::getplanetsname(){
    return _planetname;
}


void Planet::display_planets_data(std::string planetsname, int distancefromstar){
    std::string planettype;
    if(_planettype == 1)
        planettype = "Lava rivers and lakes";
    else if(_planettype == 2)
        planettype = "Diamond surface";
    else if(_planettype == 3)
        planettype = "Mercury oceans";
    else if(_planettype == 4){
        if(_habitable){
            planettype = "Fully habitable planet";
        }
        else if(!_habitable){
            if(_breathableatmosphere){
                planettype ="Potentially habitable planet";
            }
            else
                planettype = "Post apocaliptyc planet full of nuclear radiation";
        }
    }
    else if(_planettype == 5){
        planettype = "Frozen planet, contains ice and primitive uni-cellular forms of life";
    }
    else if(_planettype == 6){
        planettype = "Gas giant";
    }
    _distancefromstar = distancefromstar; //This way we will be able to access the variable with a getter before inserting it in a database
    std::cout<<"|--"<<planetsname<<"--|"<<std::endl;
    std::cout<<"Planet type: "<< planettype<<std::endl;
    std::cout<<"Average temperature: "<<_planetstemperature<<" Celcius"<<std::endl;
    std::cout<<"Surface in square km: "<<_planetssurface<<std::endl;
    std::cout<<"Atmosphere's composition: "<<_atmospherecomposition<<std::endl;
    std::cout<<"Intensity of magnetic field: "<<_magneticfieldintensity<<std::endl;
    std::cout<<"Distance from its star: "<<distancefromstar<<" millions of kilometers"<<std::endl;
    std::cout<<"Orbit's eccentricity: "<<determine_orbit_eccentricity()<<std::endl;
    std::cout<<"Rotation angle: "<<randRange(90, 180)<<std::endl;
    if(_planettype == 1)
        std::cout<<"Amount of metal to be processed: "<<_metal<<" kg"<<std::endl;
    else if(_planettype == 2)
        std::cout<<"Amount of diamonds: "<<_diamonds<<" kg"<<std::endl;
    else if(_planettype == 3)
        std::cout<<"Amount of mercury: "<<_mercury<<" megatons"<<std::endl;
    else if(_planettype == 4){
        if(_habitable)
            std::cout<<"Alien population: "<<_humans<<" specimens"<<std::endl;
        else if(!_habitable){
            if(_breathableatmosphere)
                std::cout<<"Can be turned into a habitable planet by intensifying its magnetic field by "<<_magneticfieldvsradiation<<" magneto units"<<std::endl;
            else
                std::cout<<"Post apocalyptic planet full of radiation, it was destroyed by nukes approximately 10000000 years ago, nothing can be done with it"<<std::endl;
        }
    }
    else if(_planettype == 5){
        std::cout<<"These are the bacteriae contained in our deposits along with the different types "<<std::endl;
        std::cout<<"Protozoo: "<<_protozoo<<std::endl;
        std::cout<<"Staphilococcus: "<<_staphillococcus<<std::endl;
        std::cout<<"Pseudomonae: "<<_pseudomona<<std::endl;
    }
    else if(_planettype == 6){
        planettype = "Gas giant";
        std::cout<<"This is the amount of fuel you can use to power your WARP drive: "<<_gas<<std::endl;
    }
}


Planet::Planet(){
 //PLANET CLASS METHOD

    define_planetstemperature();

    define_atmosphere_composition();

    determine_magnetic_field();

    determine_amount_of_resources();

    determine_habitability();
}


class Spaceship
{
    private:

        int _diamondsamount = 1234257463; //This is the amount that will be spent on manufacturing processes
        int _specimens = 12355839;
        int _metalamount = 15678; //This will be used for the weapons creation
        int _fuelcapacity = 134135; //This will be used to refill fuel tanks
        int _WARPdrive = 10000; //This is going to be used to power the interstellar travelling mode
        int _antimatterweapon; //Planetdestroyer
        int _soldiers = 12335; //Soldiers to subyugate other civilisations
        int _scientists = 12334; //Scientists to perfom experiments on subyugated civilisations
        int _slaves = 12345; //Slaves are going to be used to extract minerals from other planets
        int _protozoolevels = 0; //In theory only WARP drive and fuel should be set
        int _staphilococcuslevels = 200;
        int _pseudomonalevels = 0;
        int _evolutionexpressaccelerator = 0;
        int _drones = 0;
        int _armors = 0;
        int _soldierspoints = 0;
        int _scientistspoints = 0;
        int _slavespoints = 5;
        int _soldierslevel = 0;
        int _scientistslevel = 5;
        int _slaveslevel = 0;
        int _points;
        int _overalllevel;


    public:

        void civilisation_interaction(int, int);
        void planet_interaction(bool);
        void stars_interaction();
        void interstellar_travel(bool);
        int cabin();
        void classify_specimens();
        void assign_points(int, std::string);
        void laboratory();
        void genetical_modification(int, std::vector<char>, std::vector<int>);
        void methalurgy();
        void setlevel(int, std::string, int, int, int, int, int, bool, std::vector<int>, std::vector<int>);
        void purchasepoints(int);
        void pointstransaction(int);
        int randRange(int, int);
        std::string define_stars_name(std::vector<std::string>, std::vector<std::string>);
        std::string define_planets_name(std::vector<std::string>, std::vector<std::string>);
        void planet_destroyer(int);
        void civilisation_history(std::string, std::string);
        void surrender_treaty(std::string, std::string);
        void assign_troops(int, int, int);
        void battle_mode(int, int, int, int);
        void to_solar_system(std::string, std::string, std::vector<char>, std::vector<int>, std::vector<int>);
        void display_planets_database(bool, std::string, std::vector<char>, std::vector<int>, std::vector<int>);
        void generate_solar_data_base();
        void colonise_solar_system();
        void display_colonies();
        void read_story();
        void save_game(); //DATABASE
        void game_over(); //DATABASE

};

int Spaceship::randRange(int low, int high)
{
    return rand() % (high - low + 1) + low;
}


void Spaceship::to_solar_system(std::string planettype, std::string planetsname, std::vector<char> planets_available, std::vector<int> distancesmap, std::vector<int>planets_temperature){
//EXTRACTS DATA FROM A TEMPORARY DATABASE DEFINED WHEN PLANETS ARE GENERATED(PLANETSINTERACTION) IT CAN ONLY BE MODIFIED BY THE PLANET_DESTROYER FUNCTION
}




std::string Spaceship::define_stars_name(std::vector<std::string> starnames, std::vector<std::string> starnamesbuffer){
    auto name = starnames.begin() + (rand()%starnames.size());
    starnamesbuffer.emplace_back(*name);
    starnames.erase(name);
    return *name;
}


void Spaceship::stars_interaction(){
        std::vector<std::string> starnamesbuffer;
        std::vector<std::string> starnames = {"Acamar", "Adhafera", "Kornephoros", "Hoedus II", "Miaplacidus", "Procyon", "Pleione", "Rastaban", "Rotanev", "Sarir", "Cassiopeia", "Sterope", "Tabit", "Veritate", "Zaurak", "Sceptrum", "Sadachbia", "Rukbat", "Cygnus", "Capricorni", "Rotanev", "Ceasar 43", "Zeus", "Colossus", "Dranicus", "Rimbokhan", "Tiranuslae", "Criptilocus"};    std::string starsname;
        int stars_number = rand() % 20 + 5;
        Star stars[stars_number];
        std::cout<<std::endl;
        std::cout<<std::endl;
        std::cout<<"<<<STARS>>>"<<std::endl;
        std::cout<<std::endl;
        std::cout<<std::endl;
        for(int i = 0; i < stars_number; i++){
            starsname = define_stars_name(starnames, starnamesbuffer);
            std::cout<<std::endl;
            std::cout<<"Type "<<i + 1<<" to explore this solar system"<<std::endl;
            std::cout<<std::endl;
            stars[i].display_stars_data(starsname);
            std::cout<<std::endl;
        }
}

void Spaceship::display_planets_database(bool planettype, std::string planetname, std::vector<char> planets_available, std::vector<int> distancesmap, std::vector<int> planetstemperatures){
}

void Spaceship::generate_solar_data_base(){
}

std::string Spaceship::define_planets_name(std::vector<std::string> planetnames, std::vector<std::string> planetnamesbuffer){

    int random_constant = rand() % planetnames.size();
    return planetnames[random_constant];
}

std::vector<int> ORgate(bool protozoo, bool staphilloccocus, bool pseudomona){
    std::vector<bool> booleanvalues;
    std::vector<int> missingindeces;
    booleanvalues.push_back(protozoo);
    booleanvalues.push_back(staphilloccocus);
    booleanvalues.push_back(pseudomona);
    for(int i = 0; i < 3; i++){
        if(booleanvalues[i] == true){
               missingindeces.push_back(i + 1);
            }
        else
            missingindeces.push_back(0);
    }
    return missingindeces;
}

void Spaceship::genetical_modification(int choice, std::vector<char> planetsavailable, std::vector<int> planetstemperatures){
    int desired_amount;
    std::string atmosphere;
    std::string desired_atmosphere;
    int temperature;
    int slaves_number = 0;
    int radiation;
    int slaves_temperature_resistance = 0;
    std::string slaves_atmosphere_resistance;
    int slaves_radiation_resistance = 0;
    if(planetsavailable[choice - 1] == 1){
        temperature = randRange(300, 1000);
        atmosphere = "Carbon dioxide";
    }
    else if(planetsavailable[choice - 1] == 2){
        temperature = randRange(300, 1000);
        atmosphere = "Cosmic rays";
    }
    else if(planetsavailable[choice - 1] == 3){
        temperature = randRange(300, 1000);
        atmosphere = "Cyanide";
    }
    else if(planetsavailable[choice - 1] == 5){
        temperature = randRange(300, 1000);
        atmosphere = "Kriptonite";
    }
    else if(planetsavailable[choice - 1] == 6){
        temperature = randRange(300, 1000);
        atmosphere = "Nitrogen";
    }
    radiation = rand() % 4 + 1;
    planetsavailable.empty();
    std::cout<<"We will have to adapt to the following conditions"<<std::endl;
    std::cout<<"Temperature: "<<temperature<<std::endl;
    std::cout<<"Atmosphere: "<<atmosphere<<std::endl;
    std::cout<<"Radiation: "<<radiation<<std::endl;
    std::cout<<"Let's go to the laboratory to modify our specimens accordingly"<<std::endl;
    std::cout<<"<<<LABORATORY>>>"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"This is how many specimens we could obtain in our expeditions my lord"<<std::endl;
    std::cout<<_specimens;
    std::cout<<"Please choose how many you would like to send to this planet"<<std::endl;
    std::cin>>desired_amount;
    if(desired_amount > _specimens){
        std::cout<<"My lord, I must inform you that we still do not have that many specimens left"<<std::endl;
    }
    else if(desired_amount <= _specimens){
        _specimens -= desired_amount;
        slaves_number = desired_amount;
        std::cout<<"The following number of specimens are ready to become your slaves my lord: "<<desired_amount<<std::endl;
        std::cout<<"Please, choose what variables you want to modify"<<std::endl;
        std::cout<<"What is the temperature level your slaves will have to resist?"<<std::endl;
        std::cin>>desired_amount;
        slaves_temperature_resistance += desired_amount;
        std::cout<<"Perfect my lord, now just give us the level of radiation they will be exposed to"<<std::endl;
        std::cin>>desired_amount;
        slaves_radiation_resistance = desired_amount;
        std::cout<<"Now we just need to know the atmosphere composition to perform our experiments my lord"<<std::endl;
        std::getline(std::cin, desired_atmosphere);
        std::cout<<"This is your legion of slaves"<<std::endl;
        std::cout<<"1. Number: "<<slaves_number<<std::endl;
        std::cout<<"2. Temperature resistance: "<<slaves_temperature_resistance<<std::endl;
        std::cout<<"3. Radiation resistance: "<<slaves_radiation_resistance<<std::endl;
        std::cout<<"4. Atmosphere resistance: "<<atmosphere<<std::endl;
        std::cout<<"We are ready to send our slaves and extract the minerals my lord!"<<std::endl;
        slaves_radiation_resistance = 0;
        slaves_temperature_resistance = 0;

    }

}

void Spaceship::civilisation_history(std::string social_structure, std::string civilisationname){
//Reads the civilisations' stories from text files
    if(social_structure == "Techno fascist regime"){
        ;
    }
    else if(social_structure == "Liberal democracy"){
        ;
    }
    else if(social_structure == "Techno utopian anarchy"){
        ;
    }
    else if(social_structure == "AI-ruled planetary nation"){
        ;
    }
}

void Spaceship::surrender_treaty(std::string social_structure, std::string civilisationname){
//Reads the surrender treaties from text files
    if(social_structure == "Techno fascist regime"){
        ;
    }
    else if(social_structure == "Liberal democracy"){
        ;
    }
    else if(social_structure == "Techno utopian anarchy"){
        ;
    }
    else if(social_structure == "AI-ruled planetary nation"){
        ;
    }
}

void Spaceship::display_colonies(){
}


void Spaceship::assign_troops(int aliens, int drones, int cyborgs){
    if(aliens % 2 == 0){
        int adjustment = aliens - aliens/4;
        drones = aliens/2 + randRange(aliens/2, adjustment);
        aliens -= drones;
        if(drones > aliens)
            cyborgs = drones - aliens;
        else if(drones < aliens)
            cyborgs = aliens - drones;

    }
    else if(aliens % 2 != 0){
        aliens += 1;
        int adjustment = aliens - aliens/4;
        cyborgs = aliens/2 + randRange(aliens/2, adjustment);
        aliens -= cyborgs;
        if(cyborgs > aliens)
            drones= cyborgs - aliens;
        else if(cyborgs < aliens)
            drones = aliens - cyborgs;
    }

}

void Spaceship::battle_mode(int drones, int cyborgs, int enemies_drones, int enemies_cyborgs){

}

void Spaceship::colonise_solar_system(){

}

void Spaceship::civilisation_interaction(int desired_respect, int aliens){
    std::vector<std::string> civilisationsnames = {"Epthot", "Quni", "Gowan", "Geeceind", "Srekloa", "Smorthue", "Absu", "Oimnere", "Lizul", "Thelzahue", "Qolush", "Vlesruom", "Twakten", "Vantoh", "Qefill", "Druzguo"};
    int enemies_level;
    int random_constant = rand() % 4;
    int earned_respect;
    int surrender_calculation;
    int enemies_drones;
    int enemies_cyborgs;
    int choice;
    bool surrender;
    bool done = false;
    std::string social_structure;
    switch(random_constant){

        case 1: social_structure = "Techno fascist regime";
                earned_respect = 3; //Fascist regimes are inferior but more corageous than democracies
                surrender_calculation = earned_respect - desired_respect;
                enemies_level = randRange(1, 4);
                if(surrender_calculation <= 0)
                    surrender = true;
                else{

                }
        case 2: social_structure = "Liberal democracy";  //Still not very advanced
                earned_respect = 2;
                surrender_calculation = earned_respect - desired_respect;
                enemies_level = randRange(5, 7);
                if(surrender_calculation <= 0)
                    surrender = true;
                else
                   surrender = false;

        case 3: social_structure = "Techno-utopian anarchy";
                earned_respect = 5; //These guys are tough cookies
                surrender_calculation = earned_respect - desired_respect; //They share their wives!! XDD
                enemies_level = randRange(8, 13);
                if(surrender_calculation <= 0)
                    surrender = true;
                else
                    surrender = false;

        case 4: social_structure = "AI-ruled planetary nation"; //Run away motherfucker
                enemies_level = randRange(13, 17); //No surrender option

    }
    if(surrender){
        surrender_treaty(social_structure, civilisationsnames[rand() % civilisationsnames.size()]);
    }
    else if(!surrender){
        while(!done){
            std::cout<<std::endl;
            std::cout<<"<<WAR DECLARATION>>"<<std::endl;
            std::cout<<std::endl;
            std::cout<<"Type of civilisation: "<<social_structure<<std::endl;
            std::cout<<"Your current resources"<<std::endl;
            std::cout<<"DRONES: "<<_drones<<std::endl;
            std::cout<<"CYBORG-ARMORS AND WEAPONS: "<<_armors<<std::endl;
            std::cout<<std::endl;
            assign_troops(aliens, enemies_drones, enemies_cyborgs);
            std::cout<<std::endl;
            std::cout<<"ENEMIES DRONES: "<<enemies_drones<<std::endl;
            std::cout<<"ENEMIES CYBORGS: "<<enemies_cyborgs<<std::endl;
            std::cout<<"The confidential reports must be read in order to find out the enemy's level"<<std::endl;
            std::cout<<"1. Start battle"<<std::endl;
            std::cout<<"2. Confidential reports from intelligence agency"<<std::endl;
            std::cin>>choice;
            switch(choice){
                    case 1: civilisation_history(social_structure, civilisationsnames[rand() % civilisationsnames.size()]);
                            done = true;

                    case 2: battle_mode(_drones, _armors, enemies_drones, enemies_cyborgs);
                            done = true;

            }
        }
    }


}

void Spaceship::save_game(){

}

void Spaceship::game_over(){
//This function must pick up a database and display the following values
//Distance travelled in light years
//Planets destroyed
//Colonies created
//Dominated civilisations
//Amount of diamonds collected
//Level reached
}

void Spaceship::planet_destroyer(int desired_respect){
    desired_respect += 1; //THIS FUNCTION SHOULD DELETE THE CHOSEN ROW FROM THE DATABASE MORE SPECIFICALLY THE SOLAR SYSTEM DATABASE
}

void Spaceship::planet_interaction(bool back_to_solar_system){
    int choice;
    bool potential_colony = true; //We start by assuming the solar system can be colonised
    bool dead_solar_system;
    std::string colony_approbation;
    unsigned int efficiency;
    int desired_respect;
    int distancefromstar;
    int adjustment = 50;
    int adjustment1;
    int adjustment2;
    std::string planettype;
    std::string planetname;
    std::vector<int> distancesmap;
    std::vector<int> planetstemperatures;
    std::vector<std::string> planet_names_buffer;
    std::vector<std::string> planet_names = {"Lok", "Erinar", "Golrath", "Imrooso", "Maryx Minor", "Qat Chrystac", "RZ7-6113-23", "Taspir III", "55 Cancri e", "Zachayphus", "Iewhoutis", "Foclillon", "Weplov", "Reter", "Crevugan", "Obloethea", "Ethuetera", "Asnypso", "Ciocury", "Glabuwei", "Spiri 29N4", "Grypso Y1J", "Slequhiri", "Tasloaclite", "Dragatan", "Sethurilia", "Hadrion", "Geuliv","Celaris", "Adrara", "Upruna", "Fraxetis", "Cuprillon", "Woilara", "Stuzaria", "Xiotune", "Hafloth", "Pludaphus", "Glarvis 10", "Vespin", "Oclore", "Oaphus", "Clugonus", "Veskaiter", "Godriuturn"};
    std::vector<char> planets_available;
    int planets_number = rand() % 4 + 4;
    Planet planets[planets_number];
    std::cout<<"<<<PLANETS>>>"<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    if(back_to_solar_system){
        to_solar_system(planettype, planetname, planets_available, distancesmap, planetstemperatures); //FUNCTION RETRIEVING INFORMATION FROM DATABASE AND STORING THE ENTITIES IN THE ABOVE-DEFINED VECTORS
                                //OTHERWISE THE OTHER FUNCTIONS WON'T BE ABLE TO INTERACT
                                //IT DOES NOT NEED TO GENERATE A NEW ARRAY OF OBJECTS SINCE THEY WILL ALREADY BE CONTAINED IN THE DATABASE
    }
    else if(!back_to_solar_system){
        for(int j = 0; j < planets_number; j++){
            adjustment1 = adjustment + 2 * j;
            adjustment2 = adjustment1 + 4 * j;
            planetname = define_planets_name(planet_names, planet_names_buffer);
            distancefromstar = randRange(adjustment1, adjustment2);
            distancesmap.push_back(distancefromstar);
            std::cout<<std::endl;
            std::cout<<"Type "<<j + 1<<" to explore this planet"<<std::endl;
            std::cout<<std::endl;
            planets[j].display_planets_data(planetname, distancefromstar); //A TEMPORARY DATABASE SHOULD BE INITIALISED HERE
            planets_available.push_back(planets[j].getplanettype());  //ROWS AND ENTITIES WILL BE ADDED THROUGH THE LOOP
            planetstemperatures.push_back(planets[j].gettemperature());
            std::cout<<std::endl;
            std::cout<<std::endl;
            adjustment += adjustment + randRange(150, 347);
            adjustment1 += adjustment1 + randRange(150, 347);
        }
    }
    std::cout<<std::endl;
    std::cout<<"Do you want to make this solar system a colony?"<<std::endl;
    std::cin>>colony_approbation;
    if(colony_approbation == "Yes" || colony_approbation == "yes" || colony_approbation == "y" || colony_approbation == "YES" || colony_approbation == "Y"){
        if(potential_colony){
            for(int i = 0; i < planets_available.size(); i++){
                if(planets_available[i] == 4){
                    if(planets[i].gethabitability()){
                        if(planets[i].getdefeat()){  //Important to use setdefeat for when a civilisation has been destroyed
                            continue;
                        }
                        else
                            potential_colony = false;

                    }
                    else if(potential_colony && !planets[i].gethabitability()){
                        dead_solar_system = true;
                    }
                }
                else
                    continue;
            }
        }
        if(potential_colony){
            if(dead_solar_system){
                std::cout<<"This solar system can be colonised"<<std::endl;
                std::cout<<"Since all of its planets are dead"<<std::endl;
                colonise_solar_system();
            }
            else if(!dead_solar_system)  //Planettype can still be four but potentially habitable
                std::cout<<"There might be one or more potentially habitable planets in this solar system"<<std::endl;
                colonise_solar_system();
        }
        else if(!potential_colony){
            std::cout<<"You still must conquer those planets that are habitable"<<std::endl;

        }
   }
   else if(colony_approbation == "No" || colony_approbation == "no" || colony_approbation == "n" || colony_approbation == "NO" || colony_approbation == "N")
        std::cout<<"Your wishes are our commands master, you will still be given the option of making it a colony when you are back in this system"<<std::endl;
        std::cout<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Type in the planet number you wish to visit "<<std::endl;
        std::cin>>choice;

    if(_fuelcapacity < 2*(distancesmap[planets_number - 1] - distancesmap[choice - 1])){
        std::cout<<"You have no fuel capacity to travel to this planet"<<std::endl;
        std::cout<<"Choose a closer planet, the last one will always be the closest"<<std::endl;
    }
    else{

        _fuelcapacity -= 2*(distancesmap[planets_number - 1] - distancesmap[choice -1]); //Two megatons per million of km will be consumed
        if(planets[choice -1].getplanettype()== 1){
            int selection;
            efficiency = std::pow(17 - _slaveslevel - 1, 17 -_slaveslevel) * (2*planets[choice-1].getmetal()); //This way when the level
            while(1){
                std::cout<<"<<<LAVA PLANET>>"<<std::endl;
                std::cout<<"1. Extract metal"<<std::endl;
                std::cout<<"2. Destroy planet"<<std::endl;
                std::cin>>selection;
                if(selection == 0)
                    break;
                else if(selection == 1){
                    int desired_amount;
                    genetical_modification(choice , planets_available, planetstemperatures);
                    std::cout<<std::endl;
                    std::cout<<std::endl;
                    while(1){
                        std::cout<<"Tell us the amount of metal that you want my lord"<<std::endl;
                        std::cin>>desired_amount;
                        if(desired_amount > planets[choice - 1].getmetal()){
                            std::cout<<"Try typing the amount again"<<std::endl;
                        }
                        else
                            break;
                    }
                    std::cout<<"Your wishes are our commands, my lord!"<<std::endl; //WAIT FUNCTION INCLUDED HERE
                    usleep(efficiency);
                    planets[choice - 1].setmetal(-desired_amount);
                    _metalamount += desired_amount;
                    std::cout<<"We have obtained "<<desired_amount<<" kg of metal my lord"<<std::endl;
                    break;
                }
                else if(selection == 2){
                    if(_antimatterweapon < 3000){
                        std::cout<<"Sorry my lord but we do not have enough antimatter to destroy this planet"<<std::endl;
                    }
                    else
                        planet_destroyer(desired_respect);
                        _antimatterweapon -= 3000;
                }
            }

        }


        else if(planets[choice -1].getplanettype() == 2){
            int selection;
            efficiency = std::pow(17 - _slaveslevel - 1, 17 -_slaveslevel) * (2*planets[choice-1].getmetal()); //This way when the level
            while(1){
                std::cout<<"<<DIAMOND PLANET>>"<<std::endl;
                std::cout<<"1. Extract diamonds"<<std::endl;
                std::cout<<"2. Destroy planet"<<std::endl;
                std::cin>>selection;
                if(selection == 1){
                    int desired_amount;
                    genetical_modification(choice, planets_available, planetstemperatures);
                    std::cout<<std::endl;
                    std::cout<<std::endl;
                    while(1){
                        std::cout<<"Please, tell us the amount of diamonds that you want my lord"<<std::endl;
                        std::cin>>desired_amount;
                        if(desired_amount > planets[choice - 1].getdiamonds()){
                            std::cout<<"There is not that many diamonds my lord"<<std::endl;
                        }
                        else
                            break;
                    }
                    std::cout<<"Your wishes are our commands, my lord"<<std::endl; //WAIT FUNCTION INCLUDED HERE
                    usleep(efficiency);
                    planets[choice - 1].setdiamonds(-desired_amount);
                    _diamondsamount += desired_amount;
                    std::cout<<"We have obtained "<<desired_amount<<" kg of diamonds to fill your archs my lord"<<std::endl;
                    break;
                }
                else if(selection == 0)
                    break;
                else if(selection == 2){
                    if(_antimatterweapon < 3000){
                        std::cout<<"Sorry my lord but we do not have enough antimatter to destroy this planet"<<std::endl;
                    }
                    else
                        planet_destroyer(desired_respect);
                        _antimatterweapon -= 3000;
                }
            }
        }

        else if(planets[choice - 1].getplanettype() == 3){
            int selection;
            efficiency = std::pow(17 - _slaveslevel - 1, 17 -_slaveslevel) * (2*planets[choice-1].getmetal()); //This way when the level
            while(1){
                std::cout<<"<<MERCURY PLANET>>"<<std::endl;
                std::cout<<"1. Extract mercury"<<std::endl;
                std::cout<<"2. Destroy planet"<<std::endl;
                std::cin>>selection;
                if(selection== 1){
                    int desired_amount;
                    genetical_modification(choice, planets_available, planetstemperatures);
                    std::cout<<std::endl;
                    std::cout<<std::endl;
                    while(1){
                        std::cout<<"Let us know how many megatons you want my lord"<<std::endl;
                        std::cin>>desired_amount;
                        if(desired_amount > planets[choice - 1].getmercury()){
                            std::cout<<"There is not that much mercury my lord"<<std::endl;
                        }
                        else
                            break;
                    }
                    std::cout<<"Your wishes are our commands my lord!"<<std::endl;//wAIT FUNCTION INCLUDED HERE
                    usleep(efficiency);
                    planets[choice - 1].setmercury(-desired_amount);
                    _fuelcapacity += desired_amount;
                    std::cout<<"We have obtained "<<desired_amount<<" megatons of fuel to propell our gigantic space ship my lord"<<std::endl;
                    break;
                }
                else if(selection == 0)
                    break;
                else if(selection == 2){
                    planet_destroyer(desired_respect);
                    _antimatterweapon -= 3000;
                }
            }
        }
        else if(planets[choice -1].getplanettype() == 4){
            int selection;
            efficiency = std::pow(17 - _slaveslevel - 1, 17 -_slaveslevel) * (2*planets[choice-1].getmetal()); //This way when the level is 17 the exponent will be zero!
            while(1){
                std::cout<<"<<HABITABLE OR POTENTIALLY HABITABLE PLANET>>"<<std::endl;
                std::cout<<"1. Interact with civilisation/make potentially habitable"<<std::endl;
                std::cout<<"2. Destroy planet"<<std::endl;
                std::cin>>selection;
                if(selection == 1){
                    int variableadjustment;
                    bool done = false;
                    std::string missingelement1;
                    std::string missingelement2;
                    std::string missingelement3;
                    int aliens = randRange(1000000, 7000000);
                    if(planets[choice - 1].gethabitability() == false){
                        if(planets[choice - 1].getbreathableatmosphere() == true){
                             while(1){
                                if(planets[choice -1].gethabitability() == true)
                                    break;
                                else{
                                    std::cout<<"My lord, we need to increase the magnetic field's intensity, adjust it using the magneto-weapon"<<std::endl;
                                    std::cout<<"The amount by which we must adjust it is "<<std::endl;
                                    std::cout<<planets[choice-1].getmagneticfieldvsradiation()<<std::endl;
                                    std::cin>>variableadjustment; //WAIT FUNCTION HERE
                                    planets[choice - 1].turn_into_habitable();
                                }

                            }

                            while(!done){
                                std::cout<<"My lord, we will need to accelerate the evolution process to get our specimens as soon as possible"<<std::endl;
                                std::cout<<"Use your powers to bring this doom planet to life!"<<std::endl;
                                std::cout<<"Press 1 to use the evolution express accelerator"<<std::endl;
                                std::cin>>variableadjustment;
                                if(_evolutionexpressaccelerator == 0){
                                    std::cout<<"Before your vindictive and glorious anger is inflicted upon our condemned miserable souls"<<std::endl;
                                    std::cout<<"I need to let you know that we are out of the evolutionexpressaccelerator"<<std::endl;
                                    std::cout<<"However it can still be processed in the laboratory"<<std::endl;
                                    //Wait function here
                                    while(1){
                                        bool protozoo = false;
                                        bool staphilloccocus = false;
                                        bool pseudomona = false;
                                        std::cout<<"<<--LABORATORY-->>"<<std::endl;
                                        std::cout<<std::endl;
                                        std::cout<<"Welcome to the laboratory my lord, we will process the evolutionexpressaccelerator combining the necessary bacteriae"<<std::endl;
                                        if(_protozoolevels == 0 && _staphilococcuslevels == 0 && _pseudomonalevels == 0){
                                            std::cout<<"My lord I am begging you to punish me with the most unimaginably horrible of tortures"<<std::endl;
                                            std::cout<<"Our bacteriae deposits are empty"<<std::endl;
                                            std::cout<<"It is time to go explore the universe in search for more"<<std::endl;
                                            done = true;
                                            break;
                                        }
                                        else if(_protozoolevels < 200 || _staphilococcuslevels < 100 || _pseudomonalevels < 50){
                                            int missing_element_calculation = _protozoolevels - 200;
                                            if(missing_element_calculation <= 0)
                                                    protozoo = true;
                                            missing_element_calculation = _staphilococcuslevels - 100;
                                            if(missing_element_calculation <= 0)
                                                    staphilloccocus = true;
                                            missing_element_calculation = _pseudomonalevels - 50;
                                            if(missing_element_calculation <= 0)
                                                    pseudomona = true;

                                            for(int i = 0; i < 3; i++){   //Checking the abscence of three elements involves too many if statements, this function makes it faster but not simpler unfortunately
                                                if(ORgate(protozoo, staphilloccocus, pseudomona)[i] > 0){
                                                    if(ORgate(protozoo, staphilloccocus, pseudomona)[i] == 1)
                                                        missingelement1 = "Protozoo";
                                                    else if(ORgate(protozoo, staphilloccocus, pseudomona)[i] == 2)
                                                        missingelement2 = "Staphilloccocus";
                                                    else if(ORgate(protozoo, staphilloccocus, pseudomona)[i] == 3)
                                                        missingelement3 = "Pseudomona";

                                                }
                                            }
                                            std::cout<<"We are out of "<<std::endl;
                                            std::cout<<missingelement1<<std::endl;
                                            std::cout<<missingelement2<<std::endl;
                                            std::cout<<missingelement3<<std::endl;
                                            std::cout<<"Slightly increasing the chimpancee's inteligence up to the ironically named homo-sapiens"<<std::endl;
                                            std::cout<<"will take longer than we thought..."<<std::endl;
                                            std::cout<<"Time to keep on exploring the universe!"<<std::endl;
                                            done = true;
                                            break;
                                        }
                                        else{
                                            usleep(efficiency);
                                            _protozoolevels -= rand()%200 + 1;
                                            _staphilococcuslevels -= rand()%100 + 1;
                                            _pseudomonalevels -= rand()%100 + 1;
                                            _evolutionexpressaccelerator += 1;
                                            std::cout<<"We just increased the amount of evolution express accelerator by one my lord"<<std::endl;
                                            std::cout<<"God save the lord!"<<std::endl;
                                            std::cout<<"Shall the ancient gods worship you my lord for no other than thee can defy their magnanimous and ubiquitus power"<<std::endl;
                                            _specimens += aliens;
                                            _evolutionexpressaccelerator -= 1;
                                            std::cout<<std::endl;
                                            std::cout<<"Our crew has been increased by "<<aliens<<" specimens"<<std::endl;
                                            done = true;
                                            break;


                                    }

                                }


                            }

                         }


                      }



                    }
                    else if(planets[choice -1].gethabitability() == true)
                        civilisation_interaction(desired_respect, aliens);
                        break;

                }
                else if(selection == 0)
                    break;

                else if(selection == 2){
                    if(_antimatterweapon < 3000){
                        std::cout<<"Sorry my lord but we do not have enough antimatter to destroy this planet"<<std::endl;
                    }
                    else
                        planet_destroyer(desired_respect);
                        _antimatterweapon -= 3000;
                }

            }
        }

        else if(planets[choice - 1].getplanettype() == 5){
            int selection;
            efficiency = std::pow(17 - _slaveslevel, 17 - _slaveslevel) *(planets[choice-1].getmetal());
            while(1){
               std::cout<<"<<FROZEN PLANET CONTAINING SIMPLE FORMS OF LIFE>>"<<std::endl;
                std::cout<<"1. Extract bacteria"<<std::endl;
                std::cout<<"2. Destroy planet"<<std::endl;
                std::cin>>selection;
                if(selection == 1){
                    int desired_amount_protozoo;
                    int desired_amount_staphillococcus;
                    int desired_amount_pseudomona;
                    while(1){
                        std::cout<<"Type in the amount of protozoo that you want my lord"<<std::endl;
                        std::cin>>desired_amount_protozoo;
                        if(desired_amount_protozoo > planets[choice -1].getprotozoo()){
                            std::cout<<"There is not so much protozoo my lord"<<std::endl;
                        }
                        else
                            break;
                    }
                    while(1){
                        std::cout<<"Tell us the amount of staphillococcus that you would like my lord"<<std::endl;
                        std::cin>>desired_amount_staphillococcus;
                        if(desired_amount_staphillococcus > planets[choice -1].getstaphilloccocus()){
                            std::cout<<"There is not so much staphillococcus my lord"<<std::endl;
                        }
                        else
                            break;

                    }
                    while(1){
                        std::cout<<"Tell us the amount of pseudomona that you desire my lord"<<std::endl;
                        std::cin>>desired_amount_pseudomona;
                        if(desired_amount_pseudomona > planets[choice -1].getpseudomona()){
                            std::cout<<"There is not so much pseudomona my lord"<<std::endl;
                        }
                        else
                            break;
                    }
                    usleep(efficiency);
                    planets[choice - 1].setbacteriae(-desired_amount_protozoo, -desired_amount_staphillococcus, -desired_amount_pseudomona);
                    _protozoolevels += desired_amount_protozoo;
                    _staphilococcuslevels += desired_amount_staphillococcus;
                    _pseudomonalevels += desired_amount_pseudomona;
                    std::cout<<"We have added "<<desired_amount_protozoo<<","<<desired_amount_staphillococcus<<" and "<<desired_amount_pseudomona<<std::endl;
                    std::cout<<"of protozoo, staphillococcus and pseudomona my lord!"<<std::endl;
                    break;
                }

            else if(selection == 0)
                break;

            else if(selection == 2){
                    if(_antimatterweapon < 3000){
                        std::cout<<"Sorry my lord but we do not have enough antimatter to destroy this planet"<<std::endl;
                    }
                    else
                        planet_destroyer(desired_respect);
                        _antimatterweapon -= 3000;
                }


            }
        }
        else if(planets[choice -1].getplanettype() == 6){
            int selection;
            efficiency = (17 - _slaveslevel) * (planets[choice-1].getmetal());
            while(1){
                std::cout<<"<<GAS GIANT>>"<<std::endl;
                std::cout<<"1. Extract WARP drive fuel"<<std::endl;
                std::cout<<"2. Destroy planet"<<std::endl;
                std::cin>>selection;
                if(selection == 1){
                    int desired_amount;
                    while(1){
                        std::cout<<"Please my lord, let us know how much gas you will need"<<std::endl;
                        std::cin>>desired_amount;
                        if(desired_amount > planets[choice -1].getgas()){
                            std::cout<<"We are sorry to tell you my lord that the planet does not contain that much gas"<<std::endl;
                        }
                        else
                            break;
                    }
                    planets[choice - 1].setgas(-desired_amount);
                    usleep(efficiency);
                    _WARPdrive += desired_amount;
                    std::cout<<"We have obtained "<<desired_amount<<" megatons of antimatter to fill our WARP drive deposits my lord!"<<std::endl;
                    break;
                }
                else if(selection = 0)
                    break;
                else if(selection == 2){
                    if(_antimatterweapon < 3000){
                        std::cout<<"Sorry my lord but we do not have enough antimatter to destroy this planet"<<std::endl;
                    }
                    else
                        planet_destroyer(desired_respect);
                        _antimatterweapon -= 3000;
                }



            }

        }
    }

}

void Spaceship::interstellar_travel( bool back_to_solar_system)
{
    int starschoice;
    int solarsystemchoice;
    while(1){
        if(_WARPdrive <= 1000){
            std::cout<<"My lord, we have no fuel left, it is time for us to face death like brothers!"<<std::endl;
            std::cout<<"I must confess it's always been a pleasure for us to serve you"<<std::endl;
            game_over();
            break;
            //The data base should be used here to display data from the user's colonies
            //and the current solar system where our character is
        }
        stars_interaction();
        _WARPdrive -= 1000;
        std::cin>>starschoice;
        if(_fuelcapacity == 0){
            std::cout<<"My lord, we have no fuel left, it is time for us to face death like brothers!"<<std::endl;
            std::cout<<"I must confess it's always been a pleasure for us to serve you"<<std::endl;
            game_over();
        }
        if(starschoice == 0)
            break;
        else if(_WARPdrive >= 1000)
        {
            _WARPdrive -= 250;
            planet_interaction(back_to_solar_system);
        }
        std::cout<<"1. Back to solar system"<<std::endl;
        std::cout<<"2. Back to cabin"<<std::endl;
        std::cin>>solarsystemchoice;
        if(solarsystemchoice == 1)
            back_to_solar_system = true; //DATABASE EXTRACTING DATA TO DISPLAY PLANETS ON THE SCREEN
        else if(solarsystemchoice ==2)
            break;


    }

}


void Spaceship::purchasepoints(int diamonds){
    if(diamonds == 0){
        std::cout<<"Your archs do not still have diamonds my lord, we will need to invade more planets!"<<std::endl;
        std::cout<<"Which we will do very gladly..."<<std::endl;
    }
    else if(diamonds > 0){
        _points = diamonds/100;
        _diamondsamount -= diamonds;
        std::cout<<_points<<std::endl;
        std::cout<<"This is your current amount of points my lord, make us more powerful to serve you!!"<<std::endl;
    }
}




void Spaceship::assign_points(int points, std::string specimen){
    if(points > _points){
        std::cout<<"We are sorry to tell you my lord that we still don't have so many points"<<std::endl;
        std::cout<<"We will neeed to conquer more regions of the universe"<<std::endl;
    }
    else{
        _points -= points;
        if(specimen == "Robo-slaves"){
            if(points % 2 == 0){
                _slavespoints += points/10;
            }
            else if(points % 2 != 0){
                points = points + 1;
                _slavespoints += points/10;
            }
        }
        else if(specimen == "Scientists"){
            if(points % 2 == 0){
                _scientistspoints += points/10;
            }
            else if(points % 2 != 0){
                points = points + 1;
                _scientistspoints += points/10;
            }

        }
        else if(specimen == "Cyborg soldiers"){
              if(points % 2 == 0){
                _soldierspoints += points/10;
            }
            else if(points % 2 != 0){
                points = points + 1;
                _soldierspoints += points/10;
            }
        }
    }
}


void Spaceship::setlevel(int currentlevel, std::string specimen, int increaseneeded, int levelsleft, int amount_desired, int choice, int factor, bool levelup,  std::vector<int> prices, std::vector<int> levels){
    while(1){

            std::cout<<"Type in your amount of points"<<std::endl;
            std::cin>>amount_desired;
            if(amount_desired == 0)
                break;

            else if(amount_desired > _points){
                std::cout<<"You don't have that many points yet, type your points again or press 0 to exit"<<std::endl;
                std::cout<<"You can purchase points from the main menu"<<std::endl;
            }
            else if(amount_desired == 0)
                break;
            else if(amount_desired <= _points){
                assign_points(amount_desired, specimen);
                if(specimen == "Cyborg soldiers"){
                    for(int i = _soldierslevel; i < prices.size(); i++){
                        if(prices[i] <= _soldierspoints){
                            levelup = true;
                            factor += 1;
                            _soldierslevel += factor;
                        }
                        else{
                            continue;
                        }
                    }
                    if(levelup){
                        std::cout<<"Your cyborg soldiers are stronger by a factor of "<<factor<<" my lord"<<std::endl;
                        std::cout<<"We feel grateful and will gladly sacrifice our lives for our intergalactic empire!"<<std::endl;
                        std::cout<<"This is your overall level"<<std::endl;
                        _overalllevel = (_soldierslevel + _scientistslevel + _slaveslevel)/3; //Compute overall level
                        std::cout<<_overalllevel<<std::endl;
                        _soldierspoints = 0;
                        break;
                    }
                    else if(!levelup){
                        std::cout<<"Thanks for making us stronger for you my lord, it is time to go to war!"<<std::endl;
                        break;
                    }
                }
                else if(specimen == "Scientists"){
                    for(int i = _scientistslevel; i < prices.size(); i++){
                        if(prices[i] <= _scientistspoints){
                            levelup = true;
                            factor += 1;
                            _scientistslevel +=factor;
                            break;
                        }
                        else
                            continue;
                    }
                    if(levelup){
                        std::cout<<"Your scientists have clearly outsmarted their previous generation, by a factor of "<<factor<<" my lord"<<std::endl;
                        std::cout<<"This is your overall level"<<std::endl;
                        _overalllevel = (_soldierslevel + _scientistslevel + _slaveslevel)/3;
                        std::cout<<_overalllevel<<std::endl; //Compute overall
                        _scientistspoints = 0;
                        break;
                    }
                    else if(!levelup){
                        std::cout<<"Your contribution to science will make this a better universe"<<std::endl;
                        std::cout<<"and enslave half of its population..."<<std::endl;
                        break;
                    }
                }
                 else if(specimen == "Robo-slaves"){
                    for(int i = _slaveslevel; i < prices.size(); i++){
                        if(prices[i] < _slavespoints){
                            levelup = true;
                            factor += 1;
                            _slaveslevel += factor;
                            break;
                        }
                        else
                            continue;
                    }
                    if(levelup){
                        std::cout<<"Your robo-slaves have been powered up by a factor of "<<factor<<" my lord"<<std::endl;
                        std::cout<<"Not very ethical but.. who said being practical implied being moral?"<<std::endl;
                        std::cout<<"This is your overall level"<<std::endl;
                        _overalllevel = (_soldierslevel + _scientistslevel + _slaveslevel)/3;
                        std::cout<<_overalllevel<<std::endl; //Compute overall
                        _slavespoints = 0;
                        break;
                    }
                    else if(!levelup){
                        std::cout<<"Your contribution to science will help us make this a better universe!"<<std::endl;
                        std::cout<<"and enslave more than a half of its population..."<<std::endl;
                        std::cout<<"I never believed in utopian regimes anyways"<<std::endl;
                        break;
                    }
                }

            }


       }

}


void Spaceship::laboratory(){
    std::string specimen;
    int choice;
    std::cout<<"<<LABORATORY>>"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"1. Cyborg army"<<std::endl;
    std::cout<<"2. Scientists"<<std::endl;
    std::cout<<"3. Robo-slaves"<<std::endl;
    std::cout<<"4. Exit"<<std::endl;
    std::cin>>choice;
    if(choice == 1){
        specimen = "Cyborg soldiers";
        while(1){
            std::cout<<"1. Power up your cyborg army"<<std::endl;
            std::cout<<"2. Exit"<<std::endl;
            std::cin>>choice;
            if(choice == 1){
                if(choice == 2)
                    break;
                else if(choice == 1){
                    std::cout<<"Current soldiers level: "<<_soldierslevel<<std::endl;
                    int increaseneeded;
                    int levelsleft;
                    int amount_desired;
                    int choice;
                    int factor = 0; //The i value that is used to iteratte through the list plus one, this way we get by how many levels the specimens have improved
                    bool levelup;
                    std::vector<int> prices = {0, 1, 16, 81, 256, 625, 1296, 2401, 4096, 6561, 10000, 14641, 20736, 28561, 38416, 50625};
                    std::vector<int> levels = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
                    levelsleft = levels.size() - _soldierslevel;  //this must change for every type
                    std::cout<<"You have "<<levelsleft<<" levels left to become master of the universe"<<std::endl;
                    std::cout<<"These are your points "<<_points<<std::endl;
                    for(int i = _soldierslevel; i < levels.size(); i++){
                        increaseneeded = std::pow(i, 4);
                        std::cout<<"Level: "<<levels[i]<<std::endl;
                        std::cout<<"Points needed "<< increaseneeded<<std::endl;
                    }
                    setlevel(_soldierslevel, specimen, increaseneeded, levelsleft, amount_desired, choice, factor, levelup, prices, levels);
                    break;
                }
            }
            else if(choice == 2)
                break;
        }
    }
    else if(choice == 2){
        specimen = "Scientists";
        while(1){
            std::cout<<"1. Make your scientists smarter"<<std::endl;
            std::cout<<"2. Exit"<<std::endl;
            std::cin>>choice;
            if(choice == 1){
                if(choice == 2)
                    break;
                else if(choice == 1){
                    std::cout<<"Current scientists level: "<<_scientistslevel<<std::endl;
                    int increaseneeded;
                    int levelsleft;
                    int amount_desired;
                    int choice;
                    int factor = 0;
                    bool levelup;
                    std::vector<int> prices = {0, 1, 16, 81, 256, 625, 1296, 2401, 4096, 6561, 10000, 14641, 20736, 28561, 38416, 50625};
                    std::vector<int> levels = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
                    levelsleft = levels.size() - _scientistslevel;  //this must change for every type
                    std::cout<<"You have "<<levelsleft<<" levels left to become master of the universe"<<std::endl;
                    std::cout<<"These are your points "<<_points<<std::endl;
                    for(int i = _scientistslevel; i < levels.size(); i++){
                        increaseneeded = std::pow(i, 4);
                        std::cout<<"Level: "<<levels[i]<<std::endl;
                        std::cout<<"Points needed "<< increaseneeded<<std::endl;
                    }
                    setlevel(_scientistslevel, specimen, increaseneeded, levelsleft, amount_desired, choice, factor, levelup, prices, levels);
                    break;
                }
            }
            else if(choice == 2)
                break;
        }

    }
    else if(choice == 3){
        specimen = "Robo slaves";
        while(1){
            std::cout<<"1. Make your slaves almost indefatigable"<<std::endl;
            std::cout<<"2. Exit"<<std::endl;
            std::cin>>choice;
            if(choice == 1){
                if(choice == 2)
                    break;
                else if(choice == 1){
                    std::cout<<"Current slaves level: "<<_slaveslevel<<std::endl;
                    int increaseneeded;
                    int levelsleft;
                    int amount_desired;
                    int choice;
                    int factor = 0; //The i value that is used to iteratte through the list plus one, this way we get by how many levels the specimens have improved
                    bool levelup;
                    std::vector<int> prices = {0, 1, 16, 81, 256, 625, 1296, 2401, 4096, 6561, 10000, 14641, 20736, 28561, 38416, 50625};
                    std::vector<int> levels = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
                    levelsleft = levels.size() - _slaveslevel;  //this must change for every type
                    std::cout<<"You have "<<levelsleft<<" levels left to become master of the universe"<<std::endl;
                    std::cout<<"These are your points "<<_points<<std::endl;
                    for(int i = _slaveslevel; i < levels.size(); i++){
                        increaseneeded = std::pow(i, 4);
                        std::cout<<"Level: "<<levels[i]<<std::endl;
                        std::cout<<"Points needed "<< increaseneeded<<std::endl;
                    }
                    setlevel(_slaveslevel, specimen, increaseneeded, levelsleft, amount_desired, choice, factor, levelup, prices, levels);
                    break;
                }
            }
            else if(choice == 2)
                break;
        }
    }

    else if(choice == 4)
        cabin();
}

void Spaceship::methalurgy(){
    int choice;
    while(1){
        std::cout<<"<--METHALLURGY LABORATORY-->"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Metal: "<<_metalamount<<std::endl;
        std::cout<<std::endl;
        std::cout<<"1. Drones factory"<<std::endl;
        std::cout<<"2. Cyborg's armors and weapons"<<std::endl;
        std::cout<<"3. Exit"<<std::endl;
        std::cin>>choice;
        switch(choice){

            case 1: std::cout<<"Tell us how many drones you want to create my lord!"<<std::endl;
                    std::cin>>choice;
                    if(_metalamount == 0){
                        std::cout<<"Lord! our metal reserves are fully empty we must extract minerals from a nearby planet"<<std::endl;
                        break;
                    }
                    else if(_metalamount < choice){
                        std::cout<<"Lord! you don't have that much metal yet"<<std::endl;
                        std::cout<<"Type in a smaller amount!"<<std::endl;
                    }
                    else if(choice == 0)
                        break;
                    else if(_metalamount > choice){
                        _metalamount -= choice * 17;
                        _drones += choice;
                        if(_specimens < _drones){
                            std::cout<<"Unfortunately my lord, you still don't have enough specimens to be armed with so many weapons"<<std::endl;
                        }
                        else if(_specimens >_drones){
                            _specimens -= _drones;
                            std::cout<<"Our drones will fly the enemy's sky and cause the greatest fear in its soul.."<<std::endl;
                            break;
                        }


                    }

            case 2: std::cout<<"How many armors and weapons?"<<std::endl;
                    std::cin>>choice;
                    if(_metalamount == 0){
                        std::cout<<"Lord! our metal reserves are fully empty we must extract minerals from a nearby planet"<<std::endl;
                        break;
                    }
                    else if(_metalamount < choice){
                        std::cout<<"Lord! you don't have that much metal yet"<<std::endl;
                        std::cout<<"Type in a smaller amount!"<<std::endl;
                    }
                    else if(choice == 0)
                        break;
                    else if(_metalamount > choice){
                        _metalamount -= choice * 25;
                        _armors += choice;
                        if(_specimens < _armors){
                            std::cout<<"Unfortunately my lord, you still don't have enough specimens to be armed with so many weapons"<<std::endl;

                        }
                        else if(_specimens < _armors){
                            _specimens -= _armors;
                            std::cout<<"Oh yes my lord, this new armors are worth dying for!"<<std::endl;
                            break;
                        }
                    }

            case 3: cabin();

        }
    }

}

void Spaceship::read_story(){
//Reads from a text-file the main story of the game
}

int Spaceship::cabin(){
    int choice;
    bool back_to_solar_system = false;
    while(1){
        std::cout<<std::endl;
        std::cout<<"<<<CABIN OF THE INTERSTELLAR FALCON IV WELCOME ON BOARD MY MASTER>>>"<<std::endl;
        std::cout<<"1. Interstellar travel"<<std::endl;
        std::cout<<"2. Access laboratory"<<std::endl;
        std::cout<<"3. Access deposits and WARP initialiser"<<std::endl;
        std::cout<<"4. Methallurgy"<<std::endl;
        std::cout<<"5. Purchase points!"<<std::endl; //Yeah, we need revenue for our business XDDD
        std::cout<<"6. Save game"<<std::endl;
        std::cout<<"7. Colonies"<<std::endl;
        std::cout<<"8. Read story"<<std::endl;
        std::cout<<"9. Exit"<<std::endl;
        std::cin>>choice;

        if(choice == 1){
            interstellar_travel(back_to_solar_system);
        }

        else if(choice == 2){
            laboratory();
        }
        else if(choice == 3){
            std::cout<<"<<DEPOSITS>>"<<std::endl;
            std::cout<<"Fuel tank capacity for interplanetary travel: "<<_fuelcapacity<<std::endl;
            std::cout<<"Antimatter deposit to power WARP drive and planet destroyer: "<<_WARPdrive<<std::endl;
        }
        else if(choice == 4){
            methalurgy();
        }
        else if(choice == 5){
            purchasepoints(_diamondsamount);
        }
        else if(choice == 6){
            save_game(); //DATABASE WITH ALL VARIABLES OF THE USER
        }
        else if(choice == 7){
            display_colonies(); //DATABASE TO DISPLAY COLONIES
        }
        else if(choice == 8){
            read_story();
        }
        else if(choice == 9){
            std::cout<<"Lord, the tripulants will get in hibernation mode"<<std::endl;
            std::cout<<"Always willing to serve you my master!"<<std::endl;
            return 0;
            }
    }
}



int main()
{
    Spaceship s;
    s.cabin();
}


