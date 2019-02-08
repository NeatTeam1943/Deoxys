#include "../../include/subsystems/NetworkTableSub.h"

NetworkTableSub::NetworkTableSub() : Subsystem("ExampleSubsystem") {}

void NetworkTableSub::InitDefaultCommand() {
    setDefaultCommand(new GetNetworkTableData());
}
