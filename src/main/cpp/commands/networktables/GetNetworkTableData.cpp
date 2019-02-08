GetNetworkTableData::GetNetworkTableData() {
    Requiers(&Robot::m_nt);
}

void GetNetworkTableData::Initialize() {}

void GetNetworkTableData::Execute() {
    this->xEntry = Robot::table->GetEntry("x0"); // x entry
    this->x = xEntry.GetDouble(0); // x value as double (returns 0 if finds nothing)
}

bool GetNetworkTableData::IsFinished() { return false; }

void GetNetworkTableData::End() {}

void GetNetworkTableData::Interrupted() {}
