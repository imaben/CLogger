#include "stdafx.h"
#include "Logger.h"

static char *szLogDesc[] = {
	"DEBUG",
	"INFO",
	"WARN",
	"ERROR"
};

#define WRITE_LOG(level, fmt) do { \
	CString strTemp; \
	va_list args; \
	va_start(args, fmt); \
	strTemp.FormatV(fmt, args); \
	WriteLog(FormatLog(level, strTemp)); \
} while (0);

CLogger::CLogger()
{
#ifdef _DEBUG
	m_nLogLevel = LOG_LEVEL_DEBUG;
#else
	m_nLogLevel = LOG_LEVEL_INFO;
#endif
}


CLogger::~CLogger()
{
}

CString CLogger::FormatTime(int nTime)
{
	CString strTime;
	if (nTime < 10)
	{
		strTime.Format("0%d", nTime);
	}
	else
	{
		strTime.Format("%d", nTime);
	}
	return strTime;
}

CString CLogger::FormatLog(enum LogLevel eLevel, CString strLog)
{
	CTime t = CTime::GetCurrentTime();
	CString strPrint;
	strPrint.Format("[%s-%s-%s %s:%s:%s] [%s] %s",
		FormatTime(t.GetYear()),
		FormatTime(t.GetMonth()),
		FormatTime(t.GetDay()),
		FormatTime(t.GetHour()),
		FormatTime(t.GetMinute()),
		FormatTime(t.GetSecond()),
		szLogDesc[eLevel],
		strLog
	);
	return strPrint;
}

void CLogger::Debug(LPCTSTR pstrFormat, ...)
{
	if (m_nLogLevel <= LOG_LEVEL_DEBUG)
	{
		WRITE_LOG(LOG_LEVEL_DEBUG, pstrFormat);
	}
}

void CLogger::Info(LPCTSTR pstrFormat, ...)
{
	if (m_nLogLevel <= LOG_LEVEL_INFO)
	{
		WRITE_LOG(LOG_LEVEL_INFO, pstrFormat);
	}
}

void CLogger::Warn(LPCTSTR pstrFormat, ...)
{
	if (m_nLogLevel <= LOG_LEVEL_WARN)
	{
		WRITE_LOG(LOG_LEVEL_WARN, pstrFormat);
	}
}

void CLogger::Error(LPCTSTR pstrFormat, ...)
{
	if (m_nLogLevel <= LOG_LEVEL_ERROR)
	{
		WRITE_LOG(LOG_LEVEL_ERROR, pstrFormat);
	}
}