#include <controller/xbox/xbox_controller.h>

XBoxController::XBoxController(){
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
    addAxis("A1",0,1);
    addAxis("A1",6,7);
    addAxis("A1",3,4);
    addAxis("A1",2,-1);
    addAxis("A1",5,-1);
}
