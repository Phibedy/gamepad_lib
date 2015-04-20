#include <controller/xbox/xbox_controller.h>
#include <iostream>
XBoxController::XBoxController(){
    //std::cout << "ENABLE XBOX_CONTROLLER!" <<std::endl;
    //add buttons
    addButton("A",0);
    addButton("B",1);
    addButton("X",2);
    addButton("Y",3);
    addButton("A1",9);
    addButton("A3",10);
    addButton("LB",4);
    addButton("RB",5);
    addButton("BACK",6);
    addButton("START",7);
    addButton("XBOX",8);

    //add axis
    addAxis("LS",0,1);
    addAxis("MX",6,7);
    addAxis("RS",3,4);
    addAxis("LT",2,-1);
    addAxis("RT",5,-1);
    //std::cout << "ADDED BUTTONS!!!!!!!!!!!!" <<std::endl;
}
