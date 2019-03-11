#ifndef DYNAMIXEL_ANALYZER_SETTINGS
#define DYNAMIXEL_ANALYZER_SETTINGS

#include <AnalyzerSettings.h>
#include <AnalyzerTypes.h>

enum {SERVO_TYPE_AX, SERVO_TYPE_MX};
class DynamixelAnalyzerSettings : public AnalyzerSettings
{
public:
	DynamixelAnalyzerSettings();
	virtual ~DynamixelAnalyzerSettings();

	virtual bool SetSettingsFromInterfaces();
	void UpdateInterfacesFromSettings();
	virtual void LoadSettings( const char* settings );
	virtual const char* SaveSettings();

	
	Channel mInputChannel;
	U32 mBitRate;
	U32 mServoType;
	bool mShowWords;

protected:
    std::unique_ptr< AnalyzerSettingInterfaceChannel >	mInputChannelInterface;
    std::unique_ptr< AnalyzerSettingInterfaceInteger >	mBitRateInterface;
    std::unique_ptr< AnalyzerSettingInterfaceNumberList >	mServoTypeInterface;
    std::unique_ptr< AnalyzerSettingInterfaceBool >	    mShowWordsInterface;

};

#endif //DYNAMIXEL_ANALYZER_SETTINGS
