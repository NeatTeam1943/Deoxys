#pragma once

#include <frc/commands/Subsystem.h>

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
#include "../commands/GetNetworkTableData.h"

class NetworkTableSub : public frc::Subsystem {
private:
    NetworkTable* table;

public:
    static nt::NetworkTableEntry xEntry;
    static nt::NetworkTableType type;
    static double x, y;

    NetworkTableSub();
    void InitDefaultCommand() override;
};
