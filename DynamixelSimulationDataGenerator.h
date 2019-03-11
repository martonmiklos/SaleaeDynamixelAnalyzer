#ifndef DYNAMIXEL_SIMULATION_DATA_GENERATOR
#define DYNAMIXEL_SIMULATION_DATA_GENERATOR

#include <SimulationChannelDescriptor.h>
#include <string>
class DynamixelAnalyzerSettings;

class DynamixelSimulationDataGenerator
{
public:
	DynamixelSimulationDataGenerator();
	~DynamixelSimulationDataGenerator();

	void Initialize( U32 simulation_sample_rate, DynamixelAnalyzerSettings* settings );
	U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channel );

protected:
	DynamixelAnalyzerSettings* mSettings;
	U32 mSimulationSampleRateHz;

protected:
	void CreateSerialByte();
    U32 mStringIndex = 0;
    U8	 mPacketIndex = 0;

	SimulationChannelDescriptor mSerialSimulationData;

};
#endif //DYNAMIXEL_SIMULATION_DATA_GENERATOR
