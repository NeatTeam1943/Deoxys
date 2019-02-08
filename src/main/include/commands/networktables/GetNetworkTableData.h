#pragma once

#include <frc/commands/Command.h>
#include <iostream>

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance"

#include "../../include/commands/networktables/GetNetworkTableData.h"
#include "../Robot.h"

using namespace frc;
using namespace nt;
using namespace std;

class GetNetworkTableData : public frc::Command {
private:
    NetworkTableEntry xEntry;
    double x, y;

public:
    GetNetworkTableData();
    void Initialize() override;
    void Execute() override;
    void IsFinished() override;
    void End() override;
    void Interrupted() override;
}
