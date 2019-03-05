/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Autonomous/Mount.h"

/*
    A set of commands, which handles the process of stepping on the stage.
*/

Mount::Mount()
{
    // Pull down the arms, until it hits the stage.
    AddSequential(new Lift(-0.5), 2);

    // Move forward, while pulling down.
    AddSequential(new Lift(-0.5), 2);
    AddParallel(new Drive(0.5, 0, false));

    // Open piston.
    //AddSequential(new Climb(), 2);
    AddSequential(new Drive(0.5, 0, false), 2);
    //AddSequential(new Climb(), 2);
    AddSequential(new Drive(0.5, 0, false), 2);
}