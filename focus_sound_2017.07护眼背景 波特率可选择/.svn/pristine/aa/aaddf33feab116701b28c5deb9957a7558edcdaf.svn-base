/*
Module : SERIALPORT.CPP
Purpose: Implementation for an EVC wrapper class for serial ports
Created: 01-08-2007
History: 

Copyright (c) 2007 by ZOLO.  
All rights reserved.
*/

/////////////////////////////////  Includes  //////////////////////////////////
#include "stdafx.h"
#include "serialport.h"

#define TIMEOUT 5000
////////// The actual serial port code

CSerialPort::CSerialPort()
{
	m_hComm = INVALID_HANDLE_VALUE;
}

CSerialPort::~CSerialPort()
{
	Close();
}


BOOL CSerialPort::Open(int nPort, DWORD dwBaud, Parity parity, BYTE DataBits, StopBits stopbits, FlowControl fc, BOOL bOverlapped)
{
  //Validate our parameters
	if ( nPort<=0 || nPort>255 )
		return FALSE;

  //Call CreateFile to open up the comms port
  CString sPort;
  sPort.Format(_T("\\\\.\\COM%d"), nPort);

  m_hComm = CreateFile(sPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

  if (m_hComm == INVALID_HANDLE_VALUE)
	return FALSE;

 
  //Get the current state prior to changing it
  DCB dcb;
  GetState(dcb);

  //Setup the baud rate
  dcb.BaudRate = dwBaud; 

  //Setup the Parity
  switch (parity)
  {
    case EvenParity:  dcb.Parity = EVENPARITY;  break;
    case MarkParity:  dcb.Parity = MARKPARITY;  break;
    case NoParity:    dcb.Parity = NOPARITY;    break;
    case OddParity:   dcb.Parity = ODDPARITY;   break;
    case SpaceParity: dcb.Parity = SPACEPARITY; break;
    default:          ASSERT(FALSE);            break;
  }

  //Setup the data bits
  dcb.ByteSize = DataBits;

  //Setup the stop bits
  switch (stopbits)
  {
    case OneStopBit:           dcb.StopBits = ONESTOPBIT;   break;
    case OnePointFiveStopBits: dcb.StopBits = ONE5STOPBITS; break;
    case TwoStopBits:          dcb.StopBits = TWOSTOPBITS;  break;
    default:                   ASSERT(FALSE);               break;
  }

  //Setup the flow control 
  dcb.fDsrSensitivity = FALSE;
  switch (fc)
  {
    case NoFlowControl:
    {
      dcb.fOutxCtsFlow = FALSE;
      dcb.fOutxDsrFlow = FALSE;
      dcb.fOutX = FALSE;
      dcb.fInX = FALSE;
      break;
    }
    case CtsRtsFlowControl:
    {
      dcb.fOutxCtsFlow = TRUE;
      dcb.fOutxDsrFlow = FALSE;
      dcb.fRtsControl = RTS_CONTROL_HANDSHAKE;
      dcb.fOutX = FALSE;
      dcb.fInX = FALSE;
      break;
    }
    case CtsDtrFlowControl:
    {
      dcb.fOutxCtsFlow = TRUE;
      dcb.fOutxDsrFlow = FALSE;
      dcb.fDtrControl = DTR_CONTROL_HANDSHAKE;
      dcb.fOutX = FALSE;
      dcb.fInX = FALSE;
      break;
    }
    case DsrRtsFlowControl:
    {
      dcb.fOutxCtsFlow = FALSE;
      dcb.fOutxDsrFlow = TRUE;
      dcb.fRtsControl = RTS_CONTROL_HANDSHAKE;
      dcb.fOutX = FALSE;
      dcb.fInX = FALSE;
      break;
    }
    case DsrDtrFlowControl:
    {
      dcb.fOutxCtsFlow = FALSE;
      dcb.fOutxDsrFlow = TRUE;
      dcb.fDtrControl = DTR_CONTROL_HANDSHAKE;
      dcb.fOutX = FALSE;
      dcb.fInX = FALSE;
      break;
    }
    case XonXoffFlowControl:
    {
      dcb.fOutxCtsFlow = FALSE;
      dcb.fOutxDsrFlow = FALSE;
      dcb.fOutX = TRUE;
      dcb.fInX = TRUE;
      dcb.XonChar = 0x11;
      dcb.XoffChar = 0x13;
      dcb.XoffLim = 100;
      dcb.XonLim = 100;
      break;
    }
    default:
    {
      ASSERT(FALSE);
      break;
    }
  }
  
  //Now that we have all the settings in place, make the changes
  SetState(dcb);

  SetMask(EV_RXCHAR);
  
  COMMTIMEOUTS CommTimeOuts;
  GetCommTimeouts( m_hComm, &CommTimeOuts );
  CommTimeOuts.ReadIntervalTimeout = TIMEOUT;
  CommTimeOuts.ReadTotalTimeoutMultiplier = TIMEOUT;
  CommTimeOuts.ReadTotalTimeoutConstant = TIMEOUT;
  SetCommTimeouts( m_hComm, &CommTimeOuts );
  return TRUE;
}

void CSerialPort::Close()
{
	if (IsOpen())
	{
		SetCommMask( m_hComm, 0 );
		PurgeComm( m_hComm, PURGE_RXCLEAR | PURGE_TXCLEAR );
		CloseHandle(m_hComm);
		m_hComm = INVALID_HANDLE_VALUE;
	}
}


DWORD CSerialPort::Read(void* lpBuf, DWORD dwCount)
{
  if (!IsOpen())
	  return 0;

  DWORD dwBytesRead = 0;
  if (!ReadFile(m_hComm, lpBuf, dwCount, &dwBytesRead, NULL))
	  return 0;
  
  return dwBytesRead;
}

DWORD CSerialPort::Write(const void* lpBuf, DWORD dwCount)
{
	if (!IsOpen())
	  return 0;

  DWORD dwBytesWritten = 0;
  if (!WriteFile(m_hComm, lpBuf, dwCount, &dwBytesWritten, NULL))
	  return 0;
  
  return dwBytesWritten;
}


void CSerialPort::GetStatus(COMSTAT& stat)
{
	if (!IsOpen())
	  return;

	DWORD dwErrors;
	ClearCommError(m_hComm, &dwErrors, &stat);
}

void CSerialPort::GetState(DCB& dcb)
{
	if (!IsOpen())
	  return;

	GetCommState(m_hComm, &dcb);
}

void CSerialPort::SetState(DCB& dcb)
{
	if (!IsOpen())
	  return;

	SetCommState(m_hComm, &dcb);
}

void CSerialPort::SetMask(DWORD dwMask)
{
	if (!IsOpen())
	  return;

	SetCommMask(m_hComm, dwMask);
}

void CSerialPort::GetMask(DWORD& dwMask)
{
	if (!IsOpen())
	  return;

	GetCommMask(m_hComm, &dwMask);
}

void CSerialPort::Flush()
{
	if (!IsOpen())
	  return;

	FlushFileBuffers(m_hComm);
}

void CSerialPort::Purge(DWORD dwFlags)
{
	if (!IsOpen())
	  return;

	PurgeComm(m_hComm, dwFlags);
}

void CSerialPort::ClearBuffer()
{
	Purge(PURGE_TXCLEAR|PURGE_RXCLEAR);
}

void CSerialPort::ClearWriteBuffer()
{
	Purge(PURGE_TXCLEAR);
}

void CSerialPort::ClearReadBuffer()
{
	Purge(PURGE_RXCLEAR);
}

void CSerialPort::Setup(DWORD dwInQueue, DWORD dwOutQueue)
{
	if (!IsOpen())
	  return;

	SetupComm(m_hComm, dwInQueue, dwOutQueue);
}
void CSerialPort::SetTimeouts( int timeouts )
{
	if (!IsOpen())
		return;
	
	COMMTIMEOUTS CommTimeOuts;
	GetCommTimeouts( m_hComm, &CommTimeOuts );
	CommTimeOuts.ReadIntervalTimeout = timeouts;
	CommTimeOuts.ReadTotalTimeoutMultiplier = timeouts;
	CommTimeOuts.ReadTotalTimeoutConstant = timeouts;
	SetCommTimeouts( m_hComm, &CommTimeOuts );
}
void CSerialPort::SetTimeouts(COMMTIMEOUTS& timeouts)
{
	if (!IsOpen())
	  return;

	SetCommTimeouts(m_hComm, &timeouts);
}

void CSerialPort::GetTimeouts(COMMTIMEOUTS& timeouts)
{
	if (!IsOpen())
	  return;

	GetCommTimeouts(m_hComm, &timeouts);
}

BOOL CSerialPort::WaitRxchar()
{
	if (!IsOpen())
	  return FALSE;

	DWORD dwMask;

	WaitCommEvent(m_hComm, &dwMask, NULL);
	SetCommMask (m_hComm, EV_RXCHAR); 

	COMSTAT cmState;
	GetStatus( cmState );

	DWORD dwRecv = cmState.cbInQue;

	if ( dwRecv > 0 )
		return TRUE;
	else
		return FALSE;
	

/*	//等待事件产生
	if (!WaitCommEvent(m_hComm, &dwMask, NULL))
		return FALSE;
	//判断是否为数据到达事件
	if ( !((dwMask & EV_RXCHAR) == EV_RXCHAR) )
		return FALSE;

	//得到接收到的字符数
	COMSTAT cmState;
	GetStatus( cmState );
	dwRecv = cmState.cbInQue;*/

	//return TRUE;
}
	
void CSerialPort::SetMarkMode()
{
	DCB dcb;
	GetState(dcb);
	dcb.Parity = CSerialPort::MarkParity;
	SetState(dcb);	
}

void CSerialPort::SetSpaceMode()
{
	DCB dcb;
	GetState(dcb);
	dcb.Parity = CSerialPort::SpaceParity;
	SetState(dcb);
}