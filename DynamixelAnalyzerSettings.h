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

	
    Channel mInputChannel = UNDEFINED_CHANNEL;
    U32 mBitRate = 57600;
    U32 mServoType = SERVO_TYPE_AX;
    bool mShowWords = false;
    bool mInverted = false;

protected:
    std::unique_ptr< AnalyzerSettingInterfaceChannel >	mInputChannelInterface;
    std::unique_ptr< AnalyzerSettingInterfaceInteger >	mBitRateInterface;
    std::unique_ptr< AnalyzerSettingInterfaceNumberList >	mServoTypeInterface;
    std::unique_ptr< AnalyzerSettingInterfaceBool >	    mShowWordsInterface;
    std::unique_ptr< AnalyzerSettingInterfaceNumberList >	mInvertedInterface;
};

#endif //DYNAMIXEL_ANALYZER_SETTINGS
