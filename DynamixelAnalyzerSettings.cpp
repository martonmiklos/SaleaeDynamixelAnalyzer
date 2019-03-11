#include "DynamixelAnalyzerSettings.h"
#include <AnalyzerHelpers.h>


DynamixelAnalyzerSettings::DynamixelAnalyzerSettings()
{
	mInputChannelInterface.reset( new AnalyzerSettingInterfaceChannel() );
	mInputChannelInterface->SetTitleAndTooltip( "Dynamixel", "Standard Dynamixel Protocol" );
	mInputChannelInterface->SetChannel( mInputChannel );

	mBitRateInterface.reset( new AnalyzerSettingInterfaceInteger() );
	mBitRateInterface->SetTitleAndTooltip( "Bit Rate (Bits/S)",  "Specify the bit rate in bits per second." );
	mBitRateInterface->SetMax( 6000000 );
	mBitRateInterface->SetMin( 1 );
	mBitRateInterface->SetInteger( mBitRate );

	mServoTypeInterface.reset(new AnalyzerSettingInterfaceNumberList());
	mServoTypeInterface->SetTitleAndTooltip("", "Type of Servos.");
	mServoTypeInterface->AddNumber(SERVO_TYPE_AX, "AX Servos (default)", "");
	mServoTypeInterface->AddNumber(SERVO_TYPE_MX, "MX Servos", "");
	mServoTypeInterface->SetNumber(mServoType);

	mShowWordsInterface.reset(new AnalyzerSettingInterfaceBool());
	mShowWordsInterface->SetTitleAndTooltip("", "Show two registers Low/High are shown as a word.");
	mShowWordsInterface->SetCheckBoxText("Show L/W values as words");
	mShowWordsInterface->SetValue(mShowWords);

    mInvertedInterface.reset( new AnalyzerSettingInterfaceNumberList() );
    mInvertedInterface->SetTitleAndTooltip( "", "Specify if the serial signal is inverted" );
    mInvertedInterface->AddNumber( false, "Non Inverted (Standard)", "" );
    mInvertedInterface->AddNumber( true, "Inverted", "" );
    mInvertedInterface->SetNumber( mInverted );

	AddInterface( mInputChannelInterface.get() );
	AddInterface( mBitRateInterface.get() );
	AddInterface( mServoTypeInterface.get() );
	AddInterface(mShowWordsInterface.get());
    AddInterface(mInvertedInterface.get());

	AddExportOption(0, "Export as csv file");
	AddExportExtension(0, "csv", "csv");

	ClearChannels();
	AddChannel( mInputChannel, "Dynamixel", false );
}

DynamixelAnalyzerSettings::~DynamixelAnalyzerSettings()
{
}

bool DynamixelAnalyzerSettings::SetSettingsFromInterfaces()
{
	mInputChannel = mInputChannelInterface->GetChannel();
	mBitRate = mBitRateInterface->GetInteger();
	mServoType = (U32)mServoTypeInterface->GetNumber();
	mShowWords = mShowWordsInterface->GetValue();
    //mInverted = bool( U32( mInvertedInterface->GetNumber() ) );

	ClearChannels();
	AddChannel( mInputChannel, "Dynamixel Protocol", true );

	return true;
}

void DynamixelAnalyzerSettings::UpdateInterfacesFromSettings()
{
	mInputChannelInterface->SetChannel( mInputChannel );
	mBitRateInterface->SetInteger( mBitRate );
	mServoTypeInterface->SetNumber( mServoType );
	mShowWordsInterface->SetValue(mShowWords);
    //mInvertedInterface->SetNumber( mInverted );

}

void DynamixelAnalyzerSettings::LoadSettings( const char* settings )
{
	SimpleArchive text_archive;
	text_archive.SetString( settings );

	text_archive >> mInputChannel;
	text_archive >> mBitRate;
	text_archive >> mServoType;
	text_archive >> mShowWords;
    text_archive >> mInverted;


	ClearChannels();
	AddChannel( mInputChannel, "Dynamixel Protocol", true );

	UpdateInterfacesFromSettings();
}

const char* DynamixelAnalyzerSettings::SaveSettings()
{
	SimpleArchive text_archive;

	text_archive << mInputChannel;
	text_archive << mBitRate;
	text_archive << mServoType;
	text_archive << mShowWords;
    text_archive << mInverted;

	return SetReturnString( text_archive.GetString() );
}
