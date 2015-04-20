#ifndef GAMEPAD_TYPES_H
#define GAMEPAD_TYPES_H
#include <gamepad/gamepad.h>
void setAsXBoxController(Gamepad &pad){
    pad.addButton("A",0);
    pad.addButton("B",1);
    pad.addButton("X",2);
    pad.addButton("Y",3);
    pad.addButton("A1",9);
    pad.addButton("A3",10);
    pad.addButton("LB",4);
    pad.addButton("RB",5);
    pad.addButton("BACK",6);
    pad.addButton("START",7);
    pad.addButton("XBOX",8);

    //add axis
    pad.addAxis("LS",0,1);
    pad.addAxis("MX",6,7);
    pad.addAxis("RS",3,4);
    pad.addAxis("LT",2,-1);
    pad.addAxis("RT",5,-1);
}
#endif
