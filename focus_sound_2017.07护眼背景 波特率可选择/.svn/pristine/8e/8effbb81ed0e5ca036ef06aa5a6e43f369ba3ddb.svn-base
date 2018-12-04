/*
Module : SERIALPORT.H
Purpose: Declaration for an MFC wrapper class for serial ports
Created: PJN / 31-05-1999
History: None

Copyright (c) 1999 by PJ Naughter.  
All rights reserved.

*/



///////////////////// Macros / Structs etc //////////////////////////

#ifndef __SERIALPORT_H__
#define __SERIALPORT_H__

#include "StdAfx.h"

//// The actual serial port class /////////////////////////////////////////////

class CSerialPort
{
public:
//Enums
  enum FlowControl
  {
    NoFlowControl,
    CtsRtsFlowControl,
    CtsDtrFlowControl,
    DsrRtsFlowControl,
    DsrDtrFlowControl,
    XonXoffFlowControl
  };

  enum Parity
  {    
	NoParity,
    OddParity,
    EvenParity,
    MarkParity,
    SpaceParity
  };

  enum StopBits
  {
    OneStopBit,
    OnePointFiveStopBits,
    TwoStopBits
  };

//Constructors / Destructors
  CSerialPort();
  ~CSerialPort();

//General Methods
  BOOL Open(int nPort, DWORD dwBaud = 9600, Parity parity = NoParity, BYTE DataBits = 8, 
            StopBits stopbits = OneStopBit, FlowControl fc = NoFlowControl, BOOL bOverlapped = FALSE);

  void Close();

  BOOL IsOpen() const { return m_hComm != INVALID_HANDLE_VALUE; };

//Reading / Writing Methods
  DWORD Read(void* lpBuf, DWORD dwCount);
  DWORD Write(const void* lpBuf, DWORD dwCount);

//parity mode
  void SetMarkMode();
  void SetSpaceMode();

//Misc RS232 Methods
  void GetStatus(COMSTAT& stat);
  void GetState(DCB& dcb);
  void SetState(DCB& dcb);

//Timeouts
  void SetTimeouts(COMMTIMEOUTS& timeouts);
  void GetTimeouts(COMMTIMEOUTS& timeouts);
  void SetTimeouts( int timeouts );

//Event Methods
  void SetMask(DWORD dwMask);
  void GetMask(DWORD& dwMask);
  BOOL WaitRxchar();
  
//Queue Methods
  void Flush();
  void Purge(DWORD dwFlags);
  void ClearWriteBuffer();
  void ClearReadBuffer();
  void ClearBuffer();
  void Setup(DWORD dwInQueue, DWORD dwOutQueue);

public:
  HANDLE m_hComm;       //Handle to the comms port

};


#endif //__SERIALPORT_H__